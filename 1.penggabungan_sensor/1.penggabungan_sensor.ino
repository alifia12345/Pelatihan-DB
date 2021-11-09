//Inisialisasi pembuatan variable
int sensorFlame =A1;
int pinLDR=A0;
int sensorPIR=4;
int pinBuzzer =2;


int R=2;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorFlame,INPUT);
 pinMode(sensorPIR,INPUT);
 pinMode(pinLDR,INPUT);
 pinMode(pinBuzzer,OUTPUT);
 pinMode(2, OUTPUT);

}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaFlame=analogRead(sensorFlame); //Membaca Nilai Flame
     bacaFlame=map(bacaFlame,1023,32,0,100);
 
 //Print ke Serial Monitor
 Serial.print("Nilai Flame:");
 Serial.print(bacaFlame);
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik

  if (bacaFlame==0 && bacaFlame<=50){
    digitalWrite(pinBuzzer, LOW);
  }

  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR,0,1024,0,255);

  Serial.print("Nilai LDR;");
  Serial.print(bacaLDR);
  Serial.println();
  delay(100);

  analogWrite(3,bacaLDR);
  delay(100);

  int sensorPIR=digitalRead(sensorPIR);

  Serial.print("Nilai PIR:");
  Serial.print(sensorPIR);
  Serial.println();
  delay(500);

}
