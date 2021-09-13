const http = require("http");
const mediaControl = require("./mediaControl");
// const streamDeck = require("./streamDeck");

mediaControl.listApps().then((data) => {
  console.log(data);
});

mediaControl.getInfo("Spotify.exe").then((data) => {
  console.log(data.title + " by " + data.artist);
});

// const requestListener = function (req, res) {
//   res.writeHead(200);
//   res.end(currentSong.title + " by " + currentSong.artist);
// };

// const server = http.createServer(requestListener);
// server.listen(8888);
