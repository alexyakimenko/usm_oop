#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

class Menu {
private:
  std::vector<std::string> options;

public:
  Menu(std::string* options, int len) {
    std::vector<std::string> newVec(options, options + len);
    this->options = newVec;
  };

  ~Menu() {
    options.clear();
  };

  void setOptions(std::vector<std::string> newOptions) {
    options = newOptions;
  };

  void addOption(std::string option) {
    options.push_back(option);
  };
  void draw() {
    std::cout << "Make Your Choice" << std::endl;
    for(int i = 0; i < options.size(); i++) {
      std::cout << i + 1 << ": " << options[i] << std::endl;
    }
  };
};

#endif // !MENU_H
