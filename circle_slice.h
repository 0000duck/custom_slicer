#include <iostream>
#include <vector>
#include <string>

class CircleSlice{
public:
  CircleSlice(std::vector<std::string>* commands, float x_center, float y_center, float radius, float t_interval);
  void generateOuterWall(int* width);
private:
  void addCommand(float x, float y, float e, float z);

};
