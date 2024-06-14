#define LED_RED 12
#define LED_YELLOW 11
#define LED_GREEN 10
#define POTENCJOMETR A0
#define DELAY 100

void turnOff(){
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);   
  digitalWrite(LED_GREEN, LOW); 
}

class Selector{
private:
  const int intervals;
  int previousState;
  int currentState;
  int pin;
  int intervalLength;
  bool isNewF;
public:
  Selector(int pin, const int intervals): intervals(intervals){ // pierwszy dotyczy pola w klasie, drugi jest argumentem przekazywanym w konstruktorze
    this->pin = pin;
    previousState = -1;
    intervalLength = 1023/intervals+1;
  }

  int getValue(){
    return currentState;
  }
  void update(){
    int valA = analogRead(pin);
    currentState = valA / intervalLength;

    if(currentState != previousState){
      currentState = currentState;
      isNewF = true;
    }else{
      isNewF = false;
    }
  }
  bool isNew(){
    return isNewF;
  }
};

Selector s1(A0, 3);

int val;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(LED_YELLOW, LOW);   
  digitalWrite(LED_GREEN, LOW); 
  }

// the loop function runs over and over again forever
void loop() {
  s1.update();
  if(s1.isNew()){
    turnOff();
    switch(s1.getValue()){
      case 0:
        digitalWrite(LED_RED, HIGH);
        break;
      case 1:
        digitalWrite(LED_YELLOW, HIGH);
        break;
      case 2:
        digitalWrite(LED_GREEN, HIGH);
        break;
    }
  }
  delay(DELAY);
}