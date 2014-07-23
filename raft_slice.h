#include <iostream>
#include "slice.h"

class RaftSlice : public Slice{
public:
  RaftSlice(Printhead* ph, float x_c, float y_c, float width, int wall_width);
  void generateOuterWall();
  void generateFill();
  void generate();
  void moveToStart();
  void moveToStartZ();
private:
  float x_center;
  float y_center;
  float _width;
  int _wall_width;
};
