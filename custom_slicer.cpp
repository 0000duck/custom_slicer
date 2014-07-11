#include <iostream>
#include "gcode.cpp"

int main(int argc, const char* argv[]){
  if(argc != 5)
    std::cout << "Please supply a bitmap shape location, increase ratio, wall width and no. layers \n"; 
  else
  {
    const char* filename = argv[1];
    float inc_ratio = atoi(argv[2]);
    int wall_width = atoi(argv[3]);
    int no_layers = atoi(argv[4]);
    Gcode g = Gcode(filename, inc_ratio, &wall_width, &no_layers);
    g.generate();
  }
}
