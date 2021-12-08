#include <napi.h>
#include <k4a.hpp>

Napi::Value foo(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  Napi::Int32Array::New(env, (size_t)10, a);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
}