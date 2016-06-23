#include <Display.h>
int rojo =13,verde=12,amarillo=11;
int boton1 = 7, boton2=6, boton3=5;

Display dis(26,28,30,32,34,36,38);
int i=0;


void setup() {
  Serial.begin(9600);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
}

void loop() {
   
int lec = analogRead(A0);

int eboton1=digitalRead(boton1);
int boton2=digitalRead(boton2);
int boton3=digitalRead(boton3);

    
    if(lec<=512){
      delay(500);
      i++;
    
      }

  if(i==2){
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
  }else if(i>2 && i==4){
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, LOW);
  }else if(i>4 && i==6){
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
  }else if(i<2){
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
  }

  if(eboton1 == HIGH){
    delay(1000);
    i=i-2;
  }else if(
    
 Serial.println (i);
 
}
