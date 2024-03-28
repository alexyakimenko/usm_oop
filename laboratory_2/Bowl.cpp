#include <cmath>
#include <iostream>

#include "Bowl.h"
#include "Circle.h"

Bowl::Bowl(double radius): Circle(radius) {}

double Bowl::getVolume() {
  double semisphereVolume = 2.0/3.0 * M_PI * pow(this->radius, 3);
  return semisphereVolume * this->availableVolume;
}

double Bowl::main() {
  return this->getVolume() / 2.0; 
}

void Bowl::display() {
  Circle::display();
  std::cout << "\tVolume: " << this->getVolume() << std::endl;
  std::cout << "\tHalved: " << this->main() << std::endl;
}
