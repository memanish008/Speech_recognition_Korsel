
// How to control the RGB Led and Power Led of the Nano 33 BLE boards.  

 #define RED 22     
 #define BLUE 24     
 #define GREEN 23
 #define LED_PWR 25

void setup() {
 
 // intitialize the digital Pin as an output
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(LED_PWR, OUTPUT);

}

// the loop function runs over and over again
void loop() {
  digitalWrite(RED, LOW); // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  digitalWrite(GREEN, LOW);
  delay(1000);  
  digitalWrite(BLUE, LOW);
  delay(1000);  
  digitalWrite(RED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                         
  digitalWrite(GREEN, HIGH);
  delay(1000);  
  digitalWrite(BLUE, HIGH);
  delay(1000);  
  digitalWrite(LED_PWR, HIGH);
  delay(1000);  
  digitalWrite(LED_PWR, LOW);
  delay(1000);  
}
