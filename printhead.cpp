#if !defined( PRINTHEAD_CPP )
#define PRINTHEAD_CPP

#include "printhead.h"

Printhead::Printhead(std::vector<std::string>* commands)
{
  _x = 0.0;
  _y = 0.0;
  _x = 0.0;
  _e = 0.0;
  _commands = commands;
  //E_COEF = 0.0329;
  LAYER_HEIGHT = 0.1;
  LINE_WIDTH = 0.3;
}

void Printhead::extrudeXYAxisTo(float x, float y)
{
  float d = sqrt(pow((_x - x), 2) + pow((_y - y), 2));
  _x = x;
  _y = y;
  _e += (d * LAYER_HEIGHT * LINE_WIDTH);
  std::stringstream ss;
  ss << "G1 F2000 X" << _x << " Y" << _y << " E" << _e << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}


void Printhead::extrudeXYZAxisTo(float x, float y, float z)
{

  float d = sqrt(pow((_x - x), 2) + pow((_y - y), 2));
  _x = x;
  _y = y;
  _z = z;
  _z = z;
  // extrusionPerMM = double(layerThickness) / 1000.0; this is really just 0.1
  // extrusionAmount += extrusionPerMM * double(lineWidth) / 1000.0 * vSizeMM(diff);
  // _e += 
  _e += (d * LAYER_HEIGHT * LINE_WIDTH);
  std::stringstream ss;
  ss << "G1 F2000 X" << _x << " Y" << _y << " Z" << _z  << " E" << _e << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}


void Printhead::moveAlongXYAxis(float x, float y)
{
  _x += x;
  _y += y;
  std::stringstream ss;
  ss << "G1 F2000 X" << _x << " Y" << _y << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}

void Printhead::extrudeAlongXYAxis(float x, float y)
{
  float d = sqrt(pow(x, 2) + pow(y,2));
  _x += x;
  _y += y;
  _e += (d * LAYER_HEIGHT * LINE_WIDTH);
  std::stringstream ss;
  ss << "G1 F2000 X" << _x << " Y" << _y << " E" << _e << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}

void Printhead::moveZAxis()
{
  _z += LAYER_HEIGHT;
  std::stringstream ss;
  ss << ";NEWLAYER\nG1 F1200 X" << _x << " Y" << _y << " Z" << _z << "\n";
  std::string s = ss.str();
  _commands->push_back(s);
}

#endif
