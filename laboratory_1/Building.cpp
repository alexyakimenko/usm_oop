#include "Building.h"

Building::Building(int floorsNum, int roomsNum, int apartmentsNum, std::string address, std::string regNum) {
  this->floorsNum = floorsNum;
  this->roomsNum = roomsNum;
  this->apartmentsNum = apartmentsNum;
  this->address = address;
  this->regNum = regNum;
}

Building::Building() {
  this->floorsNum = 0;
  this->roomsNum = 0;
  this->apartmentsNum = 0;
  this->address = "No address";
  this->regNum = "undefined";
};

Building::~Building() {
  std::cout << "Building with regNum: " << regNum << " has been destroyed" << std::endl;
}

std::string Building::getAddress() {
  return this->address;
}

std::string Building::getRegNum() {
  return this->regNum;
}

int Building::getRoomsNum() {
  return this->roomsNum;
}

int Building::getFloorsNum() {
  return this->floorsNum;
}

int Building::getApartmentsNum() {
  return this->apartmentsNum;
}

void Building::print() {
  std::cout << "{" << std::endl;
  std::cout << "\taddress: " << this->getAddress() << std::endl; 
  std::cout << "\tregNum: " << this->getRegNum() << std::endl;
  std::cout << "\tfloorsNum: " << this->getFloorsNum() << std::endl;
  std::cout << "\tapartmentsNum: " << this->getApartmentsNum() << std::endl;
  std::cout << "\troomsNum: " << this->getRoomsNum() << std::endl;
  std::cout << "}" << std::endl;
}
