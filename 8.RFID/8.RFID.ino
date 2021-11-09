#include <SPI.h>
#include <MFRC522.h>

int Buzzer=8;

//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 pinMode(Buzzer, OUTPUT);
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content== "C79D884A") //Sesuaikan dengan ID kartu anda
 {
   digitalWrite(Buzzer, HIGH);
 delay(50);
 digitalWrite(Buzzer,LOW);
 delay(50);
 Serial.println("Selamat datang ALIFIA A!!!");
 delay(2000);
 }
 else if (content== "EA06D580") //Sesuaikan dengan ID kartu anda
 {
 digitalWrite(Buzzer, HIGH);
 delay(50);
 digitalWrite(Buzzer,LOW);
 delay(50);
 Serial.println("Selamat datang LIANI A!!!");
 delay(2000);
 
 }else{
 Serial.println("Kartu Belum Terdaftar!");
 }
 Serial.println("Tempelkan Kartu!");
 delay(100);
 digitalWrite(Buzzer,HIGH);
 delay(100);
 digitalWrite(Buzzer,LOW);
  }
