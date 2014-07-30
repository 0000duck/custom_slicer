#include "oval_slice.h"

OvalSlice::OvalSlice(
    Printhead* ph,
    //std::vector<std::string>* cmds,
    float x_c, 
    float y_c, 
    float r, 
    float t_int)
{
  //std::cout << "Slice radius " << radius << "\n";
  _ph = ph;
  //commands = cmds;
  x_center = x_c;
  y_center = y_c;
  radius = r;
  t_interval = t_int;
  CIRCLE_POINTS = 100;
  LINE_WIDTH = 0.3f;
  LAYER_HEIGHT = 0.1f;
  OVAL_OFFSET = 0.5f;
}

void OvalSlice::generateOuterWall(int width)
{
  //std::cout << "Generate OuterWall \n";
  //_ph->extrudeXYAxisTo(x_center, y_center);
  //

  //radius -= line_width * width;

  for(int i = 0; i < width; i++){
    double t = 0.0;
    double x = x_center + radius * cos(6.2832);
    double y = y_center + radius * sin(6.2832 + OVAL_OFFSET);
    _ph->extrudeXYAxisTo(x, y);
    for(int j=0; j<=CIRCLE_POINTS; j++)
    {
      //std::cout << radius << "\n";
      x = x_center + radius * cos(t);
      y = y_center + radius * sin(t + OVAL_OFFSET);
      t += t_interval;
      _ph->extrudeXYAxisTo(x, y);
    }
    //TODO FIX THIS HACK how much should it decrease by
    radius -= LINE_WIDTH;
    x -= LINE_WIDTH;
   //_ph->extrudeXYAxisTo(x, y);
  }
  _ph->moveZAxis();
}
