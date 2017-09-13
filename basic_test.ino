/* DZ292 Laser Receiver Module (DZ292) [S035] : http://rdiot.tistory.com/297 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int laserPin = 2; // Laser
int laserRcvPin = 7; // Laser Receiver

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(laserPin,OUTPUT);
  pinMode(laserRcvPin,INPUT);

  digitalWrite(laserPin, HIGH);
  delay(1000);

  lcd.clear();
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("S035:DZ292 LaserRCV");

  int rcv = digitalRead(laserRcvPin);

  lcd.setCursor(0,2);
  lcd.print("laser value=" + (String)rcv);

  if(rcv == 1)
  {
    lcd.setCursor(0,3);
    lcd.print("laser detected");
  }
  else
  {  
    lcd.setCursor(0,3);
    lcd.print("                    ");
  }
}
