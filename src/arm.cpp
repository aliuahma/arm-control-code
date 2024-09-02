#include "arm.h"

Arm* Arm::_instance = nullptr;

Arm(const std::vector<vex::motor*>& arms, float kP, float kD) {
  _arms = arms;
  _desiredAngle = 0.0; // default state
  _kP = kP;
  _kD = kD;
  _instance = this;
  _stopTask = false;
  _armTask = new vex::task(armControlWrapper);
  currentAngle = 0.0 // initial state
} 

Arm::~Arm() {
  _stopTask = true;
  _armTask->stop();
  delete _armTask;
}

void Arm::setAngle(float desiredAngle) {
  _desiredAngle = desiredAngle;
} 

int Arm::armControl() {
  float lastError = 0;
  while(!_stopTask) {
    for (auto arm : _arms) {
      currentAngle += arm->position(deg);
    }
    currentAngle /= _arms.size();
    float error = _desiredAngle - currentAngle;
    float derivative = error - lastError;
    float armPower = error * _kP + derivative * _kD;
    for (auto arm : _arms) {
      arm->spin(vex::directionType::fwd, armPower, vex::voltageUnits::mV);
    }
    lastError = error;
    vex::task::sleep(10);
  }
  for (auto arm : _arms) {
    arm->setBrake(brake);
  }
  return 1;
} 

int Arm::armControlWrapper() {
  return _instance->armControl();  
}
