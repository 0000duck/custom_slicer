#include <iostream>
#include <vector>
#include <string>
#include "printhead.cpp"
#include <math.h>

class RaftSlice{
public:
  RaftSlice(Printhead* ph, float x_c, float y_c, float width, int wall_width);
  void generateOuterWall();
  void generateFill();
  void generate();
private:
  Printhead* _ph;
  std::vector<std::string>* commands;
  float x_center;
  float y_center;
  float _width;
  int _wall_width;
};
