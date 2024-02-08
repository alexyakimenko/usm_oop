#include <iostream>
#include <vector>

#include "Menu.h"

Menu::Menu(std::string* options, int len) {
  std::vector<std::string> newVec(options, options + len);
  this->options = newVec;
}

Menu::~Menu() {
  options.clear();
}

void Menu::setOptions(std::vector<std::string> newOptions) {
  options = newOptions;
}

void Menu::addOption(std::string option) {
  options.push_back(option);
}

void Menu::draw() {
  std::cout << "Make Your Choice" << std::endl;
  for(int i = 0; i < options.size(); i++) {
    std::cout << i + 1 << ": " << options[i] << std::endl;
  }
}
