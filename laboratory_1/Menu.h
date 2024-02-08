#include <vector>
class Menu {
private:
  std::vector<std::string> options;

public:
  Menu(std::string* options, int len);
  ~Menu();
  void setOptions(std::vector<std::string> newOptions);
  void addOption(std::string option);
  void draw();
};
