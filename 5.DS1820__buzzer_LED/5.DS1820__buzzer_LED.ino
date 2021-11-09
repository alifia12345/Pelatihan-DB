#include <OneWire.h>

#include <DallasTemperature.h>

 int sensorSuhu =2;
 int buzzer=3;

 int R=4;
 int G=5;
 OneWire oneWire(sensorSuhu);
 DallasTemperature sensors(&oneWire);

 void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 sensors.begin(); //Memanggil fungsi
 pinMode(sensorSuhu, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(G,OUTPUT);
 }

 void loop() {
 //Program yang akan dijalankan berulang-ulang
 sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0); //Membaca data di index 0 pada one wire
  
  if(bacaSuhu >=30){
  Serial.print("VIRUS TERDETEKSI!!!");
  Serial.println(bacaSuhu);
  digitalWrite(buzzer,HIGH);
  digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  }
  else
  {
  Serial.println("Suhu Normal!");
  digitalWrite(buzzer,LOW);
  digitalWrite(R,LOW);
  digitalWrite(G,HIGH);
  }
  }
