const mediaControl = require('windows.media.control')

// import mediaControl from 'windows.media.control'

const MediaManager = mediaControl.GlobalSystemMediaTransportControlsSessionManager

// MediaManager.on('mediaPropertiesChanged', ()=> {
//   console.log("aa")
// })
let currentSession;
// x.on('statusChanged', handler)
MediaManager.requestAsync((error, result) => {
  currentSession = result.getCurrentSession()
  if (!currentSession) {
    return;
  }
  currentSession.on('PlaybackInfoChanged', getInfo)
  function getInfo() {
    const TARGET_ID = currentSession.sourceAppUserModelId
    if (currentSession.sourceAppUserModelId == TARGET_ID){
  
      console.log(currentSession.getTimelineProperties().minSeekTime)
      console.log(currentSession.getTimelineProperties().position)
      console.log(currentSession.getTimelineProperties().maxSeekTime)
      let info = currentSession.tryGetMediaPropertiesAsync((error, info) => {
        console.log(info.title + ' by ' + info.artist)
      })
      // # song_attr[0] != '_' ignores system attributes
      // info_dict = {song_attr: info.__getattribute__(song_attr) for song_attr in dir(info) if song_attr[0] != '_'}
  
      // # converts winrt vector to list
      // info_dict['genres'] = list(info_dict['genres'])
  
      // return info_dict
    }

  }
})
const http = require('http');

const requestListener = function (req, res) {
  res.writeHead(200);
  res.end('Hello, World!');
}

const server = http.createServer(requestListener);
server.listen(8080);