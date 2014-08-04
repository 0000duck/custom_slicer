  // WALL WIDTH 2
  wall_width = 2;
  double r = 30.0;
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt = RaftSlice(ph, left, top, 70.0, 8);
  skirt.moveToStartZ();
  skirt.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, left, top, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 20.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt2 = RaftSlice(ph, center_h, top, 50.0, 8);
  skirt2.moveToStartZ();
  skirt2.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, center_h, top, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 10.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt3 = RaftSlice(ph, right, top, 30.0, 8);
  skirt3.moveToStartZ();
  skirt3.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, right, top, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }




  // WALL WIDTH 4
  wall_width = 4;
  r = 30.0;
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt4 = RaftSlice(ph, left, center_v, 70.0, 8);
  skirt4.moveToStartZ();
  skirt4.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, left, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 20.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt5 = RaftSlice(ph, center_h, center_v, 50.0, 2);
  skirt5.moveToStartZ();
  skirt5.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, center_h, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 10.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt6 = RaftSlice(ph, right, center_v, 30.0, 8);
  skirt6.moveToStartZ();
  skirt6.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, right, center_v, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }



  // WALL WIDTH 6
  wall_width = 6;
  r = 30.0;
  //std::cout << "Skirt \n";
  //commands.push_back(";SKIRT\n");
  //RaftSlice skirt7 = RaftSlice(ph, left, bottom, 70.0, 2);
  //skirt7.moveToStartZ();
  //skirt7.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, left, bottom, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 20.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt8 = RaftSlice(ph, center_h, bottom, 50.0, 8);
  skirt8.moveToStartZ();
  skirt8.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, center_h, bottom, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }

  r = 10.0;
  commands.push_back(";SKIRT\n");
  RaftSlice skirt9 = RaftSlice(ph, right, bottom, 30.0, 8);
  skirt9.moveToStartZ();
  skirt9.generateOuterWall();

  for(int i = 0; i < no_layers; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, right, bottom, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }


