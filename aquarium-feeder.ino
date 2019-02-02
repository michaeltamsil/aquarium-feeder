#include<Servo.h>

// set pin numbers:
#define pinServo 9
Servo servo;

long previousMillis = 0;        // will store last time servo was updated
 
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 60000;           // interval at which to rotate (milliseconds)

void setup() {
  Serial.begin(9600);
  // set the digital pin as output:
  servo.attach(pinServo);
  servo.detach();
}
 
void loop()

{
unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;   

    servo.attach(pinServo);
    servo.write(60);
    delay(3000);
    servo.detach();
  }
  Serial.println(currentMillis);
}
