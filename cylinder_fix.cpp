 inc_ratio = 0;

  // WALL WIDTH 4
  wall_width = 4;
  double r = 30.0;
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt4 = RaftSlice(ph, left, top, 70.0, 8);
  skirt4.moveToStartZ();
  skirt4.generateOuterWall();

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


  // WALL WIDTH 2
  wall_width = 4;
  r = 30.0;
  std::cout << "Skirt \n";
  commands.push_back(";SKIRT\n");
  RaftSlice skirt = RaftSlice(ph, right, bottom, 70.0, 8);
  skirt.moveToStartZ();
  skirt.generateOuterWall();


  inc_ratio = 0.05f;

  for(int i = 0; i < 50; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, right, bottom, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }


  inc_ratio = -0.005f;

  for(int i = 0; i < 50; i++)
  {
    std::cout << "Cone Layer " << i << "\n";
    CircleSlice cs = CircleSlice(ph, right, bottom, r, 0.06283185);
    cs.generateOuterWall(wall_width);
    // THIS ALSO LOOKS COOL 
    //r = r * inc_ratio;
    r = r + inc_ratio;
    //std::cout << "Ratio " << r << "\n";
  }


