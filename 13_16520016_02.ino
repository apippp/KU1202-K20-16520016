#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int pingPin = A1;
long duration, cm;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("PING Sensor");
}

void loop(){
  cm = read_ultra_sonic();
  
  /*Print to LCD*/
  lcd.setCursor(0,1);
  lcd.print("Jarak(cm) ");
  lcd.setCursor(6,1);
  lcd.print(cm);
  //print_unit_cm(cm);
}

int read_ultra_sonic(){

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  if (cm >= 2 && cm <= 330){
    return cm;
  } else {
    return 0;
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2; 
}
