#include <Servo.h>

const int BUTTON_PIN = A0;
int UPPER_LEFT = 2;
int UPPER_RIGHT = 3;
int LOWER_LEFT = 4;
int LOWER_RIGHT = 5;
const int geye = 9;
const int reye = 10;
const int beye = 11;

int push = 0;  

Servo servoLeg1;                 // create servo object to control a servo
Servo servoLeg2;                 // Legs of the spider
Servo servoLeg3;
Servo servoLeg4;

int Angle1 = 0;
int Angle2 = 0;
int Angle3 = 0;
int Angle4 = 0;

int buttonState = 0;
int i = 0;
void setup() {
  Serial.begin(9600);         // initialize serial
pinMode(geye, OUTPUT);
pinMode(reye, OUTPUT);
pinMode(beye, OUTPUT);

pinMode(13, OUTPUT); //remaining line
digitalWrite(13, LOW); 

pinMode(UPPER_LEFT, OUTPUT);
pinMode(UPPER_RIGHT, OUTPUT);
pinMode(LOWER_LEFT, OUTPUT);
pinMode(LOWER_RIGHT, OUTPUT);

digitalWrite(UPPER_LEFT, LOW);
digitalWrite(UPPER_RIGHT, LOW);
digitalWrite(LOWER_LEFT, LOW);
digitalWrite(LOWER_RIGHT, LOW);

digitalWrite(BUTTON_PIN, LOW);
pinMode(BUTTON_PIN, INPUT);
}

void loop() {

buttonState = digitalRead(BUTTON_PIN);

if(buttonState == HIGH) 

++push;
 
Serial.print("Push:  "); Serial.print(push); Serial.print('\n');
if (push == 1) {
  //angry
  analogWrite (reye, 255);
  analogWrite (beye, 0);
  analogWrite (geye, 0);
  
}
else if (push == 2) {
  //happy
  analogWrite (reye, 102);
  analogWrite (beye, 255);
  analogWrite (geye, 178);
}
else if (push == 3) {
  //disco
  analogWrite (reye, 255);
  analogWrite (beye, 0);
  analogWrite (geye, 0);
  delay(1500);
  analogWrite (reye, 255);
  analogWrite (beye, 0);
  analogWrite (geye, 255);
  delay(1500);
  analogWrite (reye, 0);
  analogWrite (beye, 0);
  analogWrite (geye, 255);
  delay(1500);
  analogWrite (reye, 0);
  analogWrite (beye, 255);
  analogWrite (geye, 0);
  delay(1500);
  analogWrite (reye, 127);
  analogWrite (beye, 255);
  analogWrite (geye, 0);
  delay(1500);
}

else {
  //base
  while(i<10)
  {
  analogWrite (reye, 0);
  analogWrite (beye, 255);
  analogWrite (geye, 0);

  Angle1 = 0;
  Angle2 = 0;
  Angle3 = 0;
  Angle4 = 0;

   digitalWrite(13, HIGH);
      Angle1 = 180;
      Angle2 = 180;
      Angle3 = 180;
      Angle4 = 180;  
      servoLeg1.write(Angle1);
      servoLeg2.write(Angle2);
      servoLeg3.write(Angle3);
      servoLeg4.write(Angle4);
      delay(1000);
      Angle1 = 360;
      Angle2 = 360;
      Angle3 = 360;
      Angle4 = 360;
      ++i;
  }
i = 0;
}
}
