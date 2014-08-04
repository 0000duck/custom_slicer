#include "rectangle_slice.h"

RectangleSlice::RectangleSlice(
    Printhead* ph, 
    float x_c, 
    float y_c, 
    float width,
    float length)
{
  _ph = ph;
  x_center = x_c;
  y_center = y_c;
  _width = width;
  _length = length;
  LINE_WIDTH = 0.3f;
  LAYER_HEIGHT = 0.1f;
}

void RectangleSlice::generateOuterWall(int wall_width)
{
  moveToStart();
  _width -= (LINE_WIDTH * 2 * wall_width);
  _length -= (LINE_WIDTH * 2 * wall_width);
  for(int i = 0; i < wall_width; i++)
  {
    _ph->extrudeAlongXYAxis(0.0, _width);
    _ph->extrudeAlongXYAxis(-_length, 0.0);
    _ph->extrudeAlongXYAxis(0.0, -_width);
    _ph->extrudeAlongXYAxis(_length, 0.0);
    _ph->moveAlongXYAxis(LINE_WIDTH, -LINE_WIDTH);
    _width += (LINE_WIDTH * 2);
    _length += (LINE_WIDTH * 2);

  }
  _ph->moveZAxis();
}


void RectangleSlice::generateOuterWall45(int wall_width)
{
  
  Eigen::Rotation2D<float> R(0.7854);

  Eigen::Vector2f p0((LINE_WIDTH * 2 * wall_width), (LINE_WIDTH * 2 * wall_width));
  p0 = R * p0;

  
  moveToStart45();
  _width -= p0(0);
  _length -= p0(1);
  for(int i = 0; i < wall_width; i++)
  {
    Eigen::Vector2f p1(0.0, _width);
    Eigen::Vector2f p2(-_length, 0.0);
    Eigen::Vector2f p3(0.0, -_width);
    Eigen::Vector2f p4(_length, 0.0);

    Eigen::Vector2f p5(LINE_WIDTH, -LINE_WIDTH);
    Eigen::Vector2f p6((LINE_WIDTH * 2), (LINE_WIDTH * 2));
    
    
    p1 = R * p1;
    p2 = R * p2;
    p3 = R * p3;
    p4 = R * p4;
    p5 = R * p5;
    p6 = R * p6;

    _ph->extrudeAlongXYAxis(p1(0), p1(1));
    _ph->extrudeAlongXYAxis(p2(0), p2(1));
    _ph->extrudeAlongXYAxis(p3(0), p3(1));
    _ph->extrudeAlongXYAxis(p4(0), p4(1));
    _ph->moveAlongXYAxis(p5(0), p5(1));
    _width += p6(0);
    _length += p6(0);

  }
  _ph->moveZAxis();
}


void RectangleSlice::moveToStart()
{
  double x = x_center + (_length / 2);
  double y = y_center - (_width / 2);
  _ph->extrudeXYAxisTo(x, y);
}

void RectangleSlice::moveToStart45()
{
  //Eigen::Rotation2D<float> R(0.7854);

  //Eigen::Vector2f p0(((_length / 2)), (_width / 2));
  //p0 = R * p0;
  
  //double x = x_center + p0(0);
  //double y = y_center - p0(1);
  //_ph->extrudeXYAxisTo(x, y);
  double x = x_center + (_length / 2);
  double y = y_center - (_width / 2) + 30.0;
  _ph->extrudeXYAxisTo(x, y);
}


void RectangleSlice::moveToStartZ()
{
  double x = x_center + (_length / 2);
  double y = y_center - (_width / 2);
  _ph->extrudeXYZAxisTo(x, y, 0.1);
}


