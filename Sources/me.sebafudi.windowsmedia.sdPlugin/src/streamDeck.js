const ws = require("ws");

var websocket = null,
  uuid = null,
  actionInfo = {};
connectElgatoStreamDeckSocket(
  getPort(),
  getUuid(),
  getRegisterEvent(),
  getInfo(),
  "{}"
);
function connectElgatoStreamDeckSocket(
  inPort,
  inUUID,
  inRegisterEvent,
  inInfo,
  inActionInfo
) {
  actionInfo = JSON.parse(inActionInfo);
  websocket = new ws("ws://127.0.0.1:" + inPort);
  websocket.onopen = function () {
    x = 10;
    var json = {
      event: inRegisterEvent,
      uuid: inUUID,
    };
    websocket.send(JSON.stringify(json));
    websocket.on("message", (data) => {
      x = data;
    });
  };
}

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

function getInfo() {
  const args = process.argv;
  const indexOfInfo = process.argv.indexOf("-info");
  if (indexOfInfo == -1 || !indexOfInfo) {
    throw new Error("No info found!");
  }
  return args[indexOfInfo + 1];
}
