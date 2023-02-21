#include "Servo.h" //include servo library
#include "Freenove_WS2812B_RGBLED_Controller.h"
#define PIN_SERVO 2 //define servo pin
#define PIN_SONIC_TRIG 7 //define Trig pin
#define PIN_SONIC_ECHO 8 //define Echo pin
#define MAX_DISTANCE 300 //cm
#define SONIC_TIMEOUT (MAX_DISTANCE*60) // calculate timeout
#define SOUND_VELOCITY 340 //sound Velocity: 340m/s
#define I2C_ADDRESS  0x20
#define LEDS_COUNT   10  //it defines number of lEDs. 
Servo servo; //create servo object
char servoOffset = 0; //change the value to Calibrate servo
u8 distance[4]; //define an array with type u8(same to unsigned char)
Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT, TYPE_GRB); //initialization


void setup() {
    // while (!strip.begin());
    // Serial.begin(9600);
    pinMode(PIN_SONIC_TRIG, OUTPUT);// set trigPin to output mode
    pinMode(PIN_SONIC_ECHO, INPUT); // set echoPin to input mode
    servo.attach(PIN_SERVO); //initialize servo
    servo.write(90 + servoOffset); // change servoOffset to Calibrate servo
     
}

void loop() {

    servo.write(30);
    delay(1000);
    distance[0] = getSonar(); //get ultrasonic value and save it into distance[0]
    // servo.write(90);
    // delay(1000);
    // distance[1] = getSonar();
    servo.write(150);
    delay(1000);
    distance[2] = getSonar();

    
    Serial.print("Distance L / M / R / M2: "); //Left/Middle/Right/Middle2

    for (int i = 0; i < 4; i++) {
        Serial.print(distance[i]); //print ultrasonic in 45°, 90°, 135°, 90°
        Serial.print("/");
    }

    Serial.print('\n'); //next content will be printed in new line

     if (distance[0] > 30){
        strip.setLedColor(0, 0, 255, 0);
        strip.setLedColor(1, 0, 255, 0);
        strip.setLedColor(2, 0, 255, 0);
        strip.setLedColor(3, 0, 255, 0);
        strip.setLedColor(4, 0, 255, 0);
        strip.setLedColor(5, 0, 0, 0);
        strip.setLedColor(6, 0, 0, 0);
        strip.setLedColor(7, 0, 0, 0);
        strip.setLedColor(8, 0, 0, 0);
        strip.setLedColor(9, 0, 0, 0);
        strip.show();
    }else if (distance[0] < 30) {
        strip.setLedColor(0, 255, 0, 0);
        strip.setLedColor(1, 255, 0, 0);
        strip.setLedColor(2, 255, 0, 0);
        strip.setLedColor(3, 255, 0, 0);
        strip.setLedColor(4, 255, 0, 0);
        strip.setLedColor(5, 0, 0, 0);
        strip.setLedColor(6, 0, 0, 0);
        strip.setLedColor(7, 0, 0, 0);
        strip.setLedColor(8, 0, 0, 0);
        strip.setLedColor(9, 0, 0, 0);        
        strip.show();
    }
    if (distance[2] > 30){
        strip.setLedColor(0, 0, 0, 0);
        strip.setLedColor(1, 0, 0, 0);
        strip.setLedColor(2, 0, 0, 0);
        strip.setLedColor(3, 0, 0, 0);
        strip.setLedColor(4, 0, 0, 0);
        strip.setLedColor(5, 0, 255, 0);
        strip.setLedColor(6, 0, 255, 0);
        strip.setLedColor(7, 0, 255, 0);
        strip.setLedColor(8, 0, 255, 0);
        strip.setLedColor(9, 0, 255, 0);
        strip.show();
    }else if (distance[2] < 30) {
        strip.setLedColor(0, 0, 0, 0);
        strip.setLedColor(1, 0, 0, 0);
        strip.setLedColor(2, 0, 0, 0);
        strip.setLedColor(3, 0, 0, 0);
        strip.setLedColor(4, 0, 0, 0);
        strip.setLedColor(5, 255, 0, 0);
        strip.setLedColor(6, 255, 0, 0);
        strip.setLedColor(7, 255, 0, 0);
        strip.setLedColor(8, 255, 0, 0);
        strip.setLedColor(9, 255, 0, 0);
        strip.show();
    }else{
      strip.setAllLedsColor(0, 0, 255);    //set all LED off .
      strip.show();
    }
  
}

float getSonar() {
    unsigned long pingTime;
    float distance;
    digitalWrite(PIN_SONIC_TRIG, HIGH); // make trigPin output high level lasting for 10μs to triger HC_SR04,
    delayMicroseconds(10);
    digitalWrite(PIN_SONIC_TRIG, LOW);
    pingTime = pulseIn(PIN_SONIC_ECHO, HIGH, SONIC_TIMEOUT); // Wait HC-SR04 returning to the high level and measure out this waiting time
    if (pingTime != 0)
        distance = (float)pingTime * SOUND_VELOCITY / 2 / 10000; // calculate the distance according to the time
    else
    distance = MAX_DISTANCE;
    return distance; // return the distance value
}