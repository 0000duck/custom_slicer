#include "circle_slice.h"

CircleSlice::CircleSlice(
    Printhead* ph,
    std::vector<std::string>* cmds,
    float x_c, 
    float y_c, 
    float r, 
    float t_int)
{
  std::cout << "Slice \n";
  _ph = ph;
  commands = cmds;
  x_center = x_c;
  y_center = y_c;
  radius = r;
  t_interval = t_int;
}

void CircleSlice::generateOuterWall(int* width)
{
  for(int* i = 0; i < width; i++){
    //
  }
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
