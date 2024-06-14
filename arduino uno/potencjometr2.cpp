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
  int currentState;
  int pin;
public:
  Selector(int pin, const int intervals): intervals(intervals){ // pierwszy dotyczy pola w klasie, drugi jest argumentem przekazywanym w konstruktorze
    this->pin = pin;

  }

  int getValue(){
    int intervalLenght = 1023/intervals+1;
    int valA = analogRead(pin);
    int val = valA / intervalLenght;
    return val;
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
  delay(DELAY);
}