#include <SPI.h>
#include <MFRC522.h>

String uidString;
int buzzer = 5;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(buzzer,OUTPUT);
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 Serial.println("Tempelkan kartu!");
}

void loop() {
  // put your main code here, to run repeatedly:
 if (mfrc522.PICC_IsNewCardPresent()) {
  readRFID();
  Serial.print("Tag UID : ");
  Serial.println(uidString);

  if(uidString == "C7-9D-88-4A"){
    bunyibuzzeroke();
    Serial.println("BERHASIL!");
    delay(1000);
    Serial.println("SILAHKAN MASUK LIANI");
  }
  else if(uidString == "EA-06-D5-80"){
    bunyibuzzeroke();
    Serial.println("BERHASIL!");
    delay(1000);
    Serial.println("SILAHKAN MASUK ALIFIA");
  }else{
    Serial.println("GAGAL!!");
    bunyibuzzergagal();
  }
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
