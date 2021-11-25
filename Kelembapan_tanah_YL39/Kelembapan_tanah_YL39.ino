#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul
#include <DHT.h>
DHT dht(2, DHT11); //Pin, Jenis DHT

int sensorPin = A0;  // pin sensor
int powerPin = 6;    // untuk pengganti VCC
int powerPin2 = 3;    // untuk pengganti VCC/5vOLT
 
void setup() { 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight(); 
  // jadikan pin power sebagai output
  pinMode(powerPin, OUTPUT);
  // default bernilai LOW
  digitalWrite(powerPin, LOW);
  // mulai komunikasi serial
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  lcd.clear();
  Serial.print("Nilai kelembaban: ");
  Serial.println(bacaSensor());
  lcd.setCursor(0,0);
  lcd.print("Nilai kelembaban: ");
  lcd.setCursor(0,1);
  lcd.print(bacaSensor());
  // baca setiap 2 detik
  delay(2000);

  digitalWrite(powerPin2, HIGH);
  

 float suhu = dht.readTemperature();


 Serial.print("suhu: ");
 Serial.println(suhu);

  lcd.setCursor(0,1);
  lcd.print("Suhu: ");
  lcd.setCursor(5,1);
  lcd.print(suhu);
  delay(1000);
}
 
int bacaSensor() {
  // hidupkan power
  digitalWrite(powerPin2, HIGH);
  delay(500);
  // baca nilai analog dari sensor
  int nilaiSensor = analogRead(sensorPin);
  digitalWrite(powerPin2, LOW);
  // makin lembab maka makin tinggi nilai outputnya
 return 1023 - nilaiSensor;
}
