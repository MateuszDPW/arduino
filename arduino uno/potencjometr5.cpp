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
void fLedRed(void){
  turnOff();
  digitalWrite(LED_RED, HIGH);
}
void fLedYellow(void){
  turnOff();
  digitalWrite(LED_YELLOW, HIGH);
}
void fLedGreen(void){
  turnOff();
  digitalWrite(LED_GREEN, HIGH);
}
typedef void(*action)(void);
class Selector{
private:
  const int intervals;
  int previousState;
  int currentState;
  int pin;
  int intervalLength;
  bool isNewF;
  action *actions;
 // void (*action[3])(void) = {fLedRed, fLedYellow, fLedGreen};
  

public:
  Selector(int pin, const int intervals): intervals(intervals){ // pierwszy dotyczy pola w klasie, drugi jest argumentem przekazywanym w konstruktorze
    this->pin = pin;
    previousState = -1;
    intervalLength = 1023/intervals+1;

    //wsk = new int[5];
    //wsk[2];
    //action = new void (*)(void)[3];
    actions = new action[intervals];
    actions[0] = fLedRed;
    actions[1] = fLedYellow;
    actions[2] = fLedGreen;
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
      actions[currentState]();
    }else{
      isNewF = false;
    }
  }
  bool isNew(){
    return isNewF;
  }
};

Selector s1(POTENCJOMETR, 3);

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
  delay(DELAY);
}