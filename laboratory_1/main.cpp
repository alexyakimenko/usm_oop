#include <iostream>
#include "Building.h"

int main() {
  std::string address = "st. Pervomaiskaya";
  std::string regNum = "23o42i34u32";

  Building build(4, 3, 2, address, regNum);
  std::cout << build.getAddress() << std::endl;

}
