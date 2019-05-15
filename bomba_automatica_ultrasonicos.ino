// defines pins numbers
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int rele1 = 6;
// defines variables
long duration1, duration2;
int distance1, distance2;

//DISTANCIA 1 = TONEL
//DISTANCIA 2 = TINACO
void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin1 as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin1 as an Input
pinMode(rele1, OUTPUT);
digitalWrite(rele1, HIGH);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
//ULTRASONICO ABAJO
// Clears the trigPin1
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin1 on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin1, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance1
distance1= duration1*0.034/2;
// Prints the distance1 on the Serial Monitor
Serial.print("distance1: ");
Serial.println(distance1);

//ULTRASONICO ARRIBA
// Clears the trigPin1
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin1 on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin1, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance1
distance2= duration2*0.034/2;
// Prints the distance1 on the Serial Monitor
Serial.print("distance2: ");
Serial.println(distance2);



//REL
if(distance1 < 100 && distance2 >=100){
  digitalWrite(rele1, LOW);
}else if(distance1 >=100){
  digitalWrite(rele1, HIGH);
}else{
  digitalWrite(rele1, HIGH);
}
delay(10000);


}
