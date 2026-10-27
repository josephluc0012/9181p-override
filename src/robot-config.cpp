#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
controller Controller;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor Left1 = motor(PORT1, ratio6_1, true);
motor Left2 = motor(PORT8, ratio18_1, true); //5.5
motor Left3 = motor(PORT3, ratio6_1, false);
motor Right1 = motor(PORT4, ratio6_1, false);
motor Right2 = motor(PORT5, ratio18_1, true); //5.5
motor Right3 = motor(PORT7, ratio6_1, false);

motor LiftLeft = motor(PORT19, ratio6_1, false);
motor LiftRight = motor(PORT20, ratio6_1, true);

motor Chainbar = motor(PORT15, ratio18_1, false);
motor Intake = motor(PORT10, ratio18_1, false);

void vexcodeInit( void ) {
  // nothing to initialize
}