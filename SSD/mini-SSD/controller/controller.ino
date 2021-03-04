#include <AccelStepper.h>
AccelStepper stepper(AccelStepper::DRIVER, 2, 3); // Running on Pololu DRV8834

// set some system parameters
const int ledPin =  13;      // the number of the LED pin
const int M1Pin = 4; // the number of the pin connected to M1 on the Pololu driver
const int numsteps = 200;    // the number of steps per revolution
const int microstep = 32; // number of microsteps
const float D = 0.018; // diameter of spindles (m)
const float pi = 3.14159; // pi
const float steps_per_m = numsteps*microstep/(pi*D);

// Things to edit
float increment_distance; // distance to move per increment (mm)
const float max_speed = 0.01; // target belt velocity (m/s)
const float max_accel = 10.; // steps per second per second
const float max_speed_steps = max_speed*steps_per_m; // target belt velocity in steps per second

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); // initialize the LED pin as an output:
    pinMode(M1Pin, OUTPUT);
    digitalWrite(ledPin, LOW); // turn LED off
    digitalWrite(M1Pin, HIGH);
    
    // set up stepper motor
    stepper.setMaxSpeed(max_speed_steps); // steps per second
    stepper.setAcceleration(10.0);
    stepper.setSpeed(0);

    Serial.println("Ready. Type distance to move (in mm)");
    }

void loop() {
    Serial.flush(); //flush all previous received and transmitted data
    while(Serial.available()) {
        float increment_distance = Serial.parseFloat();
        float is = increment_distance*steps_per_m/1000;
        long increment_steps = (long) is; // increment distance in steps
        digitalWrite(ledPin, HIGH); // turn LED off
        
        Serial.print("Moving ");
        Serial.print(increment_distance);
        Serial.print(" mm, which is ");
        Serial.print(increment_steps);
        Serial.println(" steps.");

        stepper.setCurrentPosition(0);
        stepper.runToNewPosition(increment_steps);

        digitalWrite(ledPin, LOW); // turn LED off
        Serial.println("Finished move. Enter a new distance.");
        }
    }
