#define PIN_BUTTON 7
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_BUTTON, OUTPUT);
}

void action(){
  Serial.print("Button pressed.");
  Serial.println(millis());
}

void loop() {
  if(digitalRead(PIN_BUTTON) == HIGH){
    delay(20);
    action();
    while(digitalRead(PIN_BUTTON) == HIGH){
      delay(20);
    }
  }
}
