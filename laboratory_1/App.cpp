#include "App.h"

void App::addBuilding(Building building, bool insert) {
  if(!insert) {
    buildings.push_back(building);
    return;
  }

  buildings.insert(buildings.begin(), building);
}

void App::showByApps(int apartmentsNum) {
  for(Building building : buildings) {
    if(building.getApartmentsNum() <= apartmentsNum) continue;

    building.print();
  }
}

void App::deleteByAddress(std::string address) {
  for(int i = 0; i < buildings.size(); i++) {
    if(buildings[i].getAddress() != address) continue;

    buildings.erase(buildings.begin() + i);
  }
}

void App::showByRegNum(std::string regNum) {
  for(Building building : buildings) {
    if(building.getRegNum() != regNum) continue;

    building.print();
  }
}

void App::sortByFloors() {
  for(int i = 0; i < buildings.size()-1; i++) {
    int min_i = i;
    for(int j = i+1; j < buildings.size(); j++) {
      if(buildings[j].getFloorsNum() < buildings[min_i].getFloorsNum()) {
        min_i = j; 
      }
    }
    swap(buildings[i], buildings[min_i]);
  }
}

void App::writeFile() {
  ofstream output;

  output.open("buildings.out");

  for(Building building : buildings) {
    output << "{" << endl;
    output << "\taddress: " << building.getAddress() << endl;
    output << "\tregNum: " << building.getRegNum() << endl;
    output << "\tfloorsNum: " << building.getFloorsNum() << endl;
    output << "\troomsNum: " << building.getRoomsNum() << endl;
    output << "\tapartmentsNum: " << building.getApartmentsNum() << endl;
    output << "}" << endl;
  }
  
  output.close();
  cout << "File was successfully created" << endl;
}

App::App(Menu menu) {
  this->menu = menu; 
}

Menu App::getMenu() {
  return menu; 
}

void App::processAddBuilding(bool insert) {
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

  Building building(floorsNum, roomsNum, apartmentsNum, address, regNum);

  addBuilding(building, insert);
}

void App::processShowBuildings() {
  for(Building building : buildings) {
    building.print();
  }
}

void App::processShowByApps() {
  int apartmentsNum;
  cout << "Write the folowing info:" << endl;
  cout << "Number of apartments: ";
  cin >> apartmentsNum;
  showByApps(apartmentsNum);
}

void App::processDeleteByAddress() {
  string address;
  cout << "Write the folowing info:" << endl;
  cout << "Address of building: ";
  getline(cin>>ws, address);
  deleteByAddress(address);
}

void App::processShowByRegNum() {
  string regNum;
  cout << "Write the folowing info:" << endl;
  cout << "Registration Number: ";
  getline(cin>>ws, regNum);
  showByRegNum(regNum);
}

void App::processSortByFloors() {
  sortByFloors();
}

void App::processWriteFile() {
  writeFile();
}

void App::requestChoice() {
  short choice;
  cin >> choice;
  this->choice = choice;
}

void App::processChoice() {
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
      cout << "showing buildings with apartments greater than X" << endl;
      processShowByApps();
    }; break;
    case 4: {
      cout << "Inserting Building" << endl;
      processAddBuilding(true);
    }; break;
    case 5: {
      cout << "Deleting building ..." << endl;
      processDeleteByAddress();
    }; break;
    case 6: {
      cout << "Writing down Buildings" << endl;
      processWriteFile();
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

