#pragma once
#include <vector>
#include "vex.h"

class Arm {

public:

  Arm(const std::vector<vex::motor*>& arms, float kP, float kD);
  ~Arm();
  void reset();
  void setAngle(float desiredAngle);
  static int armControlWrapper();

private:
  
  std::vector<vex::motor*> _arms;
  float _desiredAngle;
  float _kP;
  float _kD;
  static Arm* _instance;
  bool _stopTask;
  vex::task* _armTask;

}; // class Arm
