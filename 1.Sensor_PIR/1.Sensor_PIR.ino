//Inisialisasi pembuatan variable
int pinPIR  =2;
int pinBuzzer  =5;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinPIR,INPUT);
 pinMode(pinBuzzer,OUTPUT);
}

void loop() {

//baca data
 int bacaPIR=digitalRead(pinPIR); //Membaca Nilai Sensor PIR
 
 //Print ke Serial Monitor
 Serial.print("Nilai PIR:");
 Serial.print(bacaPIR);
 Serial.println();
 delay(500);


//LOGIKA

  if(bacaPIR==1){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  Serial.print("ADA MALING!!!");                                                                    
  
  }else{
  digitalWrite(pinBuzzer,LOW);
  delay(100);}
  Serial.print("AMAN");
}
