const mediaControl = require("./mediaControl");
// const streamDeck = require("./streamDeck");

// streamDeck.initialize();

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
  setTimeout(wait, 100);
})();
