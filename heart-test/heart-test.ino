const int ledPin = 3;
const int buzzer = 8;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  pinMode (ledPin, OUTPUT); //LED
  pinMode(buzzer, OUTPUT); //Piezo

}

void loop() {
  
  if((digitalRead(10) == 1 )||(digitalRead(11) == 1)){
   digitalWrite(ledPin, HIGH); //LED turns on
   tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000); // ... for 1 second
   Serial.println('!'); //! prints in the serial monitor
  }
  else{
    // send the value of analog input 0:
      Serial.println(analogRead(A0));
      digitalWrite(ledPin, LOW); //LED turns off
      noTone(buzzer);     // Stop sound...
      delay(1000);         // ...for 1sec
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
