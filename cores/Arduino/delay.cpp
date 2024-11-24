#include <Windows.h>
#include <stdint.h>

namespace
{
uint64_t micros64()
{
  LARGE_INTEGER frequency, counter;
  if(!QueryPerformanceFrequency(&frequency) || !QueryPerformanceCounter(&counter))
  {
    return 0;
  }
  return static_cast<uint64_t>(counter.QuadPart * 1000000 / frequency.QuadPart);
}

static uint64_t s_start = micros64();

} // namespace

extern "C" {

  void yield(void)
  {
    Sleep(0);
  }

  unsigned long micros()
  {
    return static_cast<unsigned long>(micros64() - s_start);
  }

  unsigned long millis()
  {
    return static_cast<unsigned long>((micros64() - s_start) / 1000);
  }

  void delay(unsigned long ms)
  {
    if(ms == 0)
    {
      return;
    }

    uint32_t start = micros();

    while(ms > 0)
    {
      yield();
      while(ms > 0 && (micros() - start) >= 1000)
      {
        ms--;
        start += 1000;
      }
    }
  }

  void delayMicroseconds(unsigned int us)
  {
    if(us == 0)
    {
      return;
    }
    uint32_t start = micros();
    while(us > 0)
    {
      yield();
      while(us > 0 && (micros() - start) >= 1)
      {
        us--;
        start++;
      }
    }
  }

} // extern "C"
