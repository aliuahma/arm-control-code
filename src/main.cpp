#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
  arm.reset();
}

void autonomous(void) {
  arm.setAngle(90);
  wait(2000, msec);
  arm.setAngle(0);
}

void usercontrol(void) {
  controller.ButtonA.pressed(arm.setAngle(90));
  controller.ButtonB.pressed(arm.setAngle(0));
  while (1) {
    wait(20, msec); 
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
