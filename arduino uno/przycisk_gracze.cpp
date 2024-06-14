#define PLAYER1 7
#define PLAYER2 6
#define PLAYER3 5
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PLAYER1, OUTPUT);
}

void action1(){
  Serial.println("#PLAYER 1 was first!#");
  Serial.println("######################");
  //Serial.println(millis());
}
void action2(){
  Serial.println("#PLAYER 2 was first!#");
  Serial.println("######################");
  //Serial.println(millis());
}
void action3(){
  Serial.println("#PLAYER 3 was first!#");
  Serial.println("######################");
  //Serial.println(millis());
}

void loop() {
  if(digitalRead(PLAYER1) == HIGH){
    delay(20);
    action1();
    while(digitalRead(PLAYER1) == HIGH){
      delay(20);
    }
  }
  if(digitalRead(PLAYER2) == HIGH){
    delay(20);
    action2();
    while(digitalRead(PLAYER2) == HIGH){
      delay(20);
    }
  }
  if(digitalRead(PLAYER3) == HIGH){
    delay(20);
    action3();
    while(digitalRead(PLAYER3) == HIGH){
      delay(20);
    }
  }
}
