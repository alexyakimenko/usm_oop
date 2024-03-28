#include <iostream>
#include "Point.h"

int Point::count = 0;

Point::Point() {
  this->id = ++Point::count;
}

void Point::display() {
  std::cout << "Object: " << this->id << std::endl;
}
