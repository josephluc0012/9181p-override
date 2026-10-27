#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
controller Controller;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor Left1 = motor(PORT12, ratio6_1, true);
motor Left2 = motor(PORT13, ratio18_1, true); //5.5
motor Left3 = motor(PORT11, ratio6_1, false);
motor Right1 = motor(PORT5, ratio6_1, false);
motor Right2 = motor(PORT8, ratio18_1, true); //5.5
motor Right3 = motor(PORT10, ratio6_1, false);

motor LiftLeft = motor(PORT18, ratio6_1, false)
motor LiftRight = motor(PORT20, ratio6_1, false)

motor Chainbar = motor(PORT15, ratio18_1, false)

void vexcodeInit( void ) {
  // nothing to initialize
}