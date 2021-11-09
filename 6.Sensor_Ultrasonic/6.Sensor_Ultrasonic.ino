#include <NewPing.h>
//Inisialisasi pembuatan variable
//kuning=Trig
//Oren=Echo

int Buzzer=3;
int triger =6;
int echo =7;
int batas =200; //Maksimal 400 cm
int R=4;
int Y=8;
int G=5;
NewPing cm(triger,echo,batas);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(Buzzer, OUTPUT);
 pinMode(triger,INPUT);
 pinMode(echo,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 //Print ke Serial Monitor
 if(bacaJarak <=22 and !=0){
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(100);
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  Serial.println("BERHENTI");
  
 }else if(bacaJarak >=21 and bacaJarak <=70){
  digitalWrite(Buzzer,LOW);
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(G,LOW);
  Serial.println("BAHAYA");
 }
 else if (bacaJarak >=71){
 digitalWrite(Buzzer,LOW);
 digitalWrite(R,LOW);
 digitalWrite(Y,LOW);
 digitalWrite(G,HIGH);
 Serial.println("AMAN");
 }
}
