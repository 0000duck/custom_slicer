#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "circle_slice.cpp"

class Gcode
{
public:
  Gcode(const char *filename, float inc_ratio, int *wall_width, int *no_layers);
  bool generate();

private:
  const char* shape_filename;
  float inc_ratio;
  int* wall_width;
  int* no_layers;
  float e_coef;
  std::vector<std::string> commands;
  void appendFile(std::ofstream *output, const char* filename);
  void writeToFile();

};