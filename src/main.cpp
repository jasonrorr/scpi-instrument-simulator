#include <Arduino.h>
#include <String.h>

String serial_in;
String func;
String daSubs[5];

void establishContact() 
{
  while(Serial.available() <= 0) {
     Serial.println("Hewwo Mr. Obama?");
     delay(1000);
     Serial.println("H-Hewwo?!");
     delay(2000);
     // add in modulo and if/then to change responses based on which loop iteration we're on
  }
}

void setup() 
{
  // Setup
  pinMode(LED_BUILTIN, OUTPUT);

  // Listen for a serial connection 
  Serial.begin(9600);
  while (!Serial) {
    // Blink the built in LED until a connection is established
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  // After serial connection is established, send identifying info
  establishContact();
}

void loop() 
{
  // Once we get a valid response, do various things in response
  if (Serial.available() > 0) 
  {
    // get incoming byte:
    //inByte = Serial.read();
    serial_in = Serial.readStringUntil('\n'); // Read until newline
    {
      int colonPos, colonPos2, x;
      // find the function call and substrings
      colonPos = serial_in.indexOf(":");
      x=0;
      while (colonPos != -1 && (x < 5))
      {
        colonPos2 = serial_in.indexOf(":",colonPos+1);
        daSubs[x] = serial_in.substring(colonPos+1, colonPos2);
        colonPos = colonPos2;
        x++;
      }
    }
    Serial.println("oh hello");
    Serial.println("Command Received: " + serial_in);
    Serial.println("First Cmd Section: " + daSubs[0]);
    delay(1000);
  }
  else 
  {
    Serial.println("hewp me Mr. Obama pweaaase");
    delay(1000);
  }
}