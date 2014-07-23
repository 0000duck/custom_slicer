#if !defined( PRINTHEAD_H )
#define PRINTHEAD_H

#include <vector>
#include <sstream>
#include <string>
#include <math.h>

class Printhead
{
public:
  Printhead(std::vector<std::string>* commands);
  void extrudeXYAxisTo(float x, float y);
  void extrudeXYZAxisTo(float x, float y, float z);
  void moveAlongXYAxis(float x, float y);
  void extrudeAlongXYAxis(float x, float y);
  void moveZAxis(float height);
private:
  float _x;
  float _y;
  float _z;
  float _e;
  float E_COEF;
  std::vector<std::string>* _commands;

};

#endif
