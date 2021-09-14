const mediaControl = require("./mediaControl");
const streamDeck = require("./streamDeck");

streamDeck.initialize().then(() => {
  // console.log("asdf");
  // console.log(streamDeck.websocket.on);
  streamDeck.websocket.on("message", async (data) => {
    data = await JSON.parse(data);
    console.log("asdf");
    if (data.event === "keyDown") {
      mediaControl.getPlaybackInfo("Spotify.exe").then((data) => {
        if (data.playbackStatus === 4) {
          mediaControl.tryPausePlayback();
        } else {
          mediaControl.tryPlayPlayback();
        }
      });
    }
  });
});

mediaControl.getMediaProperties("Spotify.exe").then((data) => {
  console.log(data);
  mediaControl.onPlaybackInfoChange((data) => {
    console.log(data.playbackStatus === 4 ? "playing" : "paused");
  });
  mediaControl.onMediaPropertiesChange((data) => {
    console.log(data.title + " by " + data.artist);
  });
});

(function wait() {
  setTimeout(wait, 1000);
})();
