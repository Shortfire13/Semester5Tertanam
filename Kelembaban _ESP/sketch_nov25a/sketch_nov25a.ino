// ## Sensor Kelembaban ## //

#define pinKelembaban 34

void setup(){
  Serial.begin(9600)
}

void loop(){
  // Kelembapan //
  int nilaiSensor = analogRead(pinKelembapan);
  int kelembapan = map(nilaiSensor, 0, 4095,100,0);
  //

  // Serial Print kelembaban//
  Serial.println("H: " + String(kelembaban) + "%");
  Serial.println(nilaiSensor);
  Serial.println("");
  //

  delay(1000);
}

