/*This is a program to get the car's rfid number form another arduino and compare with the database.
When the comparison holds true it stores that id in iCar variable
Next goal is to print the the contents of iCar into the lcd display*/
#include <Wire.h>

int count = 0;
char input[12];
boolean flag = 0;
int i = 0;
char car1 = "270022321225";
char car2 = "27002233D2E4";
char car3 = "270022517D29";
char car4 = "2700222E96BD";
char car5 = "2700222FC4EE";

char iCar[14];

void compare(char iCar[])
{
  iCar = Wire.read();
   if(iCar == car1)
    {
      iCar = car1;
    }
    if(iCar == car2)
    {
      iCar = car2;
    }
    if(iCar == car3)
    {
      iCar = car3;
     }
     if(iCar == car4)
     {
      iCar = car4;
     }
     if(iCar == car5)
     {
      iCar = car5;
     }
     else
     {
      iCar = "U";
      
     }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  s
  compare(input);
  Wire.begin(8);
  Wire.onReceive(compare);
  Wire.endTransmission();
}
