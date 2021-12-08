#include <k4a.hpp>

using namespace std;

class DeviceService
{
private:
  k4a::device device;

  k4a_depth_mode_t depthMode;
  k4a_color_resolution_t colorResolution;

public:
  const k4a::device &getDevice()
  {
    return device;
  }

  bool open(int index)
  {
    try
    {
      device = k4a::device::open(index);
    }
    catch (exception e)
    {
      return false;
    }

    return true;
  }

  k4a::calibration getCalibration()
  {
    k4a::calibration calibration = device.get_calibration(depthMode, colorResolution);
    return calibration;
  }
};