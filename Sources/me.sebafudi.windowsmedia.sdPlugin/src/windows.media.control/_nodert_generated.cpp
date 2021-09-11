// Copyright (c) The NodeRT Contributors
// All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the ""License""); you may
// not use this file except in compliance with the License. You may obtain a
// copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS
// OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY
// IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE,
// MERCHANTABLITY OR NON-INFRINGEMENT.
//
// See the Apache Version 2.0 License for specific language governing permissions
// and limitations under the License.

// TODO: Verify that this is is still needed..
#define NTDDI_VERSION 0x06010000

#include <v8.h>
#include "nan.h"
#include <string>
#include <ppltasks.h>
#include "CollectionsConverter.h"
#include "CollectionsWrap.h"
#include "node-async.h"
#include "NodeRtUtils.h"
#include "OpaqueWrapper.h"
#include "WrapperBase.h"

#using <Windows.WinMD>

// this undefs fixes the issues of compiling Windows.Data.Json, Windows.Storag.FileProperties, and Windows.Stroage.Search
// Some of the node header files brings windows definitions with the same names as some of the WinRT methods
#undef DocumentProperties
#undef GetObject
#undef CreateEvent
#undef FindText
#undef SendMessage

const char* REGISTRATION_TOKEN_MAP_PROPERTY_NAME = "__registrationTokenMap__";

using v8::Array;
using v8::String;
using v8::Value;
using v8::Boolean;
using v8::Integer;
using v8::FunctionTemplate;
using v8::Object;
using v8::Local;
using v8::Function;
using v8::Date;
using v8::Number;
using v8::PropertyAttribute;
using v8::Primitive;
using Nan::HandleScope;
using Nan::Persistent;
using Nan::Undefined;
using Nan::True;
using Nan::False;
using Nan::Null;
using Nan::MaybeLocal;
using Nan::EscapableHandleScope;
using Nan::HandleScope;
using Nan::TryCatch;
using namespace concurrency;

namespace NodeRT { namespace Windows { namespace Media { namespace Control { 
  v8::Local<v8::Value> WrapCurrentSessionChangedEventArgs(::Windows::Media::Control::CurrentSessionChangedEventArgs^ wintRtInstance);
  ::Windows::Media::Control::CurrentSessionChangedEventArgs^ UnwrapCurrentSessionChangedEventArgs(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSession(::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ UnwrapGlobalSystemMediaTransportControlsSession(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionManager(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ UnwrapGlobalSystemMediaTransportControlsSessionManager(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionMediaProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ UnwrapGlobalSystemMediaTransportControlsSessionMediaProperties(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackControls(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackControls(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(Local<Value> value);
  
  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionTimelineProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ wintRtInstance);
  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ UnwrapGlobalSystemMediaTransportControlsSessionTimelineProperties(Local<Value> value);
  
  v8::Local<v8::Value> WrapMediaPropertiesChangedEventArgs(::Windows::Media::Control::MediaPropertiesChangedEventArgs^ wintRtInstance);
  ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ UnwrapMediaPropertiesChangedEventArgs(Local<Value> value);
  
  v8::Local<v8::Value> WrapPlaybackInfoChangedEventArgs(::Windows::Media::Control::PlaybackInfoChangedEventArgs^ wintRtInstance);
  ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ UnwrapPlaybackInfoChangedEventArgs(Local<Value> value);
  
  v8::Local<v8::Value> WrapSessionsChangedEventArgs(::Windows::Media::Control::SessionsChangedEventArgs^ wintRtInstance);
  ::Windows::Media::Control::SessionsChangedEventArgs^ UnwrapSessionsChangedEventArgs(Local<Value> value);
  
  v8::Local<v8::Value> WrapTimelinePropertiesChangedEventArgs(::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ wintRtInstance);
  ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ UnwrapTimelinePropertiesChangedEventArgs(Local<Value> value);
  



  static void InitGlobalSystemMediaTransportControlsSessionPlaybackStatusEnum(const Local<Object> exports) {
    HandleScope scope;

    Local<Object> enumObject = Nan::New<Object>();

    Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionPlaybackStatus").ToLocalChecked(), enumObject);
    Nan::Set(enumObject, Nan::New<String>("closed").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Closed)));
    Nan::Set(enumObject, Nan::New<String>("opened").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Opened)));
    Nan::Set(enumObject, Nan::New<String>("changing").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Changing)));
    Nan::Set(enumObject, Nan::New<String>("stopped").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Stopped)));
    Nan::Set(enumObject, Nan::New<String>("playing").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing)));
    Nan::Set(enumObject, Nan::New<String>("paused").ToLocalChecked(), Nan::New<Integer>(static_cast<int>(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Paused)));
  }



  class CurrentSessionChangedEventArgs : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("CurrentSessionChangedEventArgs").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);






        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("CurrentSessionChangedEventArgs").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      CurrentSessionChangedEventArgs(::Windows::Media::Control::CurrentSessionChangedEventArgs^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::CurrentSessionChangedEventArgs^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::CurrentSessionChangedEventArgs^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::CurrentSessionChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      CurrentSessionChangedEventArgs *wrapperInstance = new CurrentSessionChangedEventArgs(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::CurrentSessionChangedEventArgs^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::CurrentSessionChangedEventArgs^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::CurrentSessionChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapCurrentSessionChangedEventArgs(winRtInstance));
    }







    private:
      ::Windows::Media::Control::CurrentSessionChangedEventArgs^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapCurrentSessionChangedEventArgs(::Windows::Media::Control::CurrentSessionChangedEventArgs^ wintRtInstance);
      friend ::Windows::Media::Control::CurrentSessionChangedEventArgs^ UnwrapCurrentSessionChangedEventArgs(Local<Value> value);
  };

  Persistent<FunctionTemplate> CurrentSessionChangedEventArgs::s_constructorTemplate;

  v8::Local<v8::Value> WrapCurrentSessionChangedEventArgs(::Windows::Media::Control::CurrentSessionChangedEventArgs^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(CurrentSessionChangedEventArgs::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::CurrentSessionChangedEventArgs^ UnwrapCurrentSessionChangedEventArgs(Local<Value> value) {
     return CurrentSessionChangedEventArgs::Unwrap<CurrentSessionChangedEventArgs>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitCurrentSessionChangedEventArgs(Local<Object> exports) {
    CurrentSessionChangedEventArgs::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSession : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSession").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);

        Local<Function> func;
        Local<FunctionTemplate> funcTemplate;

          
            Nan::SetPrototypeMethod(localRef, "getTimelineProperties", GetTimelineProperties);
            Nan::SetPrototypeMethod(localRef, "getPlaybackInfo", GetPlaybackInfo);
          

          
            Nan::SetPrototypeMethod(localRef, "tryGetMediaPropertiesAsync", TryGetMediaPropertiesAsync);
            Nan::SetPrototypeMethod(localRef, "tryPlayAsync", TryPlayAsync);
            Nan::SetPrototypeMethod(localRef, "tryPauseAsync", TryPauseAsync);
            Nan::SetPrototypeMethod(localRef, "tryStopAsync", TryStopAsync);
            Nan::SetPrototypeMethod(localRef, "tryRecordAsync", TryRecordAsync);
            Nan::SetPrototypeMethod(localRef, "tryFastForwardAsync", TryFastForwardAsync);
            Nan::SetPrototypeMethod(localRef, "tryRewindAsync", TryRewindAsync);
            Nan::SetPrototypeMethod(localRef, "trySkipNextAsync", TrySkipNextAsync);
            Nan::SetPrototypeMethod(localRef, "trySkipPreviousAsync", TrySkipPreviousAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangeChannelUpAsync", TryChangeChannelUpAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangeChannelDownAsync", TryChangeChannelDownAsync);
            Nan::SetPrototypeMethod(localRef, "tryTogglePlayPauseAsync", TryTogglePlayPauseAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangeAutoRepeatModeAsync", TryChangeAutoRepeatModeAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangePlaybackRateAsync", TryChangePlaybackRateAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangeShuffleActiveAsync", TryChangeShuffleActiveAsync);
            Nan::SetPrototypeMethod(localRef, "tryChangePlaybackPositionAsync", TryChangePlaybackPositionAsync);
          

          
          Nan::SetPrototypeMethod(localRef,"addListener", AddListener);
          Nan::SetPrototypeMethod(localRef,"on", AddListener);
          Nan::SetPrototypeMethod(localRef,"removeListener", RemoveListener);
          Nan::SetPrototypeMethod(localRef, "off", RemoveListener);

          
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("sourceAppUserModelId").ToLocalChecked(), SourceAppUserModelIdGetter);

        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSession").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSession(::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSession *wrapperInstance = new GlobalSystemMediaTransportControlsSession(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSession(winRtInstance));
    }

    static void TryGetMediaPropertiesAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryGetMediaPropertiesAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = WrapGlobalSystemMediaTransportControlsSessionMediaProperties(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryPlayAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryPlayAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryPauseAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryPauseAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryStopAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryStopAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryRecordAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryRecordAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryFastForwardAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryFastForwardAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryRewindAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryRewindAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TrySkipNextAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TrySkipNextAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TrySkipPreviousAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TrySkipPreviousAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangeChannelUpAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryChangeChannelUpAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangeChannelDownAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryChangeChannelDownAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryTogglePlayPauseAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = wrapper->_instance->TryTogglePlayPauseAsync();
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangeAutoRepeatModeAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 2
        && info[0]->IsInt32())
      {
        try
        {
          ::Windows::Media::MediaPlaybackAutoRepeatMode arg0 = static_cast<::Windows::Media::MediaPlaybackAutoRepeatMode>(Nan::To<int32_t>(info[0]).FromMaybe(0));
          
          op = wrapper->_instance->TryChangeAutoRepeatModeAsync(arg0);
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangePlaybackRateAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 2
        && info[0]->IsNumber())
      {
        try
        {
          double arg0 = Nan::To<double>(info[0]).FromMaybe(0.0);
          
          op = wrapper->_instance->TryChangePlaybackRateAsync(arg0);
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangeShuffleActiveAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 2
        && info[0]->IsBoolean())
      {
        try
        {
          bool arg0 = Nan::To<bool>(info[0]).FromMaybe(false);
          
          op = wrapper->_instance->TryChangeShuffleActiveAsync(arg0);
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }
    static void TryChangePlaybackPositionAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      ::Windows::Foundation::IAsyncOperation<bool>^ op;


      if (info.Length() == 2
        && info[0]->IsNumber())
      {
        try
        {
          __int64 arg0 = Nan::To<int64_t>(info[0]).FromMaybe(0);
          
          op = wrapper->_instance->TryChangePlaybackPositionAsync(arg0);
        }
        catch (Platform::Exception ^exception)
        {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<bool> t) {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = Nan::New<Boolean>(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        } catch (Platform::Exception^ exception) {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {
            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }

    static void GetTimelineProperties(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      if (info.Length() == 0)
      {
        try
        {
          ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ result;
          result = wrapper->_instance->GetTimelineProperties();
          info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionTimelineProperties(result));
          return;
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }
    }
    static void GetPlaybackInfo(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      if (info.Length() == 0)
      {
        try
        {
          ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ result;
          result = wrapper->_instance->GetPlaybackInfo();
          info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(result));
          return;
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }
    }



    static void SourceAppUserModelIdGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->SourceAppUserModelId;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      


    static void AddListener(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (info.Length() < 2 || !info[0]->IsString() || !info[1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"wrong arguments, expected arguments are eventName(string),callback(function)")));
        return;
      }

      String::Value eventName(v8::Isolate::GetCurrent(), info[0]);
      auto str = *eventName;

      Local<Function> callback = info[1].As<Function>();

      ::Windows::Foundation::EventRegistrationToken registrationToken;
      if (NodeRT::Utils::CaseInsenstiveEquals(L"mediaPropertiesChanged", str))
      {
        if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
        {
          Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
      return;
        }
        GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
      
        try {
          Persistent<Object>* perstPtr = new Persistent<Object>();
          perstPtr->Reset(NodeRT::Utils::CreateCallbackObjectInDomain(callback));
          std::shared_ptr<Persistent<Object>> callbackObjPtr(perstPtr,
            [] (Persistent<Object> *ptr ) {
              NodeUtils::Async::RunOnMain([ptr]() {
                ptr->Reset();
                delete ptr;
            });
          });

          registrationToken = wrapper->_instance->MediaPropertiesChanged::add(
            ref new ::Windows::Foundation::TypedEventHandler<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^, ::Windows::Media::Control::MediaPropertiesChangedEventArgs^>(
            [callbackObjPtr](::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ arg0, ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ arg1) {
              NodeUtils::Async::RunOnMain([callbackObjPtr , arg0, arg1]() {
                HandleScope scope;


                Local<Value> wrappedArg0;
                Local<Value> wrappedArg1;

                {
                  TryCatch tryCatch;


                  wrappedArg0 = WrapGlobalSystemMediaTransportControlsSession(arg0);
                  wrappedArg1 = WrapMediaPropertiesChangedEventArgs(arg1);


                  if (wrappedArg0.IsEmpty()) wrappedArg0 = Undefined();
                  if (wrappedArg1.IsEmpty()) wrappedArg1 = Undefined();
                }

                Local<Value> args[] = { wrappedArg0, wrappedArg1 };
                Local<Object> callbackObjLocalRef = Nan::New<Object>(*callbackObjPtr);
                NodeRT::Utils::CallCallbackInDomain(callbackObjLocalRef, _countof(args), args);
              });
            })
          );
        }
        catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }

      }
      else if (NodeRT::Utils::CaseInsenstiveEquals(L"playbackInfoChanged", str))
      {
        if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
        {
          Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
      return;
        }
        GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
      
        try {
          Persistent<Object>* perstPtr = new Persistent<Object>();
          perstPtr->Reset(NodeRT::Utils::CreateCallbackObjectInDomain(callback));
          std::shared_ptr<Persistent<Object>> callbackObjPtr(perstPtr,
            [] (Persistent<Object> *ptr ) {
              NodeUtils::Async::RunOnMain([ptr]() {
                ptr->Reset();
                delete ptr;
            });
          });

          registrationToken = wrapper->_instance->PlaybackInfoChanged::add(
            ref new ::Windows::Foundation::TypedEventHandler<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^, ::Windows::Media::Control::PlaybackInfoChangedEventArgs^>(
            [callbackObjPtr](::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ arg0, ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ arg1) {
              NodeUtils::Async::RunOnMain([callbackObjPtr , arg0, arg1]() {
                HandleScope scope;


                Local<Value> wrappedArg0;
                Local<Value> wrappedArg1;

                {
                  TryCatch tryCatch;


                  wrappedArg0 = WrapGlobalSystemMediaTransportControlsSession(arg0);
                  wrappedArg1 = WrapPlaybackInfoChangedEventArgs(arg1);


                  if (wrappedArg0.IsEmpty()) wrappedArg0 = Undefined();
                  if (wrappedArg1.IsEmpty()) wrappedArg1 = Undefined();
                }

                Local<Value> args[] = { wrappedArg0, wrappedArg1 };
                Local<Object> callbackObjLocalRef = Nan::New<Object>(*callbackObjPtr);
                NodeRT::Utils::CallCallbackInDomain(callbackObjLocalRef, _countof(args), args);
              });
            })
          );
        }
        catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }

      }
      else if (NodeRT::Utils::CaseInsenstiveEquals(L"timelinePropertiesChanged", str))
      {
        if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
        {
          Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
      return;
        }
        GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
      
        try {
          Persistent<Object>* perstPtr = new Persistent<Object>();
          perstPtr->Reset(NodeRT::Utils::CreateCallbackObjectInDomain(callback));
          std::shared_ptr<Persistent<Object>> callbackObjPtr(perstPtr,
            [] (Persistent<Object> *ptr ) {
              NodeUtils::Async::RunOnMain([ptr]() {
                ptr->Reset();
                delete ptr;
            });
          });

          registrationToken = wrapper->_instance->TimelinePropertiesChanged::add(
            ref new ::Windows::Foundation::TypedEventHandler<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^, ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^>(
            [callbackObjPtr](::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ arg0, ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ arg1) {
              NodeUtils::Async::RunOnMain([callbackObjPtr , arg0, arg1]() {
                HandleScope scope;


                Local<Value> wrappedArg0;
                Local<Value> wrappedArg1;

                {
                  TryCatch tryCatch;


                  wrappedArg0 = WrapGlobalSystemMediaTransportControlsSession(arg0);
                  wrappedArg1 = WrapTimelinePropertiesChangedEventArgs(arg1);


                  if (wrappedArg0.IsEmpty()) wrappedArg0 = Undefined();
                  if (wrappedArg1.IsEmpty()) wrappedArg1 = Undefined();
                }

                Local<Value> args[] = { wrappedArg0, wrappedArg1 };
                Local<Object> callbackObjLocalRef = Nan::New<Object>(*callbackObjPtr);
                NodeRT::Utils::CallCallbackInDomain(callbackObjLocalRef, _countof(args), args);
              });
            })
          );
        }
        catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }

      }
 else  {
        Nan::ThrowError(Nan::Error(String::Concat(v8::Isolate::GetCurrent(), NodeRT::Utils::NewString(L"given event name isn't supported: "), info[0].As<String>())));
        return;
      }

      Local<Value> tokenMapVal = NodeRT::Utils::GetHiddenValue(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked());
      Local<Object> tokenMap;

      if (tokenMapVal.IsEmpty() || Nan::Equals(tokenMapVal, Undefined()).FromMaybe(false)) {
        tokenMap = Nan::New<Object>();
        NodeRT::Utils::SetHiddenValueWithObject(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked(), tokenMap);
      } else {
        tokenMap = Nan::To<Object>(tokenMapVal).ToLocalChecked();
      }

      Nan::Set(tokenMap, info[0], CreateOpaqueWrapper(::Windows::Foundation::PropertyValue::CreateInt64(registrationToken.Value)));
    }

    static void RemoveListener(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (info.Length() < 2 || !info[0]->IsString() || !info[1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"wrong arguments, expected a string and a callback")));
        return;
      }

      String::Value eventName(v8::Isolate::GetCurrent(), info[0]);
      auto str = *eventName;

      if ((!NodeRT::Utils::CaseInsenstiveEquals(L"mediaPropertiesChanged", str)) &&(!NodeRT::Utils::CaseInsenstiveEquals(L"playbackInfoChanged", str)) &&(!NodeRT::Utils::CaseInsenstiveEquals(L"timelinePropertiesChanged", str))) {
        Nan::ThrowError(Nan::Error(String::Concat(v8::Isolate::GetCurrent(), NodeRT::Utils::NewString(L"given event name isn't supported: "), info[0].As<String>())));
        return;
      }

      Local<Function> callback = info[1].As<Function>();
      Local<Value> tokenMap = NodeRT::Utils::GetHiddenValue(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked());

      if (tokenMap.IsEmpty() || Nan::Equals(tokenMap, Undefined()).FromMaybe(false)) {
        return;
      }

      Local<Value> opaqueWrapperObj =  Nan::Get(Nan::To<Object>(tokenMap).ToLocalChecked(), info[0]).ToLocalChecked();

      if (opaqueWrapperObj.IsEmpty() || Nan::Equals(opaqueWrapperObj,Undefined()).FromMaybe(false)) {
        return;
      }

      OpaqueWrapper *opaqueWrapper = OpaqueWrapper::Unwrap<OpaqueWrapper>(opaqueWrapperObj.As<Object>());

      long long tokenValue = (long long) opaqueWrapper->GetObjectInstance();
      ::Windows::Foundation::EventRegistrationToken registrationToken;
      registrationToken.Value = tokenValue;

      try  {
        if (NodeRT::Utils::CaseInsenstiveEquals(L"mediaPropertiesChanged", str)) {
          if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
          {
            Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
            return;
          }
          GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
          wrapper->_instance->MediaPropertiesChanged::remove(registrationToken);
        }
        else if (NodeRT::Utils::CaseInsenstiveEquals(L"playbackInfoChanged", str))
        {
          if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
          {
            Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
            return;
          }
          GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
          wrapper->_instance->PlaybackInfoChanged::remove(registrationToken);
        }
        else if (NodeRT::Utils::CaseInsenstiveEquals(L"timelinePropertiesChanged", str))
        {
          if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(info.This()))
          {
            Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
            return;
          }
          GlobalSystemMediaTransportControlsSession *wrapper = GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(info.This());
          wrapper->_instance->TimelinePropertiesChanged::remove(registrationToken);
        }
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
      }

      Nan::Delete(Nan::To<Object>(tokenMap).ToLocalChecked(), Nan::To<String>(info[0]).ToLocalChecked());
    }
    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSession(::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ UnwrapGlobalSystemMediaTransportControlsSession(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSession::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSession(::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSession::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ UnwrapGlobalSystemMediaTransportControlsSession(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSession::Unwrap<GlobalSystemMediaTransportControlsSession>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSession(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSession::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSessionManager : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSessionManager").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);

        Local<Function> func;
        Local<FunctionTemplate> funcTemplate;

          
            Nan::SetPrototypeMethod(localRef, "getCurrentSession", GetCurrentSession);
            Nan::SetPrototypeMethod(localRef, "getSessions", GetSessions);
          


          
          Nan::SetPrototypeMethod(localRef,"addListener", AddListener);
          Nan::SetPrototypeMethod(localRef,"on", AddListener);
          Nan::SetPrototypeMethod(localRef,"removeListener", RemoveListener);
          Nan::SetPrototypeMethod(localRef, "off", RemoveListener);


        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);

        func = Nan::GetFunction(Nan::New<FunctionTemplate>(RequestAsync)).ToLocalChecked();
        Nan::Set(constructor, Nan::New<String>("requestAsync").ToLocalChecked(), func);


        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionManager").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSessionManager(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSessionManager *wrapperInstance = new GlobalSystemMediaTransportControlsSessionManager(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionManager(winRtInstance));
    }


    static void GetCurrentSession(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());

      if (info.Length() == 0)
      {
        try
        {
          ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ result;
          result = wrapper->_instance->GetCurrentSession();
          info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSession(result));
          return;
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }
    }
    static void GetSessions(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());

      if (info.Length() == 0)
      {
        try
        {
          ::Windows::Foundation::Collections::IVectorView<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>^ result;
          result = wrapper->_instance->GetSessions();
          info.GetReturnValue().Set(NodeRT::Collections::VectorViewWrapper<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>::CreateVectorViewWrapper(result, 
            [](::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ val) -> Local<Value> {
              return WrapGlobalSystemMediaTransportControlsSession(val);
            },
            [](Local<Value> value) -> bool {
              return NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^>(value);
            },
            [](Local<Value> value) -> ::Windows::Media::Control::GlobalSystemMediaTransportControlsSession^ {
              return UnwrapGlobalSystemMediaTransportControlsSession(value);
            }
          ));
          return;
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }
    }


    static void RequestAsync(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (info.Length() == 0 || !info[info.Length() -1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: No callback was given")));
        return;
      }

      ::Windows::Foundation::IAsyncOperation<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>^ op;


      if (info.Length() == 1)
      {
        try
        {
          op = ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync();
        } catch (Platform::Exception ^exception) {
            NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
            return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Bad arguments: no suitable overload found")));
        return;
      }

      auto opTask = create_task(op);
      uv_async_t* asyncToken = NodeUtils::Async::GetAsyncToken(info[info.Length() -1].As<Function>());

      opTask.then( [asyncToken] (task<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^> t)
      {
        try {
          auto result = t.get();
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [result](NodeUtils::InvokeCallbackDelegate invokeCallback) {


            Local<Value> error;
            Local<Value> arg1;
            {
              TryCatch tryCatch;
              arg1 = WrapGlobalSystemMediaTransportControlsSessionManager(result);
              if (tryCatch.HasCaught())
              {
                error = Nan::To<Object>(tryCatch.Exception()).ToLocalChecked();
              }
              else
              {
                error = Undefined();
              }
              if (arg1.IsEmpty()) arg1 = Undefined();
            }
            Local<Value> args[] = {error, arg1};


            invokeCallback(_countof(args), args);
          });
        }
        catch (Platform::Exception^ exception)
        {
          NodeUtils::Async::RunCallbackOnMain(asyncToken, [exception](NodeUtils::InvokeCallbackDelegate invokeCallback) {

            Local<Value> error = NodeRT::Utils::WinRtExceptionToJsError(exception);

            Local<Value> args[] = {error};
            invokeCallback(_countof(args), args);
          });
        }
      });
    }




    static void AddListener(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (info.Length() < 2 || !info[0]->IsString() || !info[1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"wrong arguments, expected arguments are eventName(string),callback(function)")));
        return;
      }

      String::Value eventName(v8::Isolate::GetCurrent(), info[0]);
      auto str = *eventName;

      Local<Function> callback = info[1].As<Function>();

      ::Windows::Foundation::EventRegistrationToken registrationToken;
      if (NodeRT::Utils::CaseInsenstiveEquals(L"currentSessionChanged", str))
      {
        if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This()))
        {
          Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
      return;
        }
        GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());
      
        try {
          Persistent<Object>* perstPtr = new Persistent<Object>();
          perstPtr->Reset(NodeRT::Utils::CreateCallbackObjectInDomain(callback));
          std::shared_ptr<Persistent<Object>> callbackObjPtr(perstPtr,
            [] (Persistent<Object> *ptr ) {
              NodeUtils::Async::RunOnMain([ptr]() {
                ptr->Reset();
                delete ptr;
            });
          });

          registrationToken = wrapper->_instance->CurrentSessionChanged::add(
            ref new ::Windows::Foundation::TypedEventHandler<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^, ::Windows::Media::Control::CurrentSessionChangedEventArgs^>(
            [callbackObjPtr](::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ arg0, ::Windows::Media::Control::CurrentSessionChangedEventArgs^ arg1) {
              NodeUtils::Async::RunOnMain([callbackObjPtr , arg0, arg1]() {
                HandleScope scope;


                Local<Value> wrappedArg0;
                Local<Value> wrappedArg1;

                {
                  TryCatch tryCatch;


                  wrappedArg0 = WrapGlobalSystemMediaTransportControlsSessionManager(arg0);
                  wrappedArg1 = WrapCurrentSessionChangedEventArgs(arg1);


                  if (wrappedArg0.IsEmpty()) wrappedArg0 = Undefined();
                  if (wrappedArg1.IsEmpty()) wrappedArg1 = Undefined();
                }

                Local<Value> args[] = { wrappedArg0, wrappedArg1 };
                Local<Object> callbackObjLocalRef = Nan::New<Object>(*callbackObjPtr);
                NodeRT::Utils::CallCallbackInDomain(callbackObjLocalRef, _countof(args), args);
              });
            })
          );
        }
        catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }

      }
      else if (NodeRT::Utils::CaseInsenstiveEquals(L"sessionsChanged", str))
      {
        if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This()))
        {
          Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
      return;
        }
        GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());
      
        try {
          Persistent<Object>* perstPtr = new Persistent<Object>();
          perstPtr->Reset(NodeRT::Utils::CreateCallbackObjectInDomain(callback));
          std::shared_ptr<Persistent<Object>> callbackObjPtr(perstPtr,
            [] (Persistent<Object> *ptr ) {
              NodeUtils::Async::RunOnMain([ptr]() {
                ptr->Reset();
                delete ptr;
            });
          });

          registrationToken = wrapper->_instance->SessionsChanged::add(
            ref new ::Windows::Foundation::TypedEventHandler<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^, ::Windows::Media::Control::SessionsChangedEventArgs^>(
            [callbackObjPtr](::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ arg0, ::Windows::Media::Control::SessionsChangedEventArgs^ arg1) {
              NodeUtils::Async::RunOnMain([callbackObjPtr , arg0, arg1]() {
                HandleScope scope;


                Local<Value> wrappedArg0;
                Local<Value> wrappedArg1;

                {
                  TryCatch tryCatch;


                  wrappedArg0 = WrapGlobalSystemMediaTransportControlsSessionManager(arg0);
                  wrappedArg1 = WrapSessionsChangedEventArgs(arg1);


                  if (wrappedArg0.IsEmpty()) wrappedArg0 = Undefined();
                  if (wrappedArg1.IsEmpty()) wrappedArg1 = Undefined();
                }

                Local<Value> args[] = { wrappedArg0, wrappedArg1 };
                Local<Object> callbackObjLocalRef = Nan::New<Object>(*callbackObjPtr);
                NodeRT::Utils::CallCallbackInDomain(callbackObjLocalRef, _countof(args), args);
              });
            })
          );
        }
        catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }

      }
 else  {
        Nan::ThrowError(Nan::Error(String::Concat(v8::Isolate::GetCurrent(), NodeRT::Utils::NewString(L"given event name isn't supported: "), info[0].As<String>())));
        return;
      }

      Local<Value> tokenMapVal = NodeRT::Utils::GetHiddenValue(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked());
      Local<Object> tokenMap;

      if (tokenMapVal.IsEmpty() || Nan::Equals(tokenMapVal, Undefined()).FromMaybe(false)) {
        tokenMap = Nan::New<Object>();
        NodeRT::Utils::SetHiddenValueWithObject(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked(), tokenMap);
      } else {
        tokenMap = Nan::To<Object>(tokenMapVal).ToLocalChecked();
      }

      Nan::Set(tokenMap, info[0], CreateOpaqueWrapper(::Windows::Foundation::PropertyValue::CreateInt64(registrationToken.Value)));
    }

    static void RemoveListener(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      if (info.Length() < 2 || !info[0]->IsString() || !info[1]->IsFunction()) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"wrong arguments, expected a string and a callback")));
        return;
      }

      String::Value eventName(v8::Isolate::GetCurrent(), info[0]);
      auto str = *eventName;

      if ((!NodeRT::Utils::CaseInsenstiveEquals(L"currentSessionChanged", str)) &&(!NodeRT::Utils::CaseInsenstiveEquals(L"sessionsChanged", str))) {
        Nan::ThrowError(Nan::Error(String::Concat(v8::Isolate::GetCurrent(), NodeRT::Utils::NewString(L"given event name isn't supported: "), info[0].As<String>())));
        return;
      }

      Local<Function> callback = info[1].As<Function>();
      Local<Value> tokenMap = NodeRT::Utils::GetHiddenValue(callback, Nan::New<String>(REGISTRATION_TOKEN_MAP_PROPERTY_NAME).ToLocalChecked());

      if (tokenMap.IsEmpty() || Nan::Equals(tokenMap, Undefined()).FromMaybe(false)) {
        return;
      }

      Local<Value> opaqueWrapperObj =  Nan::Get(Nan::To<Object>(tokenMap).ToLocalChecked(), info[0]).ToLocalChecked();

      if (opaqueWrapperObj.IsEmpty() || Nan::Equals(opaqueWrapperObj,Undefined()).FromMaybe(false)) {
        return;
      }

      OpaqueWrapper *opaqueWrapper = OpaqueWrapper::Unwrap<OpaqueWrapper>(opaqueWrapperObj.As<Object>());

      long long tokenValue = (long long) opaqueWrapper->GetObjectInstance();
      ::Windows::Foundation::EventRegistrationToken registrationToken;
      registrationToken.Value = tokenValue;

      try  {
        if (NodeRT::Utils::CaseInsenstiveEquals(L"currentSessionChanged", str)) {
          if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This()))
          {
            Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
            return;
          }
          GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());
          wrapper->_instance->CurrentSessionChanged::remove(registrationToken);
        }
        else if (NodeRT::Utils::CaseInsenstiveEquals(L"sessionsChanged", str))
        {
          if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^>(info.This()))
          {
            Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"The caller of this method isn't of the expected type or internal WinRt object was disposed")));
            return;
          }
          GlobalSystemMediaTransportControlsSessionManager *wrapper = GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(info.This());
          wrapper->_instance->SessionsChanged::remove(registrationToken);
        }
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
      }

      Nan::Delete(Nan::To<Object>(tokenMap).ToLocalChecked(), Nan::To<String>(info[0]).ToLocalChecked());
    }
    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionManager(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ UnwrapGlobalSystemMediaTransportControlsSessionManager(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSessionManager::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionManager(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSessionManager::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager^ UnwrapGlobalSystemMediaTransportControlsSessionManager(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSessionManager::Unwrap<GlobalSystemMediaTransportControlsSessionManager>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSessionManager(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSessionManager::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSessionMediaProperties : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSessionMediaProperties").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);





          
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("albumArtist").ToLocalChecked(), AlbumArtistGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("albumTitle").ToLocalChecked(), AlbumTitleGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("albumTrackCount").ToLocalChecked(), AlbumTrackCountGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("artist").ToLocalChecked(), ArtistGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("genres").ToLocalChecked(), GenresGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("playbackType").ToLocalChecked(), PlaybackTypeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("subtitle").ToLocalChecked(), SubtitleGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("thumbnail").ToLocalChecked(), ThumbnailGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("title").ToLocalChecked(), TitleGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("trackNumber").ToLocalChecked(), TrackNumberGetter);

        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionMediaProperties").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSessionMediaProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapperInstance = new GlobalSystemMediaTransportControlsSessionMediaProperties(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionMediaProperties(winRtInstance));
    }





    static void AlbumArtistGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->AlbumArtist;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void AlbumTitleGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->AlbumTitle;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void AlbumTrackCountGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        int result = wrapper->_instance->AlbumTrackCount;
        info.GetReturnValue().Set(Nan::New<Integer>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void ArtistGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->Artist;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void GenresGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        ::Windows::Foundation::Collections::IVectorView<::Platform::String^>^ result = wrapper->_instance->Genres;
        info.GetReturnValue().Set(NodeRT::Collections::VectorViewWrapper<::Platform::String^>::CreateVectorViewWrapper(result, 
            [](::Platform::String^ val) -> Local<Value> {
              return NodeRT::Utils::NewString(val->Data());
            },
            [](Local<Value> value) -> bool {
              return value->IsString();
            },
            [](Local<Value> value) -> ::Platform::String^ {
              return ref new Platform::String(NodeRT::Utils::StringToWchar(v8::String::Value(v8::Isolate::GetCurrent(), value)));
            }
          ));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void PlaybackTypeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        ::Platform::IBox<::Windows::Media::MediaPlaybackType>^ result = wrapper->_instance->PlaybackType;
        info.GetReturnValue().Set(result ? static_cast<Local<Value>>(Nan::New<Integer>(static_cast<int>(result->Value))) : Undefined());
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void SubtitleGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->Subtitle;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void ThumbnailGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        ::Windows::Storage::Streams::IRandomAccessStreamReference^ result = wrapper->_instance->Thumbnail;
        info.GetReturnValue().Set(NodeRT::Utils::CreateExternalWinRTObject("Windows.Storage.Streams", "IRandomAccessStreamReference", result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void TitleGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        Platform::String^ result = wrapper->_instance->Title;
        info.GetReturnValue().Set(NodeRT::Utils::NewString(result->Data()));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void TrackNumberGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionMediaProperties *wrapper = GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(info.This());

      try  {
        int result = wrapper->_instance->TrackNumber;
        info.GetReturnValue().Set(Nan::New<Integer>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      


    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionMediaProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ UnwrapGlobalSystemMediaTransportControlsSessionMediaProperties(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSessionMediaProperties::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionMediaProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSessionMediaProperties::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionMediaProperties^ UnwrapGlobalSystemMediaTransportControlsSessionMediaProperties(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSessionMediaProperties::Unwrap<GlobalSystemMediaTransportControlsSessionMediaProperties>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSessionMediaProperties(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSessionMediaProperties::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSessionPlaybackControls : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSessionPlaybackControls").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);





          
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isChannelDownEnabled").ToLocalChecked(), IsChannelDownEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isChannelUpEnabled").ToLocalChecked(), IsChannelUpEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isFastForwardEnabled").ToLocalChecked(), IsFastForwardEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isNextEnabled").ToLocalChecked(), IsNextEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPauseEnabled").ToLocalChecked(), IsPauseEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPlayEnabled").ToLocalChecked(), IsPlayEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPlayPauseToggleEnabled").ToLocalChecked(), IsPlayPauseToggleEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPlaybackPositionEnabled").ToLocalChecked(), IsPlaybackPositionEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPlaybackRateEnabled").ToLocalChecked(), IsPlaybackRateEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isPreviousEnabled").ToLocalChecked(), IsPreviousEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isRecordEnabled").ToLocalChecked(), IsRecordEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isRepeatEnabled").ToLocalChecked(), IsRepeatEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isRewindEnabled").ToLocalChecked(), IsRewindEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isShuffleEnabled").ToLocalChecked(), IsShuffleEnabledGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isStopEnabled").ToLocalChecked(), IsStopEnabledGetter);

        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionPlaybackControls").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSessionPlaybackControls(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapperInstance = new GlobalSystemMediaTransportControlsSessionPlaybackControls(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionPlaybackControls(winRtInstance));
    }





    static void IsChannelDownEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsChannelDownEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsChannelUpEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsChannelUpEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsFastForwardEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsFastForwardEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsNextEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsNextEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPauseEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPauseEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPlayEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPlayEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPlayPauseToggleEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPlayPauseToggleEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPlaybackPositionEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPlaybackPositionEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPlaybackRateEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPlaybackRateEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsPreviousEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsPreviousEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsRecordEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsRecordEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsRepeatEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsRepeatEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsRewindEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsRewindEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsShuffleEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsShuffleEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsStopEnabledGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackControls *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(info.This());

      try  {
        bool result = wrapper->_instance->IsStopEnabled;
        info.GetReturnValue().Set(Nan::New<Boolean>(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      


    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackControls(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackControls(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSessionPlaybackControls::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackControls(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSessionPlaybackControls::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackControls(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSessionPlaybackControls::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackControls>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSessionPlaybackControls(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSessionPlaybackControls::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSessionPlaybackInfo : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSessionPlaybackInfo").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);





          
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("autoRepeatMode").ToLocalChecked(), AutoRepeatModeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("controls").ToLocalChecked(), ControlsGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("isShuffleActive").ToLocalChecked(), IsShuffleActiveGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("playbackRate").ToLocalChecked(), PlaybackRateGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("playbackStatus").ToLocalChecked(), PlaybackStatusGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("playbackType").ToLocalChecked(), PlaybackTypeGetter);

        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionPlaybackInfo").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSessionPlaybackInfo(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapperInstance = new GlobalSystemMediaTransportControlsSessionPlaybackInfo(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(winRtInstance));
    }





    static void AutoRepeatModeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Platform::IBox<::Windows::Media::MediaPlaybackAutoRepeatMode>^ result = wrapper->_instance->AutoRepeatMode;
        info.GetReturnValue().Set(result ? static_cast<Local<Value>>(Nan::New<Integer>(static_cast<int>(result->Value))) : Undefined());
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void ControlsGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackControls^ result = wrapper->_instance->Controls;
        info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionPlaybackControls(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void IsShuffleActiveGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Platform::IBox<bool>^ result = wrapper->_instance->IsShuffleActive;
        info.GetReturnValue().Set(result ? static_cast<Local<Value>>(Nan::New<Boolean>(result->Value)) : Undefined());
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void PlaybackRateGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Platform::IBox<double>^ result = wrapper->_instance->PlaybackRate;
        info.GetReturnValue().Set(result ? static_cast<Local<Value>>(Nan::New<Number>(static_cast<double>(result->Value))) : Undefined());
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void PlaybackStatusGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus result = wrapper->_instance->PlaybackStatus;
        info.GetReturnValue().Set(Nan::New<Integer>(static_cast<int>(result)));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void PlaybackTypeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionPlaybackInfo *wrapper = GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(info.This());

      try  {
        ::Platform::IBox<::Windows::Media::MediaPlaybackType>^ result = wrapper->_instance->PlaybackType;
        info.GetReturnValue().Set(result ? static_cast<Local<Value>>(Nan::New<Integer>(static_cast<int>(result->Value))) : Undefined());
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      


    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSessionPlaybackInfo::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSessionPlaybackInfo::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackInfo^ UnwrapGlobalSystemMediaTransportControlsSessionPlaybackInfo(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSessionPlaybackInfo::Unwrap<GlobalSystemMediaTransportControlsSessionPlaybackInfo>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSessionPlaybackInfo(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSessionPlaybackInfo::Init(exports);
  }

  class GlobalSystemMediaTransportControlsSessionTimelineProperties : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("GlobalSystemMediaTransportControlsSessionTimelineProperties").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);





          
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("endTime").ToLocalChecked(), EndTimeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("lastUpdatedTime").ToLocalChecked(), LastUpdatedTimeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("maxSeekTime").ToLocalChecked(), MaxSeekTimeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("minSeekTime").ToLocalChecked(), MinSeekTimeGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("position").ToLocalChecked(), PositionGetter);
            Nan::SetAccessor(localRef->PrototypeTemplate(), Nan::New<String>("startTime").ToLocalChecked(), StartTimeGetter);

        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("GlobalSystemMediaTransportControlsSessionTimelineProperties").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      GlobalSystemMediaTransportControlsSessionTimelineProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapperInstance = new GlobalSystemMediaTransportControlsSessionTimelineProperties(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapGlobalSystemMediaTransportControlsSessionTimelineProperties(winRtInstance));
    }





    static void EndTimeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::TimeSpan result = wrapper->_instance->EndTime;
        info.GetReturnValue().Set(Nan::New<Number>(result.Duration/10000.0));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void LastUpdatedTimeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::DateTime result = wrapper->_instance->LastUpdatedTime;
        info.GetReturnValue().Set(NodeRT::Utils::DateTimeToJS(result));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void MaxSeekTimeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::TimeSpan result = wrapper->_instance->MaxSeekTime;
        info.GetReturnValue().Set(Nan::New<Number>(result.Duration/10000.0));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void MinSeekTimeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::TimeSpan result = wrapper->_instance->MinSeekTime;
        info.GetReturnValue().Set(Nan::New<Number>(result.Duration/10000.0));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void PositionGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::TimeSpan result = wrapper->_instance->Position;
        info.GetReturnValue().Set(Nan::New<Number>(result.Duration/10000.0));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      
    static void StartTimeGetter(Local<String> property, const Nan::PropertyCallbackInfo<v8::Value> &info) {
      HandleScope scope;

      if (!NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^>(info.This())) {
        return;
      }

      GlobalSystemMediaTransportControlsSessionTimelineProperties *wrapper = GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(info.This());

      try  {
        ::Windows::Foundation::TimeSpan result = wrapper->_instance->StartTime;
        info.GetReturnValue().Set(Nan::New<Number>(result.Duration/10000.0));
        return;
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }
    }
      


    private:
      ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionTimelineProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ wintRtInstance);
      friend ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ UnwrapGlobalSystemMediaTransportControlsSessionTimelineProperties(Local<Value> value);
  };

  Persistent<FunctionTemplate> GlobalSystemMediaTransportControlsSessionTimelineProperties::s_constructorTemplate;

  v8::Local<v8::Value> WrapGlobalSystemMediaTransportControlsSessionTimelineProperties(::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(GlobalSystemMediaTransportControlsSessionTimelineProperties::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionTimelineProperties^ UnwrapGlobalSystemMediaTransportControlsSessionTimelineProperties(Local<Value> value) {
     return GlobalSystemMediaTransportControlsSessionTimelineProperties::Unwrap<GlobalSystemMediaTransportControlsSessionTimelineProperties>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitGlobalSystemMediaTransportControlsSessionTimelineProperties(Local<Object> exports) {
    GlobalSystemMediaTransportControlsSessionTimelineProperties::Init(exports);
  }

  class MediaPropertiesChangedEventArgs : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("MediaPropertiesChangedEventArgs").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);






        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("MediaPropertiesChangedEventArgs").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      MediaPropertiesChangedEventArgs(::Windows::Media::Control::MediaPropertiesChangedEventArgs^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::MediaPropertiesChangedEventArgs^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::MediaPropertiesChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      MediaPropertiesChangedEventArgs *wrapperInstance = new MediaPropertiesChangedEventArgs(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::MediaPropertiesChangedEventArgs^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::MediaPropertiesChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapMediaPropertiesChangedEventArgs(winRtInstance));
    }







    private:
      ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapMediaPropertiesChangedEventArgs(::Windows::Media::Control::MediaPropertiesChangedEventArgs^ wintRtInstance);
      friend ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ UnwrapMediaPropertiesChangedEventArgs(Local<Value> value);
  };

  Persistent<FunctionTemplate> MediaPropertiesChangedEventArgs::s_constructorTemplate;

  v8::Local<v8::Value> WrapMediaPropertiesChangedEventArgs(::Windows::Media::Control::MediaPropertiesChangedEventArgs^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(MediaPropertiesChangedEventArgs::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::MediaPropertiesChangedEventArgs^ UnwrapMediaPropertiesChangedEventArgs(Local<Value> value) {
     return MediaPropertiesChangedEventArgs::Unwrap<MediaPropertiesChangedEventArgs>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitMediaPropertiesChangedEventArgs(Local<Object> exports) {
    MediaPropertiesChangedEventArgs::Init(exports);
  }

  class PlaybackInfoChangedEventArgs : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("PlaybackInfoChangedEventArgs").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);






        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("PlaybackInfoChangedEventArgs").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      PlaybackInfoChangedEventArgs(::Windows::Media::Control::PlaybackInfoChangedEventArgs^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::PlaybackInfoChangedEventArgs^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::PlaybackInfoChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      PlaybackInfoChangedEventArgs *wrapperInstance = new PlaybackInfoChangedEventArgs(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::PlaybackInfoChangedEventArgs^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::PlaybackInfoChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapPlaybackInfoChangedEventArgs(winRtInstance));
    }







    private:
      ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapPlaybackInfoChangedEventArgs(::Windows::Media::Control::PlaybackInfoChangedEventArgs^ wintRtInstance);
      friend ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ UnwrapPlaybackInfoChangedEventArgs(Local<Value> value);
  };

  Persistent<FunctionTemplate> PlaybackInfoChangedEventArgs::s_constructorTemplate;

  v8::Local<v8::Value> WrapPlaybackInfoChangedEventArgs(::Windows::Media::Control::PlaybackInfoChangedEventArgs^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(PlaybackInfoChangedEventArgs::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::PlaybackInfoChangedEventArgs^ UnwrapPlaybackInfoChangedEventArgs(Local<Value> value) {
     return PlaybackInfoChangedEventArgs::Unwrap<PlaybackInfoChangedEventArgs>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitPlaybackInfoChangedEventArgs(Local<Object> exports) {
    PlaybackInfoChangedEventArgs::Init(exports);
  }

  class SessionsChangedEventArgs : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("SessionsChangedEventArgs").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);






        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("SessionsChangedEventArgs").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      SessionsChangedEventArgs(::Windows::Media::Control::SessionsChangedEventArgs^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::SessionsChangedEventArgs^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::SessionsChangedEventArgs^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::SessionsChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      SessionsChangedEventArgs *wrapperInstance = new SessionsChangedEventArgs(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::SessionsChangedEventArgs^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::SessionsChangedEventArgs^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::SessionsChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapSessionsChangedEventArgs(winRtInstance));
    }







    private:
      ::Windows::Media::Control::SessionsChangedEventArgs^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapSessionsChangedEventArgs(::Windows::Media::Control::SessionsChangedEventArgs^ wintRtInstance);
      friend ::Windows::Media::Control::SessionsChangedEventArgs^ UnwrapSessionsChangedEventArgs(Local<Value> value);
  };

  Persistent<FunctionTemplate> SessionsChangedEventArgs::s_constructorTemplate;

  v8::Local<v8::Value> WrapSessionsChangedEventArgs(::Windows::Media::Control::SessionsChangedEventArgs^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(SessionsChangedEventArgs::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::SessionsChangedEventArgs^ UnwrapSessionsChangedEventArgs(Local<Value> value) {
     return SessionsChangedEventArgs::Unwrap<SessionsChangedEventArgs>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitSessionsChangedEventArgs(Local<Object> exports) {
    SessionsChangedEventArgs::Init(exports);
  }

  class TimelinePropertiesChangedEventArgs : public WrapperBase {
    public:
      
      static void Init(const Local<Object> exports) {
        HandleScope scope;

        Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(New);
        s_constructorTemplate.Reset(localRef);
        localRef->SetClassName(Nan::New<String>("TimelinePropertiesChangedEventArgs").ToLocalChecked());
        localRef->InstanceTemplate()->SetInternalFieldCount(1);






        Local<Object> constructor = Nan::To<Object>(Nan::GetFunction(localRef).ToLocalChecked()).ToLocalChecked();
        Nan::SetMethod(constructor, "castFrom", CastFrom);



        Nan::Set(exports, Nan::New<String>("TimelinePropertiesChangedEventArgs").ToLocalChecked(), constructor);
      }

      virtual ::Platform::Object^ GetObjectInstance() const override {
        return _instance;
      }

    private:

      TimelinePropertiesChangedEventArgs(::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ instance) {
        _instance = instance;
      }

      
    static void New(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;

      Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(s_constructorTemplate);

      // in case the constructor was called without the new operator
      if (!localRef->HasInstance(info.This())) {
        if (info.Length() > 0) {
          std::unique_ptr<Local<Value> []> constructorArgs(new Local<Value>[info.Length()]);

          Local<Value> *argsPtr = constructorArgs.get();
          for (int i = 0; i < info.Length(); i++) {
            argsPtr[i] = info[i];
          }

          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), constructorArgs.get());
          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        } else {
          MaybeLocal<Object> res = Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(), info.Length(), nullptr);

          if (res.IsEmpty()) {
            return;
          }

          info.GetReturnValue().Set(res.ToLocalChecked());
          return;
        }
      }

      ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ winRtInstance;


      if (info.Length() == 1 && OpaqueWrapper::IsOpaqueWrapper(info[0]) &&
        NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::TimelinePropertiesChangedEventArgs^>(info[0])) {
        try {
          winRtInstance = (::Windows::Media::Control::TimelinePropertiesChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
        } catch (Platform::Exception ^exception) {
          NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
          return;
        }
      }
 else {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no suitable constructor found")));
        return;
      }

      NodeRT::Utils::SetHiddenValue(info.This(), Nan::New<String>("__winRtInstance__").ToLocalChecked(), True());

      TimelinePropertiesChangedEventArgs *wrapperInstance = new TimelinePropertiesChangedEventArgs(winRtInstance);
      wrapperInstance->Wrap(info.This());

      info.GetReturnValue().Set(info.This());
    }


      
    static void CastFrom(Nan::NAN_METHOD_ARGS_TYPE info) {
      HandleScope scope;
      if (info.Length() < 1 || !NodeRT::Utils::IsWinRtWrapperOf<::Windows::Media::Control::TimelinePropertiesChangedEventArgs^>(info[0])) {
        Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"Invalid arguments, no object provided, or given object could not be casted to requested type")));
        return;
      }

      ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ winRtInstance;
      try {
        winRtInstance = (::Windows::Media::Control::TimelinePropertiesChangedEventArgs^) NodeRT::Utils::GetObjectInstance(info[0]);
      } catch (Platform::Exception ^exception) {
        NodeRT::Utils::ThrowWinRtExceptionInJs(exception);
        return;
      }

      info.GetReturnValue().Set(WrapTimelinePropertiesChangedEventArgs(winRtInstance));
    }







    private:
      ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ _instance;
      static Persistent<FunctionTemplate> s_constructorTemplate;

      friend v8::Local<v8::Value> WrapTimelinePropertiesChangedEventArgs(::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ wintRtInstance);
      friend ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ UnwrapTimelinePropertiesChangedEventArgs(Local<Value> value);
  };

  Persistent<FunctionTemplate> TimelinePropertiesChangedEventArgs::s_constructorTemplate;

  v8::Local<v8::Value> WrapTimelinePropertiesChangedEventArgs(::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ winRtInstance) {
    EscapableHandleScope scope;

    if (winRtInstance == nullptr) {
      return scope.Escape(Undefined());
    }

    Local<Value> opaqueWrapper = CreateOpaqueWrapper(winRtInstance);
    Local<Value> args[] = {opaqueWrapper};
    Local<FunctionTemplate> localRef = Nan::New<FunctionTemplate>(TimelinePropertiesChangedEventArgs::s_constructorTemplate);
    return scope.Escape(Nan::NewInstance(Nan::GetFunction(localRef).ToLocalChecked(),_countof(args), args).ToLocalChecked());
  }

  ::Windows::Media::Control::TimelinePropertiesChangedEventArgs^ UnwrapTimelinePropertiesChangedEventArgs(Local<Value> value) {
     return TimelinePropertiesChangedEventArgs::Unwrap<TimelinePropertiesChangedEventArgs>(Nan::To<Object>(value).ToLocalChecked())->_instance;
  }

  void InitTimelinePropertiesChangedEventArgs(Local<Object> exports) {
    TimelinePropertiesChangedEventArgs::Init(exports);
  }


} } } } 

NAN_MODULE_INIT(init) {
  // We ignore failures for now since it probably means that
  // the initialization already happened for STA, and that's cool

  CoInitializeEx(nullptr, COINIT_MULTITHREADED);

  /*
  if (FAILED(CoInitializeEx(nullptr, COINIT_MULTITHREADED))) {
    Nan::ThrowError(Nan::Error(NodeRT::Utils::NewString(L"error in CoInitializeEx()")));
    return;
  }
  */

      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionPlaybackStatusEnum(target);
      NodeRT::Windows::Media::Control::InitCurrentSessionChangedEventArgs(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSession(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionManager(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionMediaProperties(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionPlaybackControls(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionPlaybackInfo(target);
      NodeRT::Windows::Media::Control::InitGlobalSystemMediaTransportControlsSessionTimelineProperties(target);
      NodeRT::Windows::Media::Control::InitMediaPropertiesChangedEventArgs(target);
      NodeRT::Windows::Media::Control::InitPlaybackInfoChangedEventArgs(target);
      NodeRT::Windows::Media::Control::InitSessionsChangedEventArgs(target);
      NodeRT::Windows::Media::Control::InitTimelinePropertiesChangedEventArgs(target);


  NodeRT::Utils::RegisterNameSpace("Windows.Media.Control", target);
}



NODE_MODULE(binding, init)
