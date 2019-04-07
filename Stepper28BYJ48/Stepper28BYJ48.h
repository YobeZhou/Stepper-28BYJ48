/*
 * 
 */

// ensure this library description is only included once
#ifndef Stepper28BYJ48_h
#define Stepper28BYJ48_h

// library interface description
class MyStepper {
  public:
    // constructors:
    MyStepper(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

  private:
    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    int speed;                // Speed in RPMs
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int pin_count;            // how many pins are in use.
    int step_number;          // which step the motor is on

    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;

    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif
