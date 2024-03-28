#pragma once

#include "Circle.h"

class Bowl : public Circle {
private: 
  double availableVolume = 0.9;
public:
  Bowl(double radius);
  double getVolume();
  double main();
  void display();
};
