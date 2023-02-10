#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 10
#define stepPin 9
#define motorInterfaceType 1


// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

int joystickX = 0;

const int buttonPin = 2;
const int ledPin = 13;
int ledState = LOW; // LED-aren hasierako balioa
int buttonState; // Sakatzailearen oraingo egoera
int lastButtonState = LOW; // Sakatzailearen aurreko egoera

// DEBOUNCE denborak. 
unsigned long lastDebounceTime = 0; // Lehen aldiz sakatua 
unsigned long debounceDelay = 50; // Debounce denbora. 

const int buttonPinb = 3;
const int ledPinb = 12;
int ledStateb = LOW; // LED-aren hasierako balioa
int buttonStateb; // Sakatzailearen oraingo egoera
int lastButtonStateb = LOW; // Sakatzailearen aurreko egoera

// DEBOUNCE denborak. 
unsigned long lastDebounceTimeb = 0; // Lehen aldiz sakatua 
unsigned long debounceDelayb = 50; // Debounce denbora. 

const int buttonPinc = 4;
const int ledPinc = 11;
int ledStatec = LOW; // LED-aren hasierako balioa
int buttonStatec; // Sakatzailearen oraingo egoera
int lastButtonStatec = LOW; // Sakatzailearen aurreko egoera

// DEBOUNCE denborak. 
unsigned long lastDebounceTimec = 0; // Lehen aldiz sakatua 
unsigned long debounceDelayc = 50; // Debounce denbora. 
 

void setup() {
  Serial.begin(9600);
  stepper.stop();
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(500);
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  Serial.print("Sakatzailea sakatu zain...........");
  pinMode(buttonPinb, INPUT);
  pinMode(ledPinb, OUTPUT);
  digitalWrite(ledPinb, ledStateb);
  Serial.print("Sakatzailea sakatu zain...........");
  pinMode(buttonPinc, INPUT);
  pinMode(ledPinc, OUTPUT);
  digitalWrite(ledPinc, ledStatec);
  Serial.print("Sakatzailea sakatu zain...........");
}
void loop() {

  joystickX = analogRead(1); //  position kontrola
  
  Serial.print("Joystick-a: (X)  ");
  Serial.println(joystickX);

  while (joystickX < 153 ) {
    // Set the target position:
    stepper.move(500);
    stepper.run();
    joystickX = analogRead(1);
    delay(0);
  }
  while (joystickX > 953 ) {
    // Set the target position:
    stepper.move(-500);
    stepper.run();
    joystickX = analogRead(1);
    delay(0);
  }

  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) { //Sakatzailea sakatu
  lastDebounceTime = millis();   //Timerra inizializatu
}
  // Botoiaren egoera aldatu baldin bada:
  if ((millis() - lastDebounceTime) > debounceDelay) {
  if (reading != buttonState) {  // Botoia aldatu bada
  buttonState = reading; // Balioak eguneratu
  if (buttonState == HIGH) {//LED-a HIGH bada soilik
  ledState = !ledState;
  Serial.print("LED-a: ");
  Serial.println(ledState);
}
}
}    
  digitalWrite(ledPin, ledState); // LED-a freskatu
  lastButtonState = reading; // Balioak eguneratu

  int readingb = digitalRead(buttonPinb);{
  if (readingb != lastButtonStateb) { //Sakatzailea sakatu
  lastDebounceTimeb = millis();   //Timerra inizializatu
}
}
  // Botoiaren egoera aldatu baldin bada:
  if ((millis() - lastDebounceTimeb) > debounceDelayb) {
  if (readingb != buttonStateb) {  // Botoia aldatu bada
  buttonStateb = readingb; // Balioak eguneratu
  if (buttonStateb == HIGH) {//LED-a HIGH bada soilik
  ledStateb = !ledStateb;
  Serial.print("LED-a: ");
  Serial.println(ledStateb);
}
}
}  
  digitalWrite(ledPinb, ledStateb); // LED-a freskatu
  lastButtonStateb = readingb; // Balioak eguneratu

  int readingc = digitalRead(buttonPinc);
  if (readingc != lastButtonStatec) { //Sakatzailea sakatu
  lastDebounceTimec = millis();   //Timerra inizializatu
}
  // Botoiaren egoera aldatu baldin bada:
  if ((millis() - lastDebounceTimec) > debounceDelayc) {
  if (readingc != buttonStatec) {  // Botoia aldatu bada
  buttonStatec = readingc; // Balioak eguneratu
  if (buttonStatec == HIGH) {//LED-a HIGH bada soilik
  ledStatec = !ledStatec;
  Serial.print("LED-a: ");
  Serial.println(ledStatec);
}
}
}    
  digitalWrite(ledPinc, ledStatec); // LED-a freskatu
  lastButtonStatec = readingc; // Balioak eguneratu

}
  
