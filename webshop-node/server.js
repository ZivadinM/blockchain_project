const http = require("http");
const app = require("./App");

const server = http.createServer(app);
server.listen(3000, "localhost");
//127.0.0.1 prezentuje lokal host
console.log("server started...");
