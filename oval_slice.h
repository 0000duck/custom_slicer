#include "slice.h"

class OvalSlice : public Slice{
public:
  OvalSlice(Printhead* ph, float x_c, float y_c, float radius, float t_interval);
  void generateOuterWall(int width);
private:
  float x_center;
  float y_center;
  float radius;
  float t_interval;
  int CIRCLE_POINTS;
  float OVAL_OFFSET;
};
