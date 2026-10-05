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
motor Left2 = motor(PORT8, ratio6_1, true);
motor Left3 = motor(PORT3, ratio6_1, false);
motor Right1 = motor(PORT4, ratio6_1, false);
motor Right2 = motor(PORT5, ratio6_1, true);
motor Right3 = motor(PORT7, ratio6_1, false);

motor Intake1 = motor(PORT10, ratio6_1, false);
motor Intake2 = motor(PORT11, ratio6_1, false);

pneumatics MatchLoader = pneumatics(Brain.ThreeWirePort.A);
pneumatics Wing = pneumatics(Brain.ThreeWirePort.F);
pneumatics triplestate1 = pneumatics(Brain.ThreeWirePort.D);
pneumatics triplestate2 = pneumatics(Brain.ThreeWirePort.H);

void vexcodeInit( void ) {
  // nothing to initialize
}