#include "slice.h"

class CircleSlice : public Slice{
public:
  CircleSlice(Printhead* ph, float x_c, float y_c, float radius, float t_interval);
  void generateOuterWall(int width);
private:
  float x_center;
  float y_center;
  float radius;
  float t_interval;
  int CIRCLE_POINTS;
};
