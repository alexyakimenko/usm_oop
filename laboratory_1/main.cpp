#include <iostream>
#include <vector>

#include "Menu.h"
#include "App.h"

using namespace std;


int main() {
  string menuOptions[] = {
    "Add new Building",
    "Show list of buildings",
    "Sort list of buildings",
    "Show buildings with apps greater than x",
    "Add to first position",
    "Delete by address",
    "Write down buildings",
    "Show by regNum"
  };

  Menu menu(menuOptions, 8);
  App app;
  
  while(!app.shouldClose) {
    menu.draw();
    app.requestChoice();
    app.processChoice();
  }
}

