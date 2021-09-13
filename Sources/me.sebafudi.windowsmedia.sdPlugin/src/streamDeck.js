const ws = require("ws");

const app = {
  websocket: null,
  uuid: null,
  actionInfo: {},
  initialize: function () {
    this.uuid = this.getFromArgs("pluginUUID");
    this.connectElgatoStreamDeckSocket(
      this.getFromArgs("port"),
      this.getFromArgs("pluginUUID"),
      this.getFromArgs("registerEvent"),
      this.getFromArgs("info"),
      "{}"
    );
  },
  connectElgatoStreamDeckSocket: function (
    inPort,
    inUUID,
    inRegisterEvent,
    inInfo,
    inActionInfo
  ) {
    this.actionInfo = JSON.parse(inActionInfo);
    this.websocket = new ws("ws://127.0.0.1:" + inPort);
    this.websocket.onopen = function () {
      var json = {
        event: inRegisterEvent,
        uuid: inUUID,
      };
      this.websocket.send(JSON.stringify(json));
      this.websocket.on("message", () => {});
    };
  },
  sendValueToPlugin: function (value, param) {
    if (this.websocket) {
      const json = {
        action: this.actionInfo["action"],
        event: "sendToPlugin",
        context: this.uuid,
        payload: {
          [param]: value,
        },
      };
      this.websocket.send(JSON.stringify(json));
    }
  },
  getFromArgs: function (name) {
    const args = process.argv;
    const indexOfArg = process.argv.indexOf(`-${name}`);
    if (indexOfArg == -1 || !indexOfArg) {
      throw new Error(`No -${name} found!`);
    }
    return args[indexOfArg + 1];
  },
};

module.exports = app;
