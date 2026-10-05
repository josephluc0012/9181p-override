#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.set_coordinates(0,0,0);
  chassis.drive_to_point(0,10);

}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}
void left_rush(){
chassis.set_coordinates(62.064, -16.733, 270);
chassis.turn_to_point(22.545, -23.239, 0, 10, 1.5, 150, 250);
Intake1.spin(forward, 100, velocityUnits::pct);
Intake2.spin(reverse, 100, velocityUnits::pct);
chassis.drive_to_point(29.798, -21.937, 0, 10, 12, 1.5, 150, 1000);
MatchLoader.set(true);
chassis.drive_to_point(21.684 , -22.444, 0, 10, 12, 1.5, 150, 300);
chassis.turn_to_point(44.504, -49.068, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(44.504, -49.068, 0, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(63.774, -47, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(63.774, -47, 0, 10, 12, 1.5, 150, 1000);
wait(0.1, sec);
chassis.turn_to_point(25.234, -47, 180, 10, 1.5, 150, 1000);
chassis.drive_to_point(25.234, -47, 0, 10, 12, 1.5, 150, 1000);
triplestate1.set(true);
triplestate2.set(false);
wait(1.9, sec);
MatchLoader.set(false);
chassis.drive_distance(10);
chassis.drive_distance(-10);
}
void right_rush(){
chassis.set_coordinates(62.064,16.733,270);
chassis.turn_to_point(22.545, 23.239, 0, 10, 1.5, 150, 250);
Intake1.spin(forward, 100, velocityUnits::pct);
Intake2.spin(reverse, 100, velocityUnits::pct);
chassis.drive_to_point(29.798, 21.937, 0, 10, 12, 1.5, 150, 1000);
MatchLoader.set(true);
chassis.drive_to_point(21.684 , 22.444, 0, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(44.504, 49.068, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(44.504, 49.068, 0, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(63.774, 47, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(63.774, 47, 0, 10, 12, 1.5, 150, 1000);
wait(0.1, sec);
chassis.turn_to_point(25.234, 47, 180, 10, 1.5, 150, 1000);
chassis.drive_to_point(25.234, 47, 0, 10, 12, 1.5, 150, 1000);
triplestate1.set(true);
triplestate2.set(false);
wait(2, sec);
MatchLoader.set(false);
chassis.drive_distance(10);
chassis.drive_distance(-10);
}
void left_split(){
chassis.set_coordinates(62.064,-16.733,270);
chassis.turn_to_point(22.545,-23.239, 0, 10, 1.5, 300, 250);
Intake1.spin(forward, 50, velocityUnits::pct);
Intake2.spin(reverse, 50, velocityUnits::pct);
chassis.drive_to_point(29.798, -21.937, 0, 10, 12, 1.5, 150, 900);
MatchLoader.set(true);
chassis.drive_to_point(21.684 ,-22.444, 0, 6, 12, 1.5, 150, 300);
chassis.turn_to_point(8.499, -9.26, 180, 10, 1.5, 150, 1000);
chassis.drive_to_point(8.499, -9.26, 0, 6, 12, 1.5, 150, 1000);
chassis.drive_distance(2);
triplestate1.set(false);
triplestate2.set(true);
wait(1, sec);
MatchLoader.set(true);
Intake1.spin(forward, 100, velocityUnits::pct);
Intake2.spin(reverse, 100, velocityUnits::pct);
triplestate1.set(false);
triplestate2.set(false);
chassis.turn_to_point(44.504, -49.068, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(44.504, -49.068, 0, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(63.774, -48.307, 0, 10, 1.5, 150, 1000);
chassis.drive_to_point(63.774, -48.307, 0, 10, 12, 1.5, 150, 1000);
wait(0.1, sec);
chassis.turn_to_point(25.234, -48.56, 180, 10, 1.5, 150, 1000);
chassis.drive_to_point(25.234, -48.56, 0, 10, 12, 1.5, 150, 1000);
triplestate1.set(true);
triplestate2.set(false);
wait(1, sec);
chassis.turn_to_angle(false, 90);
chassis.drive_distance(1.75, 0, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(60.731, -41.715, 0, 10, 1.5, 150, 800);
chassis.drive_distance(-20, 90, 10, 12, 1.5, 150, 1000);
}
void skills(){
chassis.set_coordinates(45.919, -0.135, 90);
Intake1.spin(forward, 100, velocityUnits::pct);
Intake2.spin(forward, 100, velocityUnits::pct);
chassis.turn_to_point(62.787, 0.106);
chassis.drive_to_point(62.787, 0.106, 0, 10, 12, 1.5, 300, 1200);
chassis.turn_to_point(45.919, -0.135);
chassis.drive_to_point(45.919, -0.135);
chassis.turn_to_point(18.388, -18.388);
chassis.drive_to_point(18.388, -18.388);
chassis.turn_to_point(9.767, -10.02, 180);
chassis.drive_to_point(9.767, -10.02, 0, 10, 12, 1.5, 300, 1200);
Intake1.spin(forward, 40, velocityUnits::pct);
Intake2.spin(forward, 40, velocityUnits::pct);
triplestate1.set(false);
triplestate2.set(true);


chassis.turn_to_point(47.039, 46.015);
chassis.drive_to_point(47.039, 46.015);
}
void solo_awp(){
chassis.set_coordinates(-46.268, -8.753, 180);
chassis.set_drive_exit_conditions(1.5, 200, 600);
chassis.turn_to_point(-47.283, -44.757, 0, 10, 1.5, 200, 250);
chassis.drive_to_point(-47.283, -44.757, 0, 10, 12, 1.5, 300, 900);
MatchLoader.set(true);
chassis.turn_to_point(-63.51, -45.011, 0, 10, 1.5, 200, 450);
Intake1.spin(forward, 100, velocityUnits::pct);
Intake2.spin(reverse, 100, velocityUnits::pct);   
chassis.drive_to_point(-63.51, -45.011);
wait(0.1, sec);
chassis.turn_to_point(-23.195, -45.011, 180);
chassis.drive_to_point(-23.195, -45.011);
MatchLoader.set(false);
triplestate1.set(true);
triplestate2.set(false);
wait(0.7, sec);
triplestate1.set(false);
triplestate2.set(false);
chassis.turn_to_point(-28.773, -22.952, 0, 10, 1.5, 200, 500);
chassis.drive_to_point(-24.97, -23.205);
chassis.turn_to_point(-24.97, 18.124, 0, 10, 1.5, 200, 300);
chassis.drive_to_point(-24.97, 18.124);
chassis.drive_to_point(-24.97, 23.195);
chassis.turn_to_point(-10.264, 10.01, 180);
chassis.drive_to_point(-10.264, 10.01);
triplestate1.set(false);
triplestate2.set(true);
wait(0.6, sec);
triplestate1.set(false);
triplestate2.set(false);
chassis.turn_to_point(-47.79, 46.268);
chassis.drive_to_point(-47.79, 46.268, 0, 10, 12, 1.5, 300, 1000);
MatchLoader.set(true);
chassis.turn_to_point(-64.524, 46.268);
chassis.drive_to_point(-64.524, 46.268);
wait(0.1, sec);
chassis.turn_to_point(-24.716, 46.268, 180);
chassis.drive_to_point(-24.716, 46.268);
triplestate1.set(true);
triplestate2.set(false);
}