#include "ConsoleSerial.h"

#include <conio.h>

namespace arduino
{
ConsoleSerial::ConsoleSerial()
{
}
ConsoleSerial::~ConsoleSerial()
{
}
void ConsoleSerial::begin(unsigned long baud)
{
  // baud is ignored
}
void ConsoleSerial::begin(unsigned long baudrate, uint16_t config)
{
  // baudrate and config are ignored
}
void ConsoleSerial::end()
{
}
int ConsoleSerial::available(void)
{
  if(_lastKey != -1)
  {
    return 1;
  }
  if(_kbhit() != 0)
  {
    return 1;
  }
  return 0;
}
int ConsoleSerial::peek(void)
{
  if(_lastKey != -1)
  {
    return _lastKey;
  }
  if(_kbhit() != 0)
  {
    _lastKey = _getch();
    return _lastKey;
  }
  return -1;
}
int ConsoleSerial::read(void)
{
  if(_lastKey != -1)
  {
    const int key = _lastKey;
    _lastKey = -1;
    return key;
  }
  if(_kbhit() != 0)
  {
    return _getch();
  }
  return -1;
}
void ConsoleSerial::flush(void)
{
}
size_t ConsoleSerial::write(uint8_t c)
{
  putchar(c);
  return 1;
}

size_t ConsoleSerial::write(const uint8_t* buffer, size_t size)
{
  fwrite(buffer, sizeof(*buffer), size, stdout);
  return size;
}
int ConsoleSerial::availableForWrite()
{
  return INT_MAX;
}

ConsoleSerial Serial;
}
