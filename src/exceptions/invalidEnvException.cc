#include <napi.h>

namespace Napi
{
  class InvalidEnvException : Napi::Error
  {
  public:
    static Napi::Error New(Napi::Env env)
    {
      return Napi::Error::New(env, "INVALID_ENV");
    }
  };
}
