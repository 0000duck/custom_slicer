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
}

void RaftSlice::generate()
{
  generateOuterWall();
  generateOuterWall();
  _ph->moveZAxis(0.4);
}

void RaftSlice::generateOuterWall()
{
  for(int i = 0; i < _wall_width; i++)
  {
    //
  }
}

void RaftSlice::generateFill()
{

}
