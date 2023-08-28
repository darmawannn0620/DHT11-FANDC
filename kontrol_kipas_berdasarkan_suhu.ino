#include<Wire.h>
#include <LiquidCrystal_I2C.h> // libray lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>  // library DHT11
DHT dht(2,DHT11); //Pin, Jenis DHT11

int kipas=3;

void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.begin();
  pinMode(kipas,OUTPUT);
}
void loop()
{
  int kelembaban=dht.readHumidity();
  int suhu=dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temperatur:");
  lcd.setCursor(12,0);
  lcd.print(suhu);
  lcd.setCursor(14,0);
  lcd.print(".C");

  lcd.setCursor(0,1);
  lcd.print("Kipas :");
  lcd.setCursor(8,1);
  if(suhu>27)
  {
  digitalWrite(kipas,HIGH); 
  lcd.print("ON ");
  }
  else
  { 
  digitalWrite(kipas,LOW);
  lcd.print("OFF");
  }
}
