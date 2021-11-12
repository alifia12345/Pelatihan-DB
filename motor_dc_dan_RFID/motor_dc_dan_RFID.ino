#include <SPI.h>
#include <MFRC522.h>
#define B1 5 // Motor B pins
#define B2 6


int Tombol=2;
int Buzzer=3;

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
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 pinMode(B1, OUTPUT);
 pinMode(B2, OUTPUT);
 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
 
 Serial.println("Silahkan Pilih salah satu:");
 Serial.println("1.forward");
 Serial.println("2.backward");
 Serial.println("3.stop"); 
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
 forward();
 delay(2000);
 }
 else if (content== "EA06D580") //Sesuaikan dengan ID kartu anda
 {
 digitalWrite(Buzzer, HIGH);
 delay(50);
 digitalWrite(Buzzer,LOW);
 delay(50);
 Serial.println("Selamat datang LIANI A!!!");
 backward();
 delay(2000);
 
 }else{
 Serial.println("Kartu Belum Terdaftar!");
 }
 Serial.println("Tempelkan Kartu!");
 delay(100);
 digitalWrite(Buzzer,HIGH);
 delay(100);
 Stop();
 digitalWrite(Buzzer,LOW);
  }
  void forward() { //function of forward 
 analogWrite(A1, 255);//5
 analogWrite(A2, 0);//6
 analogWrite(B1, 255);//10
 analogWrite(B2, 0);//11
 delay(1000);
 digitalWrite(B1,LOW);
}
void backward() { //function of backward
 analogWrite(A1, 0);
 analogWrite(A2, 210);
 analogWrite(B1, 0);
 analogWrite(B2, 255);
 delay(1000);
 digitalWrite(B2,LOW);
}
void Stop() { //function of stop
 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
}
