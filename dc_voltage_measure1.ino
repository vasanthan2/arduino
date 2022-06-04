
#include <LiquidCrystal.h>


float Vout = 0.00;
float Vin = 0.00;
float R1 = 100000.00; // resistance of R1 (100K) 
float R2 = 10000.00; // resistance of R2 (10K) 
int val = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
   pinMode(A0, INPUT); //assigning the input port vol
   Serial.begin(9600); //BaudRate

  lcd.begin(16, 2);
 
  
}

void loop() {
  
 
  
  val = analogRead(A0);
   Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out 
   Vin = Vout / (R2/(R1+R2)); // formula for calculating voltage in
   if (Vin<0.09)//condition 
   {
     Vin=0.00;//statement to quash undesired reading !
  } 

lcd.print(Vin);
delay(1000);
  lcd.clear();
}
 