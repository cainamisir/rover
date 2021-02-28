
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  int stopOutput = map(potValue, 0, 0, 0 , 255);
  analogWrite(enA, pwmOutput);
  String data;
   if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
  }
  if(data == "Close")
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  else if(data == "Open")
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  else if(data == "Fata")
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    rotDirection = 1;
    analogWrite(enA, pwmOutput);
    delay(1000);
    analogWrite(enA, stopOutput);
  }
  else if(data == "Spate")
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    rotDirection = 0;
    analogWrite(enA, pwmOutput);
    delay(1000);
    analogWrite(enA, stopOutput);
  }
  else if(data == "Stanga")
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    rotDirection = 1;
    analogWrite(enA, pwmOutput);
    delay(1000);
    analogWrite(enA, stopOutput);
  }
  else if(data == "Dreapta"){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    rotDirection = 0;
    analogWrite(enA, pwmOutput);
    delay(1000);
    analogWrite(enA, stopOutput);
  }
}
