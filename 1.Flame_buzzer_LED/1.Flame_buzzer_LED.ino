//Inisialisasi pembuatan variable
int sensorFlame =A1;
int pinBuzzer =5;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorFlame,INPUT);
 pinMode(pinBuzzer,OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
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

  if (bacaFlame==0 && bacaFlame<=20){
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    Serial.println("Aman");
  }
  else if(bacaFlame==21 && bacaFlame<=40){
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    Serial.println("WARNING!, Silahkan periksa");
    
  }
 else if(bacaFlame>= 50){
  digitalWrite(pinBuzzer, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  Serial.println("Waspada harap mengungsi");
 }
}
