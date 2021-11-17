#include <LiquidCrystal_I2C.h>
//#include <Servo.h>

int Flame=A1;
int buzzer=2;
int tombol=4;
int Kunci=0;
int R=5;
int Y=6;
int G=7;

LiquidCrystal_I2C lcd(0x27,16,2);//pengaturan lcd (alamat,jumlah kolom,jumlah,baris)

void setup() {
Serial.begin(9600);//Baudrate kecepatan pengiriman data
lcd.begin();
pinMode(Flame,INPUT);
pinMode(tombol,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
int bacaFlame=analogRead(Flame);
    bacaFlame=map(bacaFlame,1024,0,0,255);//Karena aktif low jadi nilai terkecilnya 1024 dan nilai terbesarnya 0,dan jika nilai nya aktif maka 255 dan saat belum aktif nilainya 0
//mapping memberi range 
int bacatombol=digitalRead(tombol);

Serial.println ("Nilai Flame :" + String(Flame));//Karena nilai flame masih bilangan bulat maka harus di ubah menjadi String(karakter)
delay(100);
Serial.println ("Kondisi Tombol :" + String(tombol));

if(bacatombol==1 && Kunci==0){
delay(100);
Kunci=1;
}
else if(bacatombol==1 && Kunci==1){
delay(100);
Kunci=0;
}
if(Kunci==1){
if(bacaFlame<=30){
digitalWrite(R, LOW);
digitalWrite(Y,LOW);
digitalWrite(G,HIGH);
delay(100);
lcd.clear();//membersihkan smua tampilan di lcd
lcd.setCursor(3,1);lcd.print("Aman");
} 
else if(bacaFlame>=31 && bacaFlame<=100){
digitalWrite(R,LOW);
digitalWrite(Y,HIGH);
digitalWrite(G,LOW);
delay(100);
lcd.clear();
lcd.setCursor(3,1);lcd.print("Waspada");
}
else{
digitalWrite(R,HIGH);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
delay(100);
lcd.clear();
lcd.setCursor(3,1);lcd.print("Bahaya");
}
}
if(Kunci==0){
digitalWrite(R,LOW);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
}
}
