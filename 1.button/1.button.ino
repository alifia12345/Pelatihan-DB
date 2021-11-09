//inisialisasi
//UNtuk Tombol
int tombol1=2;
int tombol2=3;
int tombol3=4;

//Untuk LED
int R=5;
int Y=6;
int G=7;

void setup() {
 Serial.begin(9600);
 pinMode (tombol1,INPUT);
 pinMode (tombol2,INPUT);
 pinMode (tombol3,INPUT);
 pinMode (R,OUTPUT);
 pinMode (Y,OUTPUT);
 pinMode (G, OUTPUT);

}

void loop(){
  //baca Data
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

  //post serial atau print serial
  Serial.print ("KondisiTombol:" + String (bacaTombol1));
  Serial.print (" KondisiTombol:" + String (bacaTombol2));
  Serial.print (" KondisiTombol:" + String (bacaTombol3));
  Serial.println();
  
  //logika
  if (bacaTombol1==1){
    digitalWrite (R, HIGH);
  }else{
      digitalWrite(R,LOW);
  }

   if (bacaTombol2==1){
    digitalWrite (Y, HIGH);
  }else{
      digitalWrite(Y,LOW);
  }

  if (bacaTombol3==1){
    digitalWrite (G, HIGH);
  }else{
      digitalWrite(G,LOW);
  }

  

}
