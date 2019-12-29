//Jim vander heiden 29-12-2019
//The product compares previous value to current value in sensor tech
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A7;  // Analog input pin that the potentiometer is attached to


int gLed = 6; //green LED pin
int bLed = 3;//blueled pin
int previous=0;
int sensorValue=0;
void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(gLed,OUTPUT);
  pinMode(bLed,OUTPUT);
  Serial.begin(9600);// serial port for debugging 
}

void loop() {

  sensorValue = analogRead(analogInPin);
 
  if(sensorValue-previous>5){
    Serial.println("seen");

    digitalWrite(bLed,LOW);
    digitalWrite(gLed,HIGH);
    delay(1000);
    digitalWrite(gLed,LOW);
    digitalWrite(bLed,HIGH);
  }
    if(sensorValue-previous<-5){
    Serial.println("seen");
    digitalWrite(bLed,LOW);
    digitalWrite(gLed,HIGH);
    delay(1000);
    digitalWrite(gLed,LOW);
    digitalWrite(bLed,HIGH);
  }
  
  previous = sensorValue;
  delay(2);
}
