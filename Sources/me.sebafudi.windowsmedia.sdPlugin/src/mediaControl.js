const mediaControl = require("windows.media.control");

const MediaManager =
  mediaControl.GlobalSystemMediaTransportControlsSessionManager;

const app = {
  listApps: () => {
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
  getInfo: (appId) => {
    return new Promise((resolve, reject) => {
      MediaManager.requestAsync((error, result) => {
        if (error) reject(error);
        let sessions = [];
        for (let i = 0; i < result.getSessions().size; i++) {
          let currentSession = result.getSessions()[i];
          if (currentSession.sourceAppUserModelId === appId) {
            currentSession.tryGetMediaPropertiesAsync((error, result) => {
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
};

module.exports = app;

// MediaManager.requestAsync((error, result) => {
//   let currentSession = result.getCurrentSession();
//   if (!currentSession) {
//     return;
//   }
//   currentSession.on("PlaybackInfoChanged", getInfo);
//   currentSession.on("MediaPropertiesChanged", getInfo);
//   getInfo();
//   function getInfo() {
//     const TARGET_ID = currentSession.sourceAppUserModelId;
//     if (currentSession.sourceAppUserModelId == TARGET_ID) {
//       console.log(currentSession.getTimelineProperties().minSeekTime);
//       console.log(currentSession.getTimelineProperties().position);
//       console.log(currentSession.getTimelineProperties().maxSeekTime);
//       currentSession.tryGetMediaPropertiesAsync((error, info) => {
//         console.log(info.title + " by " + info.artist);
//         currentSong = info;
//       });
//     }
//   }
// });
