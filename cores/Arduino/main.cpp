#include "Arduino.h"

// The following code is the default main function for Arduino sketches.
// If you want to use the Arduino API in your own main function, you can
// copy this code and modify it as needed.
int default_main()
{
  init();
  setup();
  for(;;)
  {
    loop();
    yield();
  }
  return 0;
}

