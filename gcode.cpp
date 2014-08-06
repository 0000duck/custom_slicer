#include "gcode.h"

Gcode::Gcode(const char *filename, double ratio, int width, int layers)
{
  shape_filename = filename;
  inc_ratio = ratio;
  wall_width = width;
  no_layers = layers;
  //TODO FIX THIS HACK
  e_coef = 0.0229;
  commands.reserve(500000);
  ph = new Printhead(&commands);
}

bool Gcode::generate()
{
  std::cout << "Generating gcode...\n";
 
  //rectangles();
  cylinderFixes();

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

  appendFile(&output, "../gcode/start_gcode_um2.txt");

  for (std::vector<std::string>::iterator it = commands.begin() ; it != commands.end(); ++it)
    output << *it;

  appendFile(&output, "../gcode/end_gcode_um2.txt");

  output.close();
}


void Gcode::rectangles()
{

  float left = 40.0f;
  float center_h = 115.0f;
  float right = 180.0f;

  float top = 170.0f;
  float center_v = 115.0f;
  float bottom = 55.0f;


   inc_ratio = 0;

  // WALL WIDTH 4
  wall_width = 4;
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt4 = RaftSlice(ph, center_h, center_v, 90.0, 8);
  skirt4.moveToStartZ();
  skirt4.generateOuterWall();
  
  
  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    RectangleSlice rs = RectangleSlice(ph, center_h, center_v,  30.0, 80.0);
    rs.generateOuterWall45(wall_width);
  }

  //RaftSlice skirt5 = RaftSlice(ph, right, top, 90.0, 1);
  //skirt5.moveToStartZ();
  //skirt5.generateOuterWall();

  //wall_width = 6;

  //for(int i = 0; i < no_layers; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //RectangleSlice rs = RectangleSlice(ph, right, top, 30.0, 80.0);
    //rs.generateOuterWall(wall_width);
  //}



  //wall_width = 4;
  //std::cout << "Skirt \n";
  //commands.push_back(";SKIRT\n");
  //RaftSlice skirt6 = RaftSlice(ph, left, bottom, 90.0, 1);
  //skirt6.moveToStartZ();
  //skirt6.generateOuterWall();
  
  
  //for(int i = 0; i < no_layers; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //RectangleSlice rs = RectangleSlice(ph, left, bottom, 30.0, 80.0);
    //rs.generateOuterWall45(wall_width);
  //}

  //RaftSlice skirt8 = RaftSlice(ph, right, bottom, 90.0, 1);
  //skirt8.moveToStartZ();
  //skirt8.generateOuterWall();

  //wall_width = 6;

  //for(int i = 0; i < no_layers; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //RectangleSlice rs = RectangleSlice(ph, right, bottom, 30.0, 80.0);
    //rs.generateOuterWall45(wall_width);
  //}

}

void Gcode::cylinderFixes()
{
  float left = 40.0f;
  float center_h = 115.0f;
  float right = 180.0f;

  float top = 170.0f;
  float center_v = 115.0f;
  float bottom = 55.0f;

  inc_ratio = 0;

  //// WALL WIDTH 4
  wall_width = 2;
  double r = 30.0 + (30.0 * 0.05);
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt4 = RaftSlice(ph, center_h, center_v, 70.0, 8);
  skirt4.moveToStartZ();
  skirt4.generateOuterWall();

  for(int i = 0; i < 10; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph,  center_h, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }


  inc_ratio = 0.007;

  for(int i = 0; i < 40; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph,  center_h, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  for(int i = 0; i < 40; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph,  center_h, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r - inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }
    
  inc_ratio = 0.0;

  for(int i = 0; i < 10; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph,  center_h, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }


  //wall_width = 4;
  //r = 30.0;
  //std::cout << "Skirt \n";
  //commands.push_back(";SKIRT\n");
  //RaftSlice skirt5 = RaftSlice(ph, right, top, 70.0, 2);
  //skirt5.moveToStartZ();
  //skirt5.generateOuterWall();


  //inc_ratio = 0.05f;

  //for(int i = 0; i < 50; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, right, top, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r + inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}

  ////inc_ratio = 0.05f;

  //for(int i = 0; i < 50; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, right, top, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r - inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}



  //// WALL WIDTH 2
  //wall_width = 4;
  //r = 30.0;
  //std::cout << "Skirt \n";
  //commands.push_back(";SKIRT\n");
  //RaftSlice skirt3 = RaftSlice(ph, left, top, 70.0, 8);
  //skirt3.moveToStartZ();
  //skirt3.generateOuterWall();


  //inc_ratio = 0.01f;

  //for(int i = 0; i < 50; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, left, top, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r + inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}

  ////inc_ratio = 0.05f;

  //for(int i = 0; i < 50; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, left, top, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r - inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}


  //// WALL WIDTH 2
  //wall_width = 4;
  //r = 30.0;
  //std::cout << "Skirt \n";
  //commands.push_back(";SKIRT\n");
  //RaftSlice skirt = RaftSlice(ph, right, center_v, 70.0, 12);
  //skirt.moveToStartZ();
  //skirt.generateOuterWall();


  //inc_ratio = 0.01f;

  //for(int i = 0; i < 45; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, right, center_v, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r + inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}

  //for(int i = 0; i < 10; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, right, center_v, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}
  
  ////inc_ratio = 0.05f;

  //for(int i = 0; i < 45; i++)
  //{
    //std::cout << "Cone Layer " << i << "\n";
    //CircleSlice cs = CircleSlice(ph, right, center_v, r, 0.06283185);
    //cs.generateOuterWall(wall_width);
    //// THIS ALSO LOOKS COOL 
    ////r = r * inc_ratio;
    //r = r - inc_ratio;
    ////std::cout << "Ratio " << r << "\n";
  //}





}
