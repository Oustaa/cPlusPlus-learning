const http = require("node:http");

const server = http.createServer();

server.on("request", (req, res) => {
  console.log(req.url);

  switch (req.url) {
    case "/":
      return res.end("Hello, World!");
    case "/ousta":
      return res.end("<h1>ousta is him</h1>");
    default:
      res.write("<h1 style='color:red;'>Page not found!</h1>");
      res.end();
  }
});

server.listen(9090, () => {
  console.log("Server start listeninig on port 9090");
});

