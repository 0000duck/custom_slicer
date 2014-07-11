#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

float x_coord = 0.0;
float y_coord = 0.0;
float z_coord = 0.0;
float e_val = 0.0;
float current_width = 0.0;
const float layer_height = 0.1;
const float nozzle_width = 0.4;
const int inner_wall_width = 3;
const float e_coef = 0.0329;


void addCommand(std::vector<std::string> *gcode, float x, float y, float e = 0.0, float z = 0.0)
{

  x_coord += x;
  y_coord += y;
  z_coord += z;
  e_val   += e;

  std::stringstream ss;

  if(z == 0.0 && e == 0.0)
    ss << "G1 F1200 X" << x_coord << " Y" << y_coord << "\n";
  else if (z != 0.0)
    ss << "G1 F9000 X" << x_coord << " Y" << y_coord << " Z" << z_coord  << "\n";
  else if (e != 0.0)
    ss << "G1 F1200 X" << x_coord << " Y" << y_coord << " E" << e_val << "\n";

  std::string s = ss.str();
  gcode->push_back(s);
}

void appendFile(std::ofstream *output, const char* filename)
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

void writeToFile(std::vector<std::string> *gcode)
{
  std::cout << "Write to file \n";
  std::ofstream output;
  output.open ("custom_pyramid.gcode");

  appendFile(&output, "start_gcode.txt");

  for (std::vector<std::string>::iterator it = gcode->begin() ; it != gcode->end(); ++it)
    output << *it;

  appendFile(&output, "end_gcode.txt");

  output.close();
}

void addPyramidLayer(std::vector<std::string> *gcode)
{
  std::cout << "New Layer \n";
  float w = current_width;
  float e = 0.0;
  for(int i = 1; i <= inner_wall_width; i++)
  {
    e = w * e_coef;
    addCommand(gcode, w, 0, e);
    addCommand(gcode, 0.0, w, e);
    addCommand(gcode, -w, 0, e);
    addCommand(gcode, 0.0, -w, e);
    addCommand(gcode, nozzle_width, nozzle_width);
    w = w - (nozzle_width * 2);
  }
  addCommand(gcode, -(nozzle_width * inner_wall_width), -(nozzle_width * inner_wall_width));
}

void createPyramid(const char* argv[])
{
    std::cout << "Pyramid Starting Width " << argv[1] << " \n"; 
    current_width = atoi(argv[1]);
    std::vector<std::string> gcode;
    addCommand(&gcode, 50.0, 50.0, 0.0, 0.30);
    while(current_width > (nozzle_width * inner_wall_width * 4))
    {
      addPyramidLayer(&gcode);
      current_width = current_width - (nozzle_width * 2);
      addCommand(&gcode, nozzle_width, nozzle_width, 0.0, 0.10);
    }
    writeToFile(&gcode);
}

int main(int argc, const char* argv[]){
  if(argc != 2)
    std::cout << "Please supply a starting width for pyramid\n"; 
  else
    createPyramid(argv);
}
