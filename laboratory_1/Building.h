#include <iostream>

class Building {
private:
    int floorsNum;
    int roomsNum;
    int apartmentsNum;
    std::string address;
    std::string regNum;
public:
  Building(int floorsNum, int roomsNum, int apartmentsNum, std::string address, std::string regNum);
  Building();
  ~Building();
  int getFloorsNum();
  int getRoomsNum();
  int getApartmentsNum();
  std::string getAddress();
};
