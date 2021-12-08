#define KINECT_AZURE_ENABLE_BODY_TRACKING = 1
#define NAPI_VERSION 7

#include <stdlib.h>
#include <napi.h>
#include <k4a/k4a.hpp>

#include "exceptions.hpp"

Napi::Value MethodInit(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, true);
}

Napi::Value MethodOpen(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  int index = 0;

  if (info.Length() != 1 || !info[0].IsNumber())
  {
    Napi::InvalidEnvException::New(env).ThrowAsJavaScriptException();
    return;
  }

  index = info[0].ToNumber().Int32Value();

  try
  {
    k4a::device device = k4a::device::open(index);
  }
  catch (Napi::Error e)
  {
    return Napi::Boolean::New(env, false);
  }

  return Napi::Boolean::New(env, true);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "open"), Napi::Function::New(env, MethodOpen));

  return exports;
}

NODE_API_MODULE(hello, Init);