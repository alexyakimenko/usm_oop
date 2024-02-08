#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

class Building {
private:
    int floorsNum;
    int roomsNum;
    int apartmentsNum;
    std::string address;
    std::string regNum;

public:
  Building(int floorsNum, int roomsNum, int apartmentsNum, std::string address, std::string regNum) {
    this->floorsNum = floorsNum;
    this->roomsNum = roomsNum;
    this->apartmentsNum = apartmentsNum;
    this->address = address;
    this->regNum = regNum;
  }

  Building() {
    this->floorsNum = 0;
    this->roomsNum = 0;
    this->apartmentsNum = 0;
    this->address = "No address";
    this->regNum = "undefined";
  }

  ~Building() {
    std::cout << "Building with regNum: " << regNum << " has been destroyed" << std::endl;
  }

  int getFloorsNum() {
    return this->floorsNum;
  }

  int getRoomsNum() {
    return this->roomsNum;
  }

  int getApartmentsNum() {
    return this->apartmentsNum;
  }

  std::string getAddress() {
    return this->address;
  }

  std::string getRegNum() {
    return this->regNum;
  }

  void print() {
    std::cout << "{" << std::endl;
    std::cout << "\taddress: " << this->getAddress() << std::endl; 
    std::cout << "\tregNum: " << this->getRegNum() << std::endl;
    std::cout << "\tfloorsNum: " << this->getFloorsNum() << std::endl;
    std::cout << "\tapartmentsNum: " << this->getApartmentsNum() << std::endl;
    std::cout << "\troomsNum: " << this->getRoomsNum() << std::endl;
    std::cout << "}" << std::endl;
  }
};

#endif // BUILDING_H!
