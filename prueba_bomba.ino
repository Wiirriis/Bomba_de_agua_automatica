int rele1 = 3;
const int pChismoso1 = A0;
const int pChismoso2 = A1;
const int pChismoso3 = A2;

void setup() {
  pinMode(rele1, OUTPUT);
  Serial.begin(9600);
  digitalWrite(rele1, LOW);
  Serial.println("Se terminó la comprobación");
  delay(5000);
}

void loop() {

  int humedad1 = analogRead(pChismoso1);
  int humedad2 = analogRead(pChismoso2);
  int humedad3 = analogRead(pChismoso3);
  Serial.println("Monitoreando: ");
  Serial.print("Humedad 1 "); Serial.println(humedad1);
  Serial.print("Humedad 2 "); Serial.println(humedad2);
  Serial.print("Humedad 3 "); Serial.println(humedad3);

  //TONEL VACIO
  if ( (humedad2 > 700) && (humedad1 > 700) ) {
    digitalWrite(rele1, LOW);
    Serial.println("Tanque vacío");
    Serial.print("Humedad 1 "); Serial.println(humedad1);
    Serial.print("Humedad 2 "); Serial.println(humedad2);
    Serial.print("Humedad 3 "); Serial.println(humedad3);
    delay(1000);
  }
  //TONEL LLENO
  else if ( (humedad1 < 700) && (humedad2 < 700)) {
    if (humedad3 > 700) { //TINACO VACIO? 
      digitalWrite(rele1, HIGH);
      Serial.println("Llenando...");
      Serial.print("Humedad 1 "); Serial.println(humedad1);
      Serial.print("Humedad 2 "); Serial.println(humedad2);
      Serial.print("Humedad 3 "); Serial.println(humedad3);
      delay(1000);
    }
  }
  //TINACO LLENO
  else if ( (humedad3 < 700)) {
    digitalWrite(rele1, LOW);
    Serial.println("Se apagó el rele");
    delay(1000);
  }

  delay(1000);
}
