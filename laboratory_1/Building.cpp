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

int Building::getRoomsNum() {
  return this->roomsNum;
}

int Building::getFloorsNum() {
  return this->floorsNum;
}

int Building::getApartmentsNum() {
  return this->apartmentsNum;
}
