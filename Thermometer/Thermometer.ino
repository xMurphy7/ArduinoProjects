#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN,DHTTYPE);

byte humsym[] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte thempsym[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.setBacklight(HIGH);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  lcd.createChar(0,humsym);
  lcd.createChar(1,thempsym);
}

void loop() {
  float t=dht.readTemperature();
  float h=dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print(char(1));
  lcd.print(" Temp: ");
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print(char(0));
  lcd.print(" Wilg: ");
  lcd.print(h);
  lcd.print("%");

  delay(2000);

  if(t>=22){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
  else if(t<22 && t>=19) {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
  }
  else if(t<19) {
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  } 

}