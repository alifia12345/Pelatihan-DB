int R=2;
int Y=3;
int G=4;

void setup() {
  Serial.begin(9600); //Baudrate Komunikasi Serial
 for (int i=3; i<=6; i++){
 pinMode (i,OUTPUT);} 
}

void loop() {
 for (int i=0; i<=255; i++){
  analogWrite (3,i);
  // float volt=map (i,0,255,0,5); 
  float volt= (5.0/255.0); //Konversi Nilai PWM ke Volt dari 0-255 menjadi 0-5
  float hasil = i*volt;
  Serial.print ("volt :");
  Serial.println(hasil);
  delay (20);
  }
 
 for (int i=255; i>=0; i--){
  analogWrite (3,i);
  // float volt=map (i,0,255,0,5);
  float volt=(5.0/255.0); //Konversi Nilai PWM ke Volt dari 0-255 menjadi 0-5
  float hasil =i*volt;
  Serial.print ("volt :");
  Serial.println(hasil); // Menampilkan hasil
  delay (20); }
}
