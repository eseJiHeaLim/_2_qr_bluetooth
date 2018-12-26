
#include <Servo.h>

Servo servo;


void setup()
{
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{

      servo.write(110);
      delay(200);

}
