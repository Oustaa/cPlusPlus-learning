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

  while (1) {
    const answer = await rl.question("What do you think of Node.js? ");
    client.write(answer);
  }
});

client.on("error", (error) => {
  console.log(error);
});

