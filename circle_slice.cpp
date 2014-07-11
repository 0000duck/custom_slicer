#include "circle_slice.h"

CircleSlice::CircleSlice(std::vector<std::string>* commands, float x_center, float y_center, float radius, float t_interval)
{
  std::cout << "Slice \n";
}

void CircleSlice::generateOuterWall(int* width)
{
  //
}

void CircleSlice::addCommand(float x, float y, float e = 0.0, float z = 0.0)
{

  //x_coord += x;
  //y_coord += y;
  //z_coord += z;
  //e_val   += e;

  //std::stringstream ss;

  //if(z == 0.0 && e == 0.0)
    //ss << "G1 F1200 X" << x_coord << " Y" << y_coord << "\n";
  //else if (z != 0.0)
    //ss << "G1 F9000 X" << x_coord << " Y" << y_coord << " Z" << z_coord  << "\n";
  //else if (e != 0.0)
    //ss << "G1 F1200 X" << x_coord << " Y" << y_coord << " E" << e_val << "\n";

  //std::string s = ss.str();
  //gcode->push_back(s);
}
