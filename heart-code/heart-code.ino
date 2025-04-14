const int ledPin = 3;
const int buzzer = 8;
#include "pitches.h"

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
    StayinAlive ();
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


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_G3,     // C B♭ A♭ G // Ah, ha, ha, ha
  NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4,      // E♭ F F F  // stayin' a-live
  NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4     // E♭ F F F  // stayin' a-live
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 2, 2, 2,   // Ah, ha, ha, ha
  8, 8, 8, 2,   // stayin' a-live
  8, 8, 8, 2    // stayin' a-live
};
// Function for melody
// iterate over the notes of the melody:
void StayinAlive () {
  for (int thisNote = 0; thisNote < 12; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
  }
