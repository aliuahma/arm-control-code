#include "vex.h"

using namespace vex;

brain Brain;

motor liftArm1 = motor(PORT1, ratio36_1, true);
motor liftArm2 = motor(PORT2, ratio36_1, true);
Arm arm = Arm(&liftArm1, &liftArm2, 1.0, 0.1);

void vexcodeInit(void) {
  // Nothing to initialize
}
