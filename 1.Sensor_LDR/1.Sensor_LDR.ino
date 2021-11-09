//Inisialisasi pembuatan variable
int pinLDR  = A0;
int pinLED  =3;

void setup() {
 //Menentukan Fungsionalitas dari LDR pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinLDR,INPUT);
 pinMode(3,OUTPUT);
}

void loop() {

//baca data
 int bacaLDR=analogRead(pinLDR); //Membaca Nilai Sensor LDR
     bacaLDR=map(bacaLDR,0,1024,0,255);
     //tampung=merubah data(tampung,data awal, data akhir sensor,nilai awal rubah,nilai )
     
 //Print ke Serial Monitor
 Serial.print("Nilai LDR:");
 Serial.print(bacaLDR);
 Serial.println();
 delay(100);

  analogWrite(3, bacaLDR);
  delay(100);
}
