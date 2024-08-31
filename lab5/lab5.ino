int analogPin = 32;
int val = 0;
int redPin = 5;
int greenPin = 18;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  Serial.print("val = "); 
  Serial.println(val); 
  if(val>=1000){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  else{
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
  delay(500);
}
