const net = require("node:net");
const readline = require("node:readline/promises");
const { stdin: input, stdout: output } = require("node:process");

const rl = readline.createInterface({ input, output });

const client = net.createConnection({
  host: "127.0.0.1",
  port: 55555,
});

client.on("connect", async () => {
  console.log("connected");

  // { type: message | username_signed }
  client.on("data", (chunk) => {
    const recivedData = JSON(chunk.toString());
    switch (recivedData.type) {
      case "username_signed":
        client.username = recivedData.username;
        break;
      case "message":
        // rl.clearLine(0);
        console.log(recivedData.message);
        break;
    }
  });

  while (1) {
    const answer = await rl.question(`${client.username} > `);
    client.write(answer);
  }
});

client.on("error", (error) => {
  console.log(error);
});

