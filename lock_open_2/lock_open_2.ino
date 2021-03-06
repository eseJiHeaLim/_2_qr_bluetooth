
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;
SoftwareSerial BTSerial(2, 3); //Connect HC-06. Use your (TX, RX) settings
String res = "";

int Servo_Center = 85;
int Servo_Open = Servo_Center+7;
int Servo_Lock = Servo_Center-8;

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  servo.attach(11);
  servo.write(Servo_Center);
}

void loop()
{
  if (BTSerial.available()) {
    res = (char)BTSerial.read();
    if (res == "Y") {
      Serial.print("This is Open\n");
      res = "";
      servo.write(Servo_Open);
      delay(600);
      servo.write(Servo_Center);
    }
    else if (res == "N") {
      Serial.print("This is Lock\n");
      res = "";
      servo.write(Servo_Lock);
      delay(700);
      servo.write(Servo_Center);
    }

  }

}
