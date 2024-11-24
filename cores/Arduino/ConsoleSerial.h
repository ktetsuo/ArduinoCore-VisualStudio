#pragma once
#include <HardwareSerial.h>

namespace arduino
{
class ConsoleSerial : public HardwareSerial
{
  int _lastKey = -1;
public:
  ConsoleSerial();
  ~ConsoleSerial();
  void begin(unsigned long baud) override;
  void begin(unsigned long baudrate, uint16_t config) override;
  void end() override;
  int available(void) override;
  int peek(void) override;
  int read(void) override;
  void flush(void) override;
  size_t write(uint8_t c) override;
  size_t write(const uint8_t* buffer, size_t size) override;
  int availableForWrite() override;
  operator bool() override { return true; }
};

extern ConsoleSerial Serial;
}
