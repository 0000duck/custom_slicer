#include "printhead.h"

Printhead::Printhead(std::vector<std::string>* commands)
{
  _x = 0.0;
  _y = 0.0;
  _x = 0.0;
  _e = 0.0;
  _commands = commands;
}

void Printhead::moveXYAxisTo(float x, float y)
{
  _x = x;
  _y = y;
  _e += 0.5;
  std::stringstream ss;
  ss << "G1 F1200 X" << _x << " Y" << _y << " E" << _e << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}

void Printhead::moveZAxis(float height)
{
  _z += height;
  std::stringstream ss;
  ss << ";NEWLAYER\nG1 F1200 X" << _x << " Y" << _y << " Z" << _z << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}
