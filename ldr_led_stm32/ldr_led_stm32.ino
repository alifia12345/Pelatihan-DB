//INISIALISASI
int IR=PA0;
int LDR=PA1;

int R=PA2;
int Y=PA3;
int kunci=0

void setup() {
 Serial.begin(9600);
 pinMode(IR, INPUT);
 pinMode(LDR,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
  
}

void loop() {
  //BACA DATA / SENSOR
int bacaIR=digitalWrite(IR);
int bacaLDR=analogWrite(LDR);
    bacaLDR= map(bacaLDR,2059,0,0,255);

  //PRINT TO SERIAL
  Serial.print("NilaiIR :" + String(bacaIR));
  Serial.print("NilaiLDR :" + String(bacaLDR));
  Serial.println();

  //LOGIKA
  }if(bacaIR==0 && kunci==0){
  digitalWrite(R,HIGH);
  kunci=1;
  }else if (bacaIR==0 && kunci==1){
    digitalWrite(R,LOW);
  }
  }
