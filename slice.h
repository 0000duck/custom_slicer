#if !defined( SLICE_H )
#define SLICE_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "printhead.cpp"

class Slice
{
protected:
  Printhead* _ph;
  std::vector<std::string>* commands;
  float LINE_WIDTH;
  float LAYER_HEIGHT;

};


#endif
