// Funktionsweise:
// Der Kørsel folgt einem Weiß-Schwarz-Übergang (Kante) im Uhrzeigersinn und zeigt den Zustand der Reflektionslichtschranke mit der LED_onboard (D13) an.
// Reflektionsschranke über weißem/hellen Untergrund: LED_onboard an / linker Motor an / rechter Motor aus
// Reflektionsschranke über schwarzem/dunklem Untergrund: LED_onboard aus / linker Motor aus / rechter Motor an
// ----------------------------------------------------------
// Joachim Fessler / fessler@rwu.de / März 2020
// http://korsel.hs-weingarten.de


#define Motor_links 9
#define Motor_rechts 3
#define LED_onboard 13
#define Sensor A1
#define Motor_On 1000
#define Motor_Off 0


void setup()
{
  pinMode(Sensor, INPUT_PULLUP);      // Reflektionslichtschranke
  pinMode(LED_onboard, OUTPUT);       // LED auf dem Arduino Nano Board
  pinMode(Motor_rechts, OUTPUT);      // Ausgang (via NPN-Transistor) für den rechten Motor
  pinMode(Motor_links, OUTPUT);       // Ausgang (via NPN-Transistor) für den linken Motor
}


void loop()
{
  if (digitalRead (Sensor) == LOW)              // Weiße bzw. helle Oberfläche
  {
    digitalWrite(LED_onboard, HIGH);
    analogWrite(Motor_links, Motor_On);      // Linkes Rad an
    analogWrite(Motor_rechts, Motor_Off);      // Rechtes Rad aus
  }
  else                                      // Schwarze bzw. dunkle Oberfläche
  {
    digitalWrite(LED_onboard, LOW);
    analogWrite(Motor_rechts, Motor_On);     // Rechtes Rad an
    analogWrite(Motor_links, Motor_Off);       // Linkes Rad aus
  }

}
