#include <RungWheelController.h>


RungWheelController dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
