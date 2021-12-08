#include <napi.h>
#include <k4a.hpp>

#include "DeviceService.cc"

DeviceService deviceService = DeviceService();

Napi::Value MethodOpen(Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  int index = 0;

  if (info.Length() == 1 && info[0].IsNumber())
  {
    index = info[0].ToNumber().Int32Value();
  }

  bool success = deviceService.open(index);

  return Napi::Boolean::New(env, success);
}

Napi::Value MethodGetCalibration(Napi::Env env)
{
  k4a::calibration calibration = deviceService.getCalibration();
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "open"), Napi::Function::New(env, MethodOpen));

  return exports;
}

NODE_API_MODULE(device, Init)