int relay1=4, relay2=5, relay4=6, fine=7;

void relayShowBinaryNumber(int n){

  if(n-4>=0){
    digitalWrite(relay4, HIGH);
    n=n-4;
  }
  else{
    digitalWrite(relay4, LOW);
  }
  if(n-2>=0){
    digitalWrite(relay2, HIGH);
    n=n-2;
  }
  else{
    digitalWrite(relay2, LOW);
  }
  if(n-1>=0){
    digitalWrite(relay1, HIGH);
    n=n-1;
  }
  else{
    digitalWrite(relay1, LOW);
  }

}

void relayTest(){
  relayShowBinaryNumber(1);
  delay(200);
  relayShowBinaryNumber(3);
  delay(200);
  relayShowBinaryNumber(7);
  delay(500);
}


void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(fine, INPUT);

}

void loop() {
  int i=0;
  int fineStatus=0;
  for(i=0;i<8;i++){
    relayShowBinaryNumber(i);
    delay(1000);
  }
  while(digitalRead(fine)==LOW){
    digitalRead(fine);
    relayTest();
    delay(10);
  }
  
}
