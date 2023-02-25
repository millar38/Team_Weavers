
#include <Servo.h>

// constants won't change

const int APOGEESERVO_PIN = 9; // Arduino pin connected to servo motor's pin
const int MAINSERVO_PIN = 8;

const int BUTTON_PIN = 6;

int TestA = 2;
int TestM = 3;

int apogee_T = A6; //Define, switched them for testing
int apogee_TG = A2; 
int main_T = A7;
int main_TG = A3;

int apogee_TVal = 0;
int apogee_TGVal = 0;
int main_TVal = 0;
int main_TGVal = 0;

int buttonState = 0;

Servo servoM;                 // create servo object to control a servo
Servo servoA;

// variables will change:

int AngleA = 0;
int AngleM = 0;

void setup() {
  Serial.begin(9600);         // initialize serial
 
  pinMode(APOGEESERVO_PIN, OUTPUT); // Define the Relaypin as output pin
  pinMode(MAINSERVO_PIN, OUTPUT);
  digitalWrite(APOGEESERVO_PIN, HIGH);
  digitalWrite(MAINSERVO_PIN, HIGH);

  pinMode(apogee_T, INPUT);
  pinMode(apogee_TG, INPUT);

  pinMode(main_T, INPUT);
  pinMode(main_TG, INPUT);

  servoM.attach(MAINSERVO_PIN);    // attaches the servo on pin 9 to the servo object
  servoA.attach(APOGEESERVO_PIN);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);  
  servoA.write(AngleA);
  servoM.write(AngleM);

  pinMode(BUTTON_PIN, OUTPUT);
  pinMode(TestA, OUTPUT);
  pinMode(TestM, OUTPUT);
  digitalWrite(TestA, LOW);
  digitalWrite(TestM, LOW);
}
 
void loop() {
 
  apogee_TVal = analogRead(apogee_T);
  apogee_TGVal = analogRead(apogee_TG);


  main_TVal = analogRead(main_T);
  main_TGVal = analogRead(main_TG);

  float apogee_TVolt = (apogee_TVal - apogee_TGVal)/204.8;
  float main_TVolt = (main_TVal - main_TGVal)/204.8;

  int apogee_On = digitalRead(APOGEESERVO_PIN);
  int main_On = digitalRead(MAINSERVO_PIN);

  Serial.print("Apogee (Telemega):  "); Serial.print(apogee_TVolt); Serial.print('\n');
  //Serial.print("Main (Telemega):    "); Serial.print(main_TVolt); Serial.print('\n');

  //Serial.print("Main_Relay: "); Serial.print(main_On); Serial.print('\n');
  

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    digitalWrite(TestA, HIGH);
    digitalWrite(TestM, HIGH);
  } else {
    digitalWrite(TestA, LOW);
    digitalWrite(TestM, LOW);
  }
  
  if(apogee_TVolt > 3) {
   digitalWrite(13, HIGH);
      AngleA = 90;  
      servoA.write(AngleA);
      delay(1000);
      AngleA = 0;

    // control servo motor arccoding to the angle

    }

  if(main_TVolt > 3) {
    digitalWrite(13, HIGH);  
      AngleM = 90;
      servoM.write(90);
      delay(1000);
      AngleM = 0;

    // control servo motor arccoding to the angle

    }
}
