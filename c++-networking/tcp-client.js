const net = require("node:net");
const readline = require("node:readline/promises");
const { stdin: input, stdout: output } = require("node:process");

const rl = readline.createInterface({ input, output });

const client = net.createConnection({
  host: "127.0.0.1",
  port: 55555,
});

client.on("connect", async () => {
  client.on("data", (chunk) => {
    const recivedData = JSON.parse(chunk.toString());

    switch (recivedData.type) {
      case "username_signed":
        client.username = recivedData.username;
        break;
      case "message":
        // Clear the input prompt
        process.stdout.moveCursor(0, -1);
        process.stdout.clearLine(-1);

        // Print the received message
        console.log(recivedData.message);

        // Reprint the prompt
        process.stdout.write(`me > `);
        break;
    }
  });

  while (true) {
    const answer = await rl.question(`me > `);
    client.write(answer);
  }
});

client.on("error", (error) => {
  console.log(error);
});

