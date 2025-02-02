const net = require("node:net");

let sid = 1;
const connectedClients = [];

const server = net.createServer();

server.on("connection", (socket) => {
  console.log("Client has connected");
  connectedClients.push({ ...socket, sid });

  socket.on("data", (chunk) => {
    console.log(`Recieved: ${chunk}`);
  });

  socket.on("end", () => {
    console.log("Clinet has disconected");
  });

  socket.on("error", (error) => {
    console.log(error);
  });

  sid++;
});

server.on("error", (error) => {
  console.log(error);
});

server.listen(55555, "127.0.0.1", () => {
  console.log("server is lisning on port 9000");
});

