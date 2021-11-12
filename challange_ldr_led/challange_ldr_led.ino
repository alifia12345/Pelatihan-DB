//INISIALISASI
int Tombol=PA3;
int LDR=PA4;

int R=PA0;
int Y=PA1;
int G=PA5;
int kunci=0;

void setup() {
 Serial.begin(9600);
 pinMode(Tombol,INPUT);
 pinMode(LDR,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
  
}

void loop() {
  //BACA DATA / SENSOR
int bacaLDR=analogRead(LDR);
    bacaLDR= map(bacaLDR,4095,300,0,255);
int bacaTombol=digitalRead(Tombol);

  //PRINT TO SERIAL
  Serial.print("NilaiLDR :" + String(bacaLDR));
  Serial.print("NilaiTombol :" +String(bacaTombol));
  Serial.println();

  //LOGIKA
 if (bacaTombol==0 && kunci==0){
 kunci=1;
  if(bacaLDR<100){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
 }else if(bacaLDR>100 && bacaLDR<200){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
 }else if(bacaLDR>200 && bacaLDR<250){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
   }
 }
 if(bacaTombol==0 && kunci==1){
  kunci=0;
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
   
}
}
// if(bacaLDR>=200 and bacaLDR<=250){
//    analogWrite(R,255);
//    analogWrite(Y,0);
//    analogWrite(G,0);
//  }if (bacaLDR>=100 and bacaLDR<=200){
//    analogWrite(R,0);
//    analogWrite(Y,255);
//    analogWrite(G,0);
//  }if (bacaLDR==0 and bacaLDR<=100){
//    analogWrite(R,0);
//    analogWrite(Y,0);
//    analogWrite(G,255);
//  }if (bacaLDR==0 && bacakunci==0){
//    delay(100);
//    kunci=1;
//  }
  
