#include "gcode.h"

Gcode::Gcode(const char *filename, float ratio, int *width, int *layers)
{
  shape_filename = filename;
  inc_ratio = ratio;
  wall_width = width;
  no_layers = layers;
  e_coef = 0.0329;
  ph = new Printhead();
}

bool Gcode::generate()
{
  std::cout << "Generating gcode...\n";
  float r = 10.0f;

  for(int* i = 0; i < no_layers; i++)
  {
    CircleSlice cs = CircleSlice(ph, &commands, 100.0, 100.0, r, 0.5);
    cs.generateOuterWall(wall_width);
    r = r * inc_ratio;
  }
  writeToFile();
  return true;
}

void Gcode::appendFile(std::ofstream *output, const char* filename)
{
  std::string line;
  std::ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      *output << line << "\n";
    }
    myfile.close();
  }
}

void Gcode::writeToFile()
{
  std::ofstream output;
  output.open ("../gcode/output.gcode");

  appendFile(&output, "../gcode/start_gcode.txt");

  for (std::vector<std::string>::iterator it = commands.begin() ; it != commands.end(); ++it)
    output << *it;

  appendFile(&output, "../gcode/end_gcode.txt");

  output.close();
}

