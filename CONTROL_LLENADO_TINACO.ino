int TonelBajo = 3;
int TonelAlto = 4;
//int TinacoBajo = 5;
int TinacoAlto = 6;
int bomba = 7;

void setup() {
  Serial.begin(9600); 
  pinMode(TonelBajo, INPUT);
  pinMode(TonelAlto, INPUT);
  //pinMode(TinacoBajo, INPUT);
  pinMode(TinacoAlto, INPUT);
  pinMode(bomba, OUTPUT);
  digitalWrite(bomba, LOW);
  delay(1000);
}

void loop() {
  int TonelBajoState = digitalRead(TonelBajo);
  int TonelAltoState = digitalRead(TonelAlto);
  //int TinacoBajoState = digitalRead(TinacoBajo);
  int TinacoAltoState = digitalRead(TinacoAlto);
  int activo = 1;
  int inactivo = 0;

  Serial.print("TonelBajo :");
  Serial.println(TonelBajoState);
  Serial.print("TonelAlto: ");
  Serial.println(TonelAltoState);
  //Serial.print("TinacoBajo: ");
  //Serial.println(TinacoBajoState);
  Serial.print("TinacoAlto: ");
  Serial.println(TinacoAltoState);

  //TONEL VACIO
  if(TonelBajoState == inactivo && TonelAltoState == inactivo){
    digitalWrite(bomba, LOW);
  }

  //TINACO LLENO
  if(TinacoAltoState == activo){
    digitalWrite(bomba, LOW);
  }
  
  
  //TONEL LLENO, TINACO VACIO
  if(TonelBajoState == activo && TonelAltoState == activo ){ //TONEL LLENO?
      if(TinacoAltoState == inactivo){
        digitalWrite(bomba, HIGH);
      }
  }
  
  delay(1000);
}
