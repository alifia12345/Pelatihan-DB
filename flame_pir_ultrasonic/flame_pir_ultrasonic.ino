#include <NewPing.h>

//Inisialisasi pembuatan variable
int Trig =PA1;
int Echo =PA0;
int batas =200; //Maksimal 400 cm

int PIR=PA3;
int Flame=PA2;

int R=PA4;
int Y=PA5;
int G=PA6;

int kunci=0;

NewPing cm(Trig,Echo,batas);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(Flame,INPUT);
 pinMode(PIR,INPUT);
 pinMode(Trig,INPUT);
 pinMode(Echo,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 int bacaFlame=digitalRead(Flame);
 int bacaPIR=digitalRead(PIR);
 
 //Print ke Serial Monitor ultrasonic
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik

//print ke serial monitor flame
Serial.print("Nilai Flame: ");
Serial.print(bacaFlame);
Serial.println();

//print serialmonitor PIR
Serial.print("Nilai PIR: " );
Serial.print(bacaPIR);
Serial.println();

//Logika
if(bacaFlame==0 && kunci==0){
delay(100);
kunci=1;
}else if(bacaFlame==0 && kunci==1){
 delay(100);
 kunci=0;
}
if(kunci==1){
if(bacaPIR==1){
  digitalWrite(R,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  Serial.print("Ada Orang");
}else if (bacaPIR==0){
  digitalWrite(Y,HIGH);
  delay(100);
  digitalWrite(Y,LOW);
  Serial.print("Aman");
 if(kunci==0){
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
  }
}
if(kunci==1){
  if(bacaJarak<=30){
   digitalWrite(R,HIGH);
   digitalWrite(Y,LOW);
   digitalWrite(G,LOW);
   Serial.println("Bahaya");
  }else if(bacaJarak>=31 and bacaJarak<=100){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    Serial.print("Hati-Hati");
  }else if(bacaJarak>=101 and bacaJarak<=200){
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH); 
    Serial.print("Aman");
    }
  }
  if(kunci==0){
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    Serial.println("Tidak ada orang");
}
}
}
