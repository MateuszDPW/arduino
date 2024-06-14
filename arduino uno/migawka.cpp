#define LED_RED 12
#define LED_YELLOW 11
#define LED_GREEN 10
#define DELAY 700
// the setup function runs once when you press reset or power the board
void setup() {
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
  digitalWrite(LED_RED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                      // wait for a second
  digitalWrite(LED_RED, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(LED_YELLOW, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                      // wait for a second
  digitalWrite(LED_YELLOW, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(LED_GREEN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                      // wait for a second
  digitalWrite(LED_GREEN, LOW);   // turn the LED off by making the voltage LOW
}
