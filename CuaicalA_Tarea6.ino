#include <MsTimer2.h>
int segundos = 0;
int minutos = 0;
int horas = 0;
int dec;
String alh;
String alm;
int uni;
int dec1;
int conversor1;
int conversor2;
int uni1;
int h;
int m;
int dec2;
int uni2;
int vec[6] = {2, 3, 4, 5, 6, 7};
int A = 11;
int B = 10;
int C = 9;
int D = 8;
void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(13, INPUT);
  for (int j = 0; j < 6; j++) {
    pinMode(vec[j], OUTPUT);
  }
  MsTimer2::set(1000, reloj);
  MsTimer2::start();
  Serial.println("Ingrese la hora a programar....");

}
void loop() {

  while (digitalRead(13) == HIGH) {
    delay(500);
    conversor1 = analogRead(A0);
    conversor1 = map(conversor1, 0, 1023, 0, 59);
    conversor2 = analogRead(A1);
    conversor2 = map(conversor2, 0, 1023, 0, 23);
    minutos = conversor1;
    horas = conversor2;
    dbj();
  }
  dbj();
  if (Serial.available() > 0) {
    alh = Serial.readString();
    Serial.println("Hora Ingresada...");
    Serial.println("Ingrese minutos.");
    delay(500);
    alm = Serial.readString();
    Serial.println("Minutos Ingresados");
    if (alh.toInt() >= 0 && alh.toInt() <= 23 && alm.toInt() >= 0 && alm.toInt() <= 59) {
      h = alh.toInt();
      m = alm.toInt();

    } else {
      Serial.println("Datos ingresados Erroneos...."); 
      h = 0;
      m = 0;
    }

  }
  if (h == horas && m == minutos) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
}




void reloj() {

  if (segundos < 60) {
    segundos++;
  } else {
    segundos = 0;
    if (minutos < 60) {
      minutos++;
    } else {
      minutos = 0;
      if (horas < 24) {
        horas++;
      } else {
        horas = 0;

      }
    }
  }
  dibujo(segundos, minutos, horas);


}
void contador (int i) {
  switch (i) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 10:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;




  }

}
void dibujo(int a , int b, int c) {
  if (a <= 59 && a >= 10) {// segundos
    dec = a / 10;
    uni = a - dec * 10;
  } else {
    uni = a;
  }
  if (b <= 59 && b >= 10) {//minutos
    dec1 = b / 10;
    uni1 = b - dec1 * 10;
  } else {
    uni1 = b;
  }

  if (c <= 23 && c >= 10) {//horas
    dec2 = c / 10;
    uni2 = c - dec2 * 10;
  } else {
    uni2 = c;
  }
}
void dbj() {

  digitalWrite(vec[0], LOW);
  digitalWrite(vec[1], HIGH);
  digitalWrite(vec[2], LOW);
  digitalWrite(vec[3], LOW);
  digitalWrite(vec[4], LOW);
  digitalWrite(vec[5], LOW);
  contador(dec);
  delay(100);
  digitalWrite(vec[0], HIGH);
  digitalWrite(vec[1], LOW);
  digitalWrite(vec[2], LOW);
  digitalWrite(vec[3], LOW);
  digitalWrite(vec[4], LOW);
  digitalWrite(vec[5], LOW);
  contador(uni);
  delay(100);
  digitalWrite(vec[0], LOW);
  digitalWrite(vec[1], LOW);
  digitalWrite(vec[2], LOW);
  digitalWrite(vec[3], HIGH);
  digitalWrite(vec[4], LOW);
  digitalWrite(vec[5], LOW);
  contador(dec1);
  delay(100);
  digitalWrite(vec[0], LOW);
  digitalWrite(vec[1], LOW);
  digitalWrite(vec[2], HIGH);
  digitalWrite(vec[3], LOW);
  digitalWrite(vec[4], LOW);
  digitalWrite(vec[5], LOW);
  contador(uni1);
  delay(100);
  digitalWrite(vec[0], LOW);
  digitalWrite(vec[1], LOW);
  digitalWrite(vec[2], LOW);
  digitalWrite(vec[3], LOW);
  digitalWrite(vec[4], LOW);
  digitalWrite(vec[5], HIGH);
  contador(dec2);
  delay(100);
  digitalWrite(vec[0], LOW);
  digitalWrite(vec[1], LOW);
  digitalWrite(vec[2], LOW);
  digitalWrite(vec[3], LOW);
  digitalWrite(vec[4], HIGH);
  digitalWrite(vec[5], LOW);
  contador(uni2);
  delay(100);
}
