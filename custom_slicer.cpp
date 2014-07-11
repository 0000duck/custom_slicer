#include <iostream>
#include "gcode.h"

int main(int argc, const char* argv[]){
  if(argc != 2)
    std::cout << "Please supply a starting width for pyramid\n"; 
  else
  {
    Gcode g = Gcode();
    //g.generate();
  }
}
