#include "gcode.h"

Gcode::Gcode(const char *filename, double ratio, int width, int layers)
{
  shape_filename = filename;
  inc_ratio = ratio;
  wall_width = width;
  no_layers = layers;
  e_coef = 0.0329;
  ph = new Printhead(&commands);
}

bool Gcode::generate()
{
  std::cout << "Generating gcode...\n";
  double r = 20.0;

  for(int i = 0; i < 4; i++)
  {
    std::cout << "Raft " << i << "\n";
    RaftSlice rs = RafeSlice(ph, 100, 100, 40.0, wall_width);
    rs.generate();
  }

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, 100.0, 100.0, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL r = r * inc_ratio;
    r = r + inc_ratio;
    std::cout << "Ratio " << r << "\n";
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

