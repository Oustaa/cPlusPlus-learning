const net = require("node:net");
const { faker } = require("@faker-js/faker");

let sid = 1;
const connectedClients = [];

const server = net.createServer();

server.on("connection", (socket) => {
  const username = faker.internet.username();
  socket.sid = sid;
  socket.username = username;
  // console.log("Client has connected %d", socket.sid);

  connectedClients.push(socket);

  socket.write(JSON.stringify({ type: "username_signed", username }));

  socket.on("data", (chunk) => {
    connectedClients.forEach((skt) => {
      console.log({
        "skt.username": skt.username,
        "socket.username": socket.username,
      });
      if (skt.username !== socket.username) {
        skt.write(
          JSON.stringify({
            message: `${socket.username}> ${chunk}`,
            type: "message",
          })
        );
      }
    });
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
  // console.log("server is lisning on port 9000");
});

