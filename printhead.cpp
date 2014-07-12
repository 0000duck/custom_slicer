#include "printhead.h"

Printhead::Printhead()
{
  _x = 0.0;
  _y = 0.0;
  _e = 0.0;

}

void Printhead::setPosition(float x, float y, float e)
{
  _x = x;
  _y = y;
  _e = e;
}
