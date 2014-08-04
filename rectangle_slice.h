#include <iostream>
#include "slice.h"
#include <Eigen/Dense>

class RectangleSlice : public Slice{
public:
  RectangleSlice(Printhead* ph, float x_c, float y_c, float width, float length);
  void generateOuterWall(int wall_width);
  void generateOuterWall45(int wall_width);
  void moveToStartZ();
  void moveToStart();
  void moveToStart45();

private:
  float x_center;
  float y_center;
  float _width;
  float _length;
};
