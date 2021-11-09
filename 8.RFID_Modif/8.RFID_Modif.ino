#include <SPI.h>
#include <MFRC522.h>

String uidString;
int buzzer = 5;
int infrared=2;
int kunci1=0;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {

 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(buzzer,OUTPUT);
 pinMode(infrared, INPUT);
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 Serial.println("Tempelkan kartu!");
}

void loop() {

 int bacainfrared=digitalRead(infrared);
  // put your main code here, to run repeatedly:
  
 if (mfrc522.PICC_IsNewCardPresent()and kunci1==0) {
  readRFID();
  Serial.print("Tag UID : ");
  Serial.println(uidString);

  if(uidString == "C7-9D-88-4A"){
    delay(500);
    bunyibuzzeroke();
    Serial.println("Palang Terbuka");
    delay(1000);
    kunci1=1;
  }
  else{
    Serial.println("GAGAL MASUK!!");
    bunyibuzzergagal();
  }
  }if(bacainfrared==0 && kunci1==1){
   bunyibuzzergagal();
   Serial.println("Palang Tertutup");
   kunci1=0;
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
