#include "raft_slice.h"


RaftSlice::RaftSlice(
    Printhead* ph, 
    float x_c, 
    float y_c, 
    float width, 
    int wall_width)
{
  _ph = ph;
  x_center = x_c;
  y_center = y_c;
  _width = width;
  _wall_width = wall_width;
  LINE_WIDTH = 0.3f;
  LAYER_HEIGHT = 0.1f;
}

void RaftSlice::generate()
{
  moveToStart();
  generateOuterWall();
  generateFill();
  _ph->moveZAxis();
}

void RaftSlice::moveToStart()
{
  double x = x_center + (_width / 2);
  double y = y_center - (_width / 2);
  _ph->extrudeXYAxisTo(x, y);
}

void RaftSlice::moveToStartZ()
{
  double x = x_center + (_width / 2);
  double y = y_center - (_width / 2);
  _ph->extrudeXYZAxisTo(x, y, 0.1);
}


void RaftSlice::generateOuterWall()
{
  for(int i = 0; i < _wall_width; i++)
  {
    _ph->extrudeAlongXYAxis(0.0, _width);
    _ph->extrudeAlongXYAxis(-_width, 0.0);
    _ph->extrudeAlongXYAxis(0.0, -_width);
    _ph->extrudeAlongXYAxis(_width, 0.0);
    _ph->moveAlongXYAxis(-LINE_WIDTH, LINE_WIDTH);
    _width -= (LINE_WIDTH * 2);
  }
}

void RaftSlice::generateFill()
{
  int line_count = (_width / LINE_WIDTH) / 2;
  for(int i = 0; i <= line_count; i++)
  {
    _ph->extrudeAlongXYAxis(0.0, _width);
    _ph->moveAlongXYAxis(-LINE_WIDTH, 0.0);
    _ph->extrudeAlongXYAxis(0.0, -_width);
    _ph->moveAlongXYAxis(-LINE_WIDTH, 0.0);
  }
}
