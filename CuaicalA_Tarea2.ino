/*  UNIVERSIDAD TECNICA DEL NORTE
             FICA-CITEL
         SISTEMAS EMBEBIDOS
  Nombre: Cuaical Reascos Adonis Germanico
  Fecha: 23/11/2020
  Ejercicio: Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99.
*/
const int A = 7;
const int B = 8;
const int C = 9;
const int D = 10;
const int E = 11;
const int F = 12;
const int G = 13;
int p = 1 ;
int aux = 0;
int n;
int uni;
int dec;

void setup() {
  pinMode(A, INPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  bool t = true;

  if (digitalRead(A) == HIGH) {
    delay(100);
    if ( p < 100 ) {
      p++;
      aux = p;
      while (t == true) {
        int m = 0;


        for (n = 1; n <= aux; n++) {
          if (aux % n == 0) {
            m++;
          }
        }

        if (m == 2) {
          t = false;
          if (aux < 10) {
            uni = aux;
          } else {
            dec = aux / 10;
            uni = aux - dec * 10;
          }
        } else {
          t = true;
          aux++;
        }

        t;
      } p = aux;
    } else {
      p = 0;
    }
  }

  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  contador(uni);
  delay(100);
  if (p > 9) {
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    contador(dec);
    delay(100);


  }
}

void contador (int i) {
  switch (i) {
    case 0:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      break;
    case 1:
      digitalWrite(E, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      break;
    case 2:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      break;
    case 3:
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      break;
    case 4:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      break;
    case 5:
      digitalWrite(E, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      break;
    case 6:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      break;
    case 7:
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(B, LOW);
      break;
    case 8:
      digitalWrite(E, LOW);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, HIGH);
      break;
    case 9:
      digitalWrite(E, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, HIGH);
      break;
    case 10:
      digitalWrite(E, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(B, HIGH);
      break;


  }

}
