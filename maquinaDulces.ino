int rojo = 13;
int verde = 12;
int amarillo = 11;
int azul = 10;

int boton1 = 7;
int boton2 = 6;
int boton3 = 5;

int i=0;

//  Chicles $2
//  Galletas $3
//  Chocolate $4
//  Papas $5
//  Refresco $8

void setup() {
  Serial.begin(9600);

  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(azul, OUTPUT);

  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
}

void loop() {
   
  int lec = analogRead(A0);

  int estadoBoton1=digitalRead(boton1);
  int estadoBoton2=digitalRead(boton2);
  int estadoBoton3=digitalRead(boton3);

    
  if(lec<=512){
      delay(500);
      i++;
  }

  if(i==2){                       //  Chicles $2 
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
  }else if(i==3){                 //  Galletas $3
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
  }else if(i==4){                 //  Chocolate $4
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, LOW);
  }else if(i==5){                 //  Papas $5
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, HIGH);
  }else if(i<2){                  //  Apagar todo       
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
  }

  if(estadoBoton1 == HIGH){
    delay(1000);
    i=i-2;
  }else if(estadoBoton2 == HIGH){
    delay(1000);
    i=i-3;
  }else if(estadoBoton3 == HIGH){
    delay(1000);
    i=i-4;
  }

    
 Serial.println (i);
 
}