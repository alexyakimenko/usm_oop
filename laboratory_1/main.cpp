#include <iostream>
#include <vector>

#include "Building.h"
#include "Menu.h"

using namespace std;


class App {
private:
  short choice;
  vector<Building> buildings;

  void addBuilding(Building building) {
    buildings.push_back(building);
  }

  void addBuilding(int floorsNum, int roomsNum, int apartmentsNum, string address, string regNum) {
    Building building(floorsNum, roomsNum, apartmentsNum, address, regNum);
    buildings.push_back(building);
  }

  void showByApps(int apartmentsNum) {
    for(Building building : buildings) {
      if(building.getApartmentsNum() <= apartmentsNum) continue;

      building.print();
    }
  }
  
  void deleteByAddress(string address) {
    for(int i = 0; i < buildings.size(); i++) {
      if(buildings[i].getAddress() != address) continue;

      buildings.erase(buildings.begin() + i);
    }
  }

  void showByRegNum(string regNum) {
    for(Building building : buildings) {
      if(building.getRegNum() != regNum) continue;

      building.print();
    }
  }

  static bool compare(Building& b1, Building& b2) {
      return b1.getRoomsNum() > b2.getFloorsNum();
  }

  void sortByFloors() {
    sort(buildings.begin(), buildings.end(), compare);
  }

public:
  bool shouldClose = false;

  void processAddBuilding() {
    int floorsNum, roomsNum, apartmentsNum;
    string address, regNum;

    cout << "Write the folowing info:" << endl;
    cout << "Nubmber of floors: ";
    cin >> floorsNum;
    cout << "Number of rooms: ";
    cin >> roomsNum;
    cout << "Number of apartments: ";
    cin >> apartmentsNum;
    cout << "Address of building: \n";
    getline(cin>>ws, address, '\n');
    cout << "Registration number: \n";
    getline(cin>>ws, regNum, '\n');
  

    addBuilding(floorsNum, roomsNum, apartmentsNum, address, regNum);
  }

  void processShowBuildings() {
    for(Building building : buildings) {
      building.print();
    }
  }

  void processShowByApps() {
    int apartmentsNum;
    cout << "Write the folowing info:" << endl;
    cout << "Number of apartments: ";
    cin >> apartmentsNum;
    showByApps(apartmentsNum);
  }

  void processDeleteByAddress() {
    string address;
    cout << "Write the folowing info:" << endl;
    cout << "Address of building: ";
    getline(cin>>ws, address);
    deleteByAddress(address);
  }

  void processShowByRegNum() {
    string regNum;
    cout << "Write the folowing info:" << endl;
    cout << "Registration Number: ";
    getline(cin>>ws, regNum);
    showByRegNum(regNum);
  }

  void processSortByFloors() {
    sortByFloors();
  }

  void requestChoice() {
    short choice;
    cin >> choice;
    this->choice = choice;
  }

  void processChoice() {
    switch(choice-1) {
      case 0: {
        cout << "Adding new Building..." << endl;
        processAddBuilding();
      }; break;
      case 1: {
        cout << "Showing list of Buildings..." << endl;
        processShowBuildings(); 
      }; break;
      case 2: {
        cout << "Sorting list of Buildings..." << endl;
        processSortByFloors();
      }; break;
      case 3: {
        cout << "Showing buildings with apartments greater than X" << endl;
        processShowByApps();
      }; break;
      case 4: {
        
      }; break;
      case 5: {
        cout << "Deleting building ..." << endl;
        processDeleteByAddress();
      }; break;
      case 6: {

      }; break;
      case 7: {
        cout << "Showing by Registration Number" << endl;
        processShowByRegNum();
      }; break;
      default: {
        shouldClose = true;
        cout << "Closing app ..." << endl;
      }
    }
  }


};

int main() {
  string menuOptions[] = {
    "Add new Building",
    "Show list of buildings",
    "Sort list of buildings",
    "Show buildings with apps greater than x",
    "<to be clarified>",
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

