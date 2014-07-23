#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "circle_slice.cpp"
#include "raft_slice.cpp"

class Gcode
{
public:
  Gcode(const char *filename, double inc_ratio, int wall_width, int no_layers);
  bool generate();

private:
  const char* shape_filename;
  double inc_ratio;
  int wall_width;
  int no_layers;
  float e_coef;
  Printhead* ph;
  std::vector<std::string> commands;
  void appendFile(std::ofstream *output, const char* filename);
  void writeToFile();
};
