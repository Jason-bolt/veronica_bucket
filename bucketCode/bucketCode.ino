#include <ccs811.h>

 /* Arduino example sketch to control a JSN-SR04T ultrasonic distance sensor with Arduino. No library needed. More info: https://www.makerguides.com */

// Define Trig and Echo pin:
#define trigPin 26 //2
#define echoPin 18 // 4
#define relay 22 // 7

// Define variables:
long duration;
int distance;

void setup() {
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
  // Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(5);

 // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance:
  distance = duration*0.034/2;
  
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance == 18){
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW); 
    delay(200);
  }

//    while (distance >= 18 && distance <= 22){
//      digitalWrite(relay, HIGH);
//      delay(2000);+
//      if (distance != 18){
//        digitalWrite(relay, LOW);
//        break;
//      }else{
//        continue;
//      }
//  }
  
  delay(500);
  
 
}
