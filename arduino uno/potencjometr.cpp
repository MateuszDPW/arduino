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

  val = analogRead(POTENCJOMETR);
  Serial.println(val);
  delay(DELAY);
if(val<300){
  turnOff();
  digitalWrite(LED_RED, HIGH);
}else if(val <600){
  turnOff();
  digitalWrite(LED_YELLOW, HIGH);
}else {
  turnOff();
  digitalWrite(LED_GREEN, HIGH);
}
}