const mediaControl = require("windows.media.control");
const ws = require("ws");
// import mediaControl from 'windows.media.control'

// this is our global websocket, used to communicate from/to Stream Deck software
// and some info about our plugin, as sent by Stream Deck software
var websocket = null,
  uuid = null,
  actionInfo = {};
connectElgatoStreamDeckSocket();
function connectElgatoStreamDeckSocket(
  inPort,
  inUUID,
  inRegisterEvent,
  inInfo,
  inActionInfo
) {
  inPort = getPort();
  inUUID = getUuid();
  inRegisterEvent = getRegisterEvent();
  inActionInfo = "{}";
  // please note: the incoming arguments are of type STRING, so
  // in case of the inActionInfo, we must parse it into JSON first
  actionInfo = JSON.parse(inActionInfo); // cache the info
  websocket = new ws("ws://127.0.0.1:" + inPort);

  // if connection was established, the websocket sends
  // an 'onopen' event, where we need to register our PI
  websocket.onopen = function () {
    x = 10;
    var json = {
      event: inRegisterEvent,
      uuid: inUUID,
    };
    // register property inspector to Stream Deck
    websocket.send(JSON.stringify(json));
    websocket.on("message", (data) => {
      x = data;
    });
  };
}

// our method to pass values to the plugin
function sendValueToPlugin(value, param) {
  if (websocket) {
    const json = {
      action: actionInfo["action"],
      event: "sendToPlugin",
      context: uuid,
      payload: {
        [param]: value,
      },
    };
    websocket.send(JSON.stringify(json));
  }
}
let currentSong;
let x = 5;

function getPort() {
  const args = process.argv;
  const indexOfPort = process.argv.indexOf("-port");
  if (indexOfPort == -1 || !indexOfPort) {
    throw new Error("No port found!");
  }
  return args[indexOfPort + 1];
}
function getUuid() {
  const args = process.argv;
  const indexOfUuid = process.argv.indexOf("-pluginUUID");
  if (indexOfUuid == -1 || !indexOfUuid) {
    throw new Error("No uuid found!");
  }
  return args[indexOfUuid + 1];
}
function getRegisterEvent() {
  const args = process.argv;
  const indexOfRegisterEvent = process.argv.indexOf("-registerEvent");
  if (indexOfRegisterEvent == -1 || !indexOfRegisterEvent) {
    throw new Error("No registerEvent found!");
  }
  return args[indexOfRegisterEvent + 1];
}

const MediaManager =
  mediaControl.GlobalSystemMediaTransportControlsSessionManager;

// MediaManager.on('mediaPropertiesChanged', ()=> {
//   console.log("aa")
// })
let currentSession;
// x.on('statusChanged', handler)
MediaManager.requestAsync((error, result) => {
  currentSession = result.getCurrentSession();
  if (!currentSession) {
    return;
  }
  currentSession.on("PlaybackInfoChanged", getInfo);
  currentSession.on("MediaPropertiesChanged", getInfo);
  getInfo();
  function getInfo() {
    const TARGET_ID = currentSession.sourceAppUserModelId;
    if (currentSession.sourceAppUserModelId == TARGET_ID) {
      console.log(currentSession.getTimelineProperties().minSeekTime);
      console.log(currentSession.getTimelineProperties().position);
      console.log(currentSession.getTimelineProperties().maxSeekTime);
      let info = currentSession.tryGetMediaPropertiesAsync((error, info) => {
        console.log(info.title + " by " + info.artist);
        currentSong = info;
      });
      // # song_attr[0] != '_' ignores system attributes
      // info_dict = {song_attr: info.__getattribute__(song_attr) for song_attr in dir(info) if song_attr[0] != '_'}

      // # converts winrt vector to list
      // info_dict['genres'] = list(info_dict['genres'])

      // return info_dict
    }
  }
});
const http = require("http");

const requestListener = function (req, res) {
  res.writeHead(200);
  res.end(currentSong.title + " by " + currentSong.artist + " " + x);
};

const server = http.createServer(requestListener);
server.listen(8888);
