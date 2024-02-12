#pragma once

#include <vector>
#include <fstream>

#include "Building.h"
#include "Menu.h"

using namespace std;

class App {
private:
  short choice;
  std::vector<Building> buildings;
  Menu menu;

  void addBuilding(Building building, bool insert = false);
  void showByApps(int apartmentsNum); 
  void deleteByAddress(std::string address); 
  void showByRegNum(std::string regNum); 
  void sortByFloors();
  void writeFile(); 

public:
  bool shouldClose = false;

  App(Menu menu); 
  Menu getMenu(); 
  void processAddBuilding(bool insert = false); 
  void processShowBuildings(); 
  void processShowByApps(); 
  void processDeleteByAddress(); 
  void processShowByRegNum(); 
  void processSortByFloors(); 
  void processWriteFile(); 
  void requestChoice(); 
  void processChoice();
};

