#include <iostream>
#include <vector>
#include <string>
#include "printhead.cpp"
#include <math.h>

class CircleSlice{
public:
  CircleSlice(Printhead* ph, float x_center, float y_center, float radius, float t_interval);
  void generateOuterWall(int width);
private:
  Printhead* _ph;
  std::vector<std::string>* commands;
  float x_center;
  float y_center;
  float radius;
  float t_interval;
  void addCommand(float x, float y, float e, float z);
  int CIRCLE_POINTS;
  float FILAMENT_WIDTH;
};
