#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

String uidString;
int buzzer=5;
int tombol=3;
int kunci=0;


#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
 pinMode(buzzer,OUTPUT);
 pinMode(tombol,INPUT);
 SPI.begin();
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 Serial.println("Tempelkan kartu!");
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacatombol=digitalRead(tombol);

 if (mfrc522.PICC_IsNewCardPresent()and kunci==0) {
  readRFID();
  Serial.print("Tag UID : ");
  Serial.println(uidString);
  
  if(uidString == "C7-9D-88-4A"){
    delay(500);
    bunyibuzzeroke();
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(4,0); lcd.print("Welcome");
    lcd.setCursor(0,1); lcd.print(" Alifia Andini");
    delay(1000); //Jeda waktu perulagan seama 1000 mili detik
    kunci=1;
  }
  else{
    lcd.clear();
    lcd.setCursor(2,0); lcd.print("GAGAL MASUK");
    bunyibuzzergagal();
  }
  }if(bacatombol==1 && kunci==1){
   bunyibuzzergagal();
   lcd.clear(); //Untuk Menghapus karakter pada LCD
   lcd.setCursor(2,0); lcd.print("Terimakasih");
   lcd.setCursor(1,1); lcd.print("Selamat Jalan");
   delay(1000);
   kunci=0;
  }
  }

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //pembatasan bisa dirubah sesuai keinginan, disini yang digunakan"-"
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}
void bunyibuzzeroke(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
