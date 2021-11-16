#include <LiquidCrystal_I2C.h>

//Inisialisasi
int Flame=A1;
int R=2;
int Y=3;
int G=4;
int Tombol=5;
int Kunci=0;

//inisialisasi pembuatan variabel
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Menentukan fungsionalitas dari Pin 
  Serial.begin(9600);
  lcd.begin();
  pinMode(Flame,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(Tombol,INPUT);
  lcd.clear();
}

void loop() {
  //Baca Data
  int bacaFlame=analogRead(Flame);
      bacaFlame=map(bacaFlame,1024,0,0,255);
  int bacaTombol=digitalRead(Tombol);
  
  // Post serial
  Serial.println("NilaiFlame :" + String(bacaFlame));
  delay(100);
  Serial.println("KondisiTombol :" + String(bacaTombol));

  //Logika
  if(bacaTombol==1 && Kunci==0){
  delay(50);
  Kunci=1;
  }
  else if(bacaTombol==1 && Kunci==1){
   delay(50);
   Kunci=0;
  }
  if(Kunci ==1){
    if(bacaFlame<=30){
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,HIGH);
  lcd.clear();
  lcd.setCursor(6,0); lcd.print("Aman");
  delay(1000);
  }
  else if(bacaFlame>=31 && bacaFlame<=100){
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(G,LOW);
  lcd.clear();
  lcd.setCursor(4,0),lcd.print("Waspada");
  delay(1000);
}
 else if(bacaFlame>=101){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  lcd.clear();
  lcd.setCursor(5,0),lcd.print("Bahaya");
  delay(1000);
 }
  } 
  if(Kunci==0){
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  }
}
  
