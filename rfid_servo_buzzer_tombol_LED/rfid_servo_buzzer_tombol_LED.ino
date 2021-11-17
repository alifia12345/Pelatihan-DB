#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>


String uidString;
int Kunci=0;
int tombol=4;
int buzzer=2;
int R=5;
int Y=6;
int G=7;

//pin untuk servo
int outServo=3;
Servo myServo;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
 Serial.begin(9600);
 lcd.begin();
 myServo.attach(outServo);
 pinMode(buzzer,OUTPUT);
 pinMode(tombol,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 SPI.begin(); 
 mfrc522.PCD_Init(); 
 bunyibuzzeroke();
 lcd.setCursor(1,0);lcd.print("Selamat Datang");
 lcd.setCursor(4,1);lcd.print("Tempelkan");
 myServo.write(0);
}

void loop() {
  int bacatombol=digitalRead(tombol);
  
  if(mfrc522.PICC_IsNewCardPresent()&& Kunci==0){
  readRFID();
  Serial.print("Tag UID :");
  Serial.println(uidString);
  
  if(uidString == "C7-9D-88-4A"){
    myServo.write(90);
    bunyibuzzeroke();
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    lcd.clear();
    lcd.setCursor(3,0);lcd.print("BERHASIL!");
    lcd.setCursor(1,1);lcd.print("SILAHKAN MASUK");
    Kunci=1;
  }
  else{
  bunyibuzzergagal();
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  lcd.clear();
  lcd.setCursor(3,0);lcd.print("Gagal Masuk");
  }
  }
  if(bacatombol==1 && Kunci==1){
    myServo.write(0);
    bunyibuzzergagal();
    lcd.clear();
    lcd.setCursor(2,0);lcd.print("Selamat Jalan");
    delay(100);
    Kunci=0;
  }
}
void readRFID(){
mfrc522.PICC_ReadCardSerial();
uidString=String(mfrc522.uid.uidByte[0], HEX) +"-"+
          String(mfrc522.uid.uidByte[1], HEX) +"-"+
          String(mfrc522.uid.uidByte[2], HEX) +"-"+
          String(mfrc522.uid.uidByte[3], HEX);
          uidString.toUpperCase();
}
  
 void bunyibuzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  }
 void bunyibuzzergagal(){
 digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
 }
  
