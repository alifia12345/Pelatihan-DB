//Inisialisasi pembuatan variable
int sensorLDR =A0;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(sensorLDR,INPUT);
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaLDR=analogRead(sensorLDR); //Membaca Nilai LDR

  //Print ke Serial Monitor
  Serial.print("Nilai LDR:");
  Serial.print(bacaLDR);
  Serial.println();
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
