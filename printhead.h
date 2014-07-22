#include <vector>
#include <sstream>
#include <string>

class Printhead
{
public:
  Printhead(std::vector<std::string>* commands);
  void moveXYAxisTo(float x, float y);
  void moveZAxis(float height);
private:
  float _x;
  float _y;
  float _z;
  float _e;
  std::vector<std::string>* _commands;

};
