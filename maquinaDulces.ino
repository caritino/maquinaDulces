int rojo = 13;
int verde = 12;
int amarillo = 11;
int azul = 10;

int boton1 = 7;
int boton2 = 6;
int boton3 = 5;
int boton4 = 4;

int i=0;

int ledA=28;
int ledB=30;
int ledC=32;
int ledD=34;
int ledE=36;
int ledF=38;
int ledG=40;
int ledH=42;

void cero(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, LOW);
}

void uno(){
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
}
void dos(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, HIGH);
}

void tres(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, HIGH);
}

void cuatro(){
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
}

void cinco(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
}

void seis(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
}

void siete(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
}

void ocho(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
}

void nueve(){
  digitalWrite(ledA, 1);
  digitalWrite(ledB, 1);
  digitalWrite(ledC, 1);
  digitalWrite(ledD, 1);
  digitalWrite(ledE, 0);
  digitalWrite(ledF, 1);
  digitalWrite(ledG, 1);
}

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
  pinMode(boton4, INPUT);

  int j;
  for(j=0;j<8;j++)
    pinMode(j,1);
}

void loop() {
   
  int lec = analogRead(A0);

  int estadoBoton1=digitalRead(boton1);
  int estadoBoton2=digitalRead(boton2);
  int estadoBoton3=digitalRead(boton3);
  int estadoBoton4=digitalRead(boton4);
    
  if(lec<=512){
      delay(500);
      i++;
  }

  if(i<=0){
    cero();
    i = 0;
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
  }else if(i==1){
    uno();
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
  }else if(i==2){                       //  Chicles $2 
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    dos();
  }else if(i==3){                 //  Galletas $3
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    tres();
  }else if(i==4){                 //  Chocolate $4
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, LOW);
    cuatro();
  }else if(i==5){                 //  Papas $5
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, HIGH);
    cinco();
  }else if(i==6){                 
    seis();
  }else if(i==7){                 
    siete();
  }else if(i==8){                 //  Refresco $8
    ocho();
  }else if(i>=9){                 
    nueve();
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
  }else if(estadoBoton4 == HIGH){
    delay(1000);
    i=i-8;
  }

  Serial.println (i); 
}
