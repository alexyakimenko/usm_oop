#pragma once
#include "Point.h"

class Circle : public Point {
protected:
  double radius;
public:
  Circle(double radius);
  double getLength();
  void display();
};
