const mediaControl = require("windows.media.control");

const MediaManager =
  mediaControl.GlobalSystemMediaTransportControlsSessionManager;

const app = {
  currentSession: null,
  currentPlaybackInfo: null,
  listApps: function () {
    return new Promise((resolve, reject) => {
      MediaManager.requestAsync((error, result) => {
        if (error) reject(error);
        let sessions = [];
        for (let i = 0; i < result.getSessions().size; i++) {
          sessions.push(result.getSessions()[i].sourceAppUserModelId);
        }
        resolve(sessions);
      });
    });
  },
  getMediaProperties: function (appId) {
    return new Promise((resolve, reject) => {
      MediaManager.requestAsync((error, result) => {
        if (error) reject(error);
        for (let i = 0; i < result.getSessions().size; i++) {
          this.currentSession = result.getSessions()[i];
          if (this.currentSession.sourceAppUserModelId === appId) {
            this.currentSession.tryGetMediaPropertiesAsync((error, result) => {
              resolve({
                albumArtist: result.albumArtist,
                albumTitle: result.albumTitle,
                albumTrackCount: result.albumTrackCount,
                artist: result.artist,
                genres: result.genres,
                playbackType: result.playbackType,
                subtitle: result.subtitle,
                // thumbnail: result.thumbnail,
                title: result.title,
                trackNumber: result.trackNumber,
              });
            });
            break;
          }
        }
      });
    });
  },
  getPlaybackInfo: function (appId) {
    return new Promise((resolve, reject) => {
      MediaManager.requestAsync((error, result) => {
        if (error) reject(error);
        for (let i = 0; i < result.getSessions().size; i++) {
          this.currentSession = result.getSessions()[i];
          if (this.currentSession.sourceAppUserModelId === appId) {
            this.currentPlaybackInfo = this.currentSession.getPlaybackInfo();
            resolve({
              autoRepeatMode: this.currentPlaybackInfo.autoRepeatMode,
              controls: this.currentPlaybackInfo.controls,
              isShuffleActive: this.currentPlaybackInfo.isShuffleActive,
              playbackRate: this.currentPlaybackInfo.playbackRate,
              playbackStatus: this.currentPlaybackInfo.playbackStatus,
              playbackType: this.currentPlaybackInfo.playbackType,
            });
            break;
          }
        }
      });
    });
  },
  onPlaybackInfoChange: function (callback) {
    this.currentSession.on("PlaybackInfoChanged", () => {
      this.getPlaybackInfo(this.currentSession.sourceAppUserModelId).then(
        (data) => {
          callback(data);
        }
      );
    });
  },
  onMediaPropertiesChange: function (callback) {
    this.currentSession.on("MediaPropertiesChanged", () => {
      this.getMediaProperties(this.currentSession.sourceAppUserModelId).then(
        (data) => {
          callback(data);
        }
      );
    });
  },
};

module.exports = app;
