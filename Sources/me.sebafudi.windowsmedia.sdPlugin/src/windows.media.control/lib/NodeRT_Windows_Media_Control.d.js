_GlobalSystemMediaTransportControlsSessionPlaybackStatus = function () {
  this.closed = 0;
  this.opened = 1;
  this.changing = 2;
  this.stopped = 3;
  this.playing = 4;
  this.paused = 5;
}
exports.GlobalSystemMediaTransportControlsSessionPlaybackStatus = new _GlobalSystemMediaTransportControlsSessionPlaybackStatus();

CurrentSessionChangedEventArgs = (function () {
  var cls = function CurrentSessionChangedEventArgs() {
  };
  

  return cls;
}) ();
exports.CurrentSessionChangedEventArgs = CurrentSessionChangedEventArgs;

GlobalSystemMediaTransportControlsSession = (function () {
  var cls = function GlobalSystemMediaTransportControlsSession() {
    this.sourceAppUserModelId = new String();
  };
  

  cls.prototype.tryGetMediaPropertiesAsync = function tryGetMediaPropertiesAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryPlayAsync = function tryPlayAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryPauseAsync = function tryPauseAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryStopAsync = function tryStopAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryRecordAsync = function tryRecordAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryFastForwardAsync = function tryFastForwardAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryRewindAsync = function tryRewindAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.trySkipNextAsync = function trySkipNextAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.trySkipPreviousAsync = function trySkipPreviousAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryChangeChannelUpAsync = function tryChangeChannelUpAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryChangeChannelDownAsync = function tryChangeChannelDownAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryTogglePlayPauseAsync = function tryTogglePlayPauseAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }


  cls.prototype.tryChangeAutoRepeatModeAsync = function tryChangeAutoRepeatModeAsync(requestedAutoRepeatMode, callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <param name="requestedAutoRepeatMode" type="Number">A param.</param>
    /// </signature>
  }


  cls.prototype.tryChangePlaybackRateAsync = function tryChangePlaybackRateAsync(requestedPlaybackRate, callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <param name="requestedPlaybackRate" type="Number">A param.</param>
    /// </signature>
  }


  cls.prototype.tryChangeShuffleActiveAsync = function tryChangeShuffleActiveAsync(requestedShuffleState, callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <param name="requestedShuffleState" type="Boolean">A param.</param>
    /// </signature>
  }


  cls.prototype.tryChangePlaybackPositionAsync = function tryChangePlaybackPositionAsync(requestedPlaybackPosition, callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <param name="requestedPlaybackPosition" type="Number">A param.</param>
    /// </signature>
  }


  cls.prototype.getTimelineProperties = function getTimelineProperties() {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <returns type="GlobalSystemMediaTransportControlsSessionTimelineProperties" />
    /// </signature>
    return new GlobalSystemMediaTransportControlsSessionTimelineProperties();
  }


  cls.prototype.getPlaybackInfo = function getPlaybackInfo() {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <returns type="GlobalSystemMediaTransportControlsSessionPlaybackInfo" />
    /// </signature>
    return new GlobalSystemMediaTransportControlsSessionPlaybackInfo();
  }


    cls.prototype.addListener = function addListener(eventName, callback){}
    cls.prototype.removeListener = function removeListener(eventName, callback){}
    cls.prototype.on = function on(eventName, callback){}
    cls.prototype.off = function off(eventName, callback){}
  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSession = GlobalSystemMediaTransportControlsSession;

GlobalSystemMediaTransportControlsSessionManager = (function () {
  var cls = function GlobalSystemMediaTransportControlsSessionManager() {
  };
  

  cls.prototype.getCurrentSession = function getCurrentSession() {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <returns type="GlobalSystemMediaTransportControlsSession" />
    /// </signature>
    return new GlobalSystemMediaTransportControlsSession();
  }


  cls.prototype.getSessions = function getSessions() {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// <returns type="Object" />
    /// </signature>
    return new Object();
  }


  cls.requestAsync = function requestAsync(callback) {
    /// <signature>
    /// <summary>Function summary.</summary>
    /// </signature>
  }



    cls.prototype.addListener = function addListener(eventName, callback){}
    cls.prototype.removeListener = function removeListener(eventName, callback){}
    cls.prototype.on = function on(eventName, callback){}
    cls.prototype.off = function off(eventName, callback){}
  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSessionManager = GlobalSystemMediaTransportControlsSessionManager;

GlobalSystemMediaTransportControlsSessionMediaProperties = (function () {
  var cls = function GlobalSystemMediaTransportControlsSessionMediaProperties() {
    this.albumArtist = new String();
    this.albumTitle = new String();
    this.albumTrackCount = new Number();
    this.artist = new String();
    this.genres = new Object();
    this.playbackType = new Number();
    this.subtitle = new String();
    this.thumbnail = new Object();
    this.title = new String();
    this.trackNumber = new Number();
  };
  

  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSessionMediaProperties = GlobalSystemMediaTransportControlsSessionMediaProperties;

GlobalSystemMediaTransportControlsSessionPlaybackControls = (function () {
  var cls = function GlobalSystemMediaTransportControlsSessionPlaybackControls() {
    this.isChannelDownEnabled = new Boolean();
    this.isChannelUpEnabled = new Boolean();
    this.isFastForwardEnabled = new Boolean();
    this.isNextEnabled = new Boolean();
    this.isPauseEnabled = new Boolean();
    this.isPlayEnabled = new Boolean();
    this.isPlayPauseToggleEnabled = new Boolean();
    this.isPlaybackPositionEnabled = new Boolean();
    this.isPlaybackRateEnabled = new Boolean();
    this.isPreviousEnabled = new Boolean();
    this.isRecordEnabled = new Boolean();
    this.isRepeatEnabled = new Boolean();
    this.isRewindEnabled = new Boolean();
    this.isShuffleEnabled = new Boolean();
    this.isStopEnabled = new Boolean();
  };
  

  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSessionPlaybackControls = GlobalSystemMediaTransportControlsSessionPlaybackControls;

GlobalSystemMediaTransportControlsSessionPlaybackInfo = (function () {
  var cls = function GlobalSystemMediaTransportControlsSessionPlaybackInfo() {
    this.autoRepeatMode = new Number();
    this.controls = new GlobalSystemMediaTransportControlsSessionPlaybackControls();
    this.isShuffleActive = new Boolean();
    this.playbackRate = new Number();
    this.playbackStatus = new GlobalSystemMediaTransportControlsSessionPlaybackStatus();
    this.playbackType = new Number();
  };
  

  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSessionPlaybackInfo = GlobalSystemMediaTransportControlsSessionPlaybackInfo;

GlobalSystemMediaTransportControlsSessionTimelineProperties = (function () {
  var cls = function GlobalSystemMediaTransportControlsSessionTimelineProperties() {
    this.endTime = new Number();
    this.lastUpdatedTime = new Date();
    this.maxSeekTime = new Number();
    this.minSeekTime = new Number();
    this.position = new Number();
    this.startTime = new Number();
  };
  

  return cls;
}) ();
exports.GlobalSystemMediaTransportControlsSessionTimelineProperties = GlobalSystemMediaTransportControlsSessionTimelineProperties;

MediaPropertiesChangedEventArgs = (function () {
  var cls = function MediaPropertiesChangedEventArgs() {
  };
  

  return cls;
}) ();
exports.MediaPropertiesChangedEventArgs = MediaPropertiesChangedEventArgs;

PlaybackInfoChangedEventArgs = (function () {
  var cls = function PlaybackInfoChangedEventArgs() {
  };
  

  return cls;
}) ();
exports.PlaybackInfoChangedEventArgs = PlaybackInfoChangedEventArgs;

SessionsChangedEventArgs = (function () {
  var cls = function SessionsChangedEventArgs() {
  };
  

  return cls;
}) ();
exports.SessionsChangedEventArgs = SessionsChangedEventArgs;

TimelinePropertiesChangedEventArgs = (function () {
  var cls = function TimelinePropertiesChangedEventArgs() {
  };
  

  return cls;
}) ();
exports.TimelinePropertiesChangedEventArgs = TimelinePropertiesChangedEventArgs;

