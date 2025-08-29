#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int d = 8;
const int k = 9;
const int led1 = 6;
const int led2 = 10;
const int led3 = 11;

LiquidCrystal_I2C lcd(0x27,2,16);
void setup() {
  
  pinMode (d,OUTPUT);
  pinMode (k,INPUT);
  
  lcd.init();
  lcd.backlight();

  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);

}

void loop() {

 long duration , distance ;
  digitalWrite (d,LOW);
  delayMicroseconds (2);
  digitalWrite (d,HIGH);
  delayMicroseconds (10);
  digitalWrite (d,LOW);
  duration = pulseIn (k,HIGH);
  distance = duration*0.034/2;
  lcd.setCursor(0,0);
  lcd.print ("distance: ");
  lcd.print (distance);
  lcd.print (" cm ");
  int l =map (distance,4,170,0,255);
  delay (400);
     
  if (l<=170&&l>=4)
   {
     lcd.setCursor(0,1);
     lcd.print ("led is ON ");

     analogWrite (led1,l);
     analogWrite (led2,l);
     analogWrite (led3,l);
     
     
   }
      else
   {
    lcd.setCursor(10,0);
     lcd.print ("           ");
     lcd.setCursor(0,1);
     lcd.print ("led is OFF");
     digitalWrite (led1,LOW);
     digitalWrite (led2,LOW);
     digitalWrite (led3,LOW);
          
     
   }
  

}
