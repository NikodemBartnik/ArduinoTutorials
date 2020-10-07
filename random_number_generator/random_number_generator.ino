byte seven_seg_digits[15] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11110110,  // = 9
                              B00000001,  // = Tutto spento con punto acceso
                              B00000000,  // = Tutto spento
                              B01101110,  // = Lettera H
                              B10011110,  // = Lettera E
                              B00011100   // = Lettera L
                             };

// connect to the ST_CP of 74HC595 (pin 3,latch pin)
int latchPin = 3;
// connect to the SH_CP of 74HC595 (pin 4, clock pin)
int clockPin = 4;
// connect to the DS of 74HC595 (pin 2)
int dataPin = 2;

int pulsante=5, buzzer = 6, rele = 7;
int pulsanteStatus, cont=0, cont2=0, i=0;

bool spento=false, isRele=false;

// display a number on the digital segment display
void sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);

  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);

  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void bleep_bloop(){
  int prev=-1, m=0, n=random(15,50), suono=0, prevSound=-1;
  int i=0;
  for(i=0;i<n;i++){
    while(prev==m or prevSound==suono){
      m=random(0,10);
      suono=random(150,1000);
      }
    sevenSegWrite(m);
    if(isRele == false){
      tone(buzzer, suono);
      }
    prev=m;
    prevSound=suono;
    delay(100);
    }
    noTone(buzzer);
  }

void cycle(){
  for(i=0;i<10;i++){
    sevenSegWrite(i);
    delay(100);
  }

  delay(200);
  sevenSegWrite(11);
  delay(100);

  for(i=8;i>=0;i--){
    sevenSegWrite(i);
    delay(100);
  }

  sevenSegWrite(10);
  delay(300);
  sevenSegWrite(11);
 }

void greetings(){ //Questa funzione fa visualizzare "HELLO" appena si avvia lo sketch
  sevenSegWrite(12); //H
  delay(200);
  sevenSegWrite(11);
  delay(200);
  sevenSegWrite(13); //E
  delay(200);
  sevenSegWrite(11);
  delay(200);
  sevenSegWrite(14); //L
  delay(200);
  sevenSegWrite(11);
  delay(200);
  sevenSegWrite(14); //L
  delay(200);
  sevenSegWrite(11);
  delay(200);
  sevenSegWrite(0);  //O
  delay(200);
  sevenSegWrite(11);
  delay(500);
  cycle();
  }

void setup() {
  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(pulsante, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rele, OUTPUT);
  greetings();
  delay(200);

  sevenSegWrite(0);
}



void loop() {
  for(cont=0;cont<10000;cont++){
    pulsanteStatus=digitalRead(pulsante);
    if(pulsanteStatus==HIGH){
      digitalWrite(rele, LOW);
      bleep_bloop();
      isRele=false;
      cont=0;
      spento=false;
    }
    delay(1);
  }

    digitalWrite(rele, HIGH);
    isRele=true;
    delay(200);

}
