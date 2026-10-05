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
  // custom autons below
}
void match_auto(){
chassis.set_coordinates(0, -62.346, 270);
// grab pin and cup
chassis.turn_to_point(-16.626, -51.46, 0, 10, 1.5, 150, 250);
// lift up lift slightly and pray dont fall
chassis.drive_to_point(-16.626, -51.46, 0, 10, 12, 1.5, 150, 1000);
// put lift down and let go of pin
chassis.turn_to_point(-9.5, -55.814, 90, 10, 1.5, 150, 250);
wait(0.1, sec);
chassis.drive_to_point(-9.5, -55.814, 90, 10, 1.5, 150, 250);
// time to go to the other pins
chassis.turn_to_point(-19.792, -28.501, 180, 10, 1.5, 150, 1000);
// slow down before reaching pin
chassis.drive_to_point(-19.792, -28.501, 0, 10, 12, 1.5, 150, 1000);
// clamp that shi
chassis.turn_to_point(-23.751, -41.168, 90, 10, 1.5, 150, 1000);
wait(0.1, sec);
chassis.drive_to_point(-23.751, -41.168, 90, 10, 1.5, 150, 1000);
// go back and score pin
chassis.turn_to_point(-24.74, -33.647, 180, 10, 12, 1.5, 150, 1000);
// go back away from goal
wait(0.1, sec);
chassis.turn_to_point(-41.366, -43.939, 180, 10, 12, 1.5, 150, 1000);
// go to the other pin stack
chassis.drive_to_point(-41.366, -43.939, 180, 10, 12, 1.5, 150, 1000);
chassis.turn_to_point(-30.678, -46.908, 270, 10, 12, 1.5, 150, 1000);
// back to goal and also lift up the lift
chassis.drive_to_point(-30.678, -46.908, 270, 10, 12, 1.5, 150, 1000);
// score pin and game
}
// void next_auto(){