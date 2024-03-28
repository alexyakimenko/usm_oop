#include <iostream>
#include <cmath>
#include <typeinfo>

#include "Circle.h"
#include "Point.h"

Circle::Circle(double radius): radius(radius) {
}

double Circle::getLength() {
  return 2 * M_PI * this->radius;
}

void Circle::display() {
  Point::display();
  std::cout << "\tRadius: " << this->radius << std::endl;
  std::cout << "\tLength: " << this->getLength() << std::endl;
}
