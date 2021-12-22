//***********************Phong Trinh - 31/03/2021*******************
//********************Engineering Sucess Center - UPEI*********************

const uint8_t pumPin = 2;
int sensorPin = A0; 
float sensorValue = 0;
const uint8_t buttonPin = 3;
const uint8_t ledPin = 13;
uint8_t ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pumPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  digitalWrite(pumPin,HIGH);
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin),buttonPressed,FALLING);
  delay(500);
}
//********************Set up for the Pump*********************
void loop() {
  sensorValue = analogRead(sensorPin);
  
  if(sensorValue>700)
  {
      digitalWrite(pumPin, LOW);
  }
  else
  {
    digitalWrite(pumPin, HIGH);
    }
 Serial.print("Moisture Level:");
 Serial.println(sensorValue);
 Serial.println();
 delay(1000);
}
//********************Set up for Interrupt Service Routine*********************
void buttonPressed (){
  ledState = !ledState;
  digitalWrite(ledPin,ledState); 
}
