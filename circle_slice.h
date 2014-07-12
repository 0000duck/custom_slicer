#include <iostream>
#include <vector>
#include <string>
#include "printhead.cpp"

class CircleSlice{
public:
  CircleSlice(Printhead* ph, std::vector<std::string>* cmds, float x_center, float y_center, float radius, float t_interval);
  void generateOuterWall(int* width);
private:
  Printhead* _ph;
  std::vector<std::string>* commands;
  float x_center;
  float y_center;
  float radius;
  float t_interval;
  void addCommand(float x, float y, float e, float z);

};
