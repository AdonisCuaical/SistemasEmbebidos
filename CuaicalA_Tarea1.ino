/*  UNIVERSIDAD TECNICA DEL NORTE
             FICA-CITEL
         SISTEMAS EMBEBIDOS
  Nombre: Cuaical Reascos Adonis Germanico
  Fecha: 23/11/2020
Ejercicio: 
Juego #1

Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones

Juego #2

Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones

Juego #3

Se encienden secuencialmente cada uno ellos (flexible a su criterio)

Juego #4

Para esta sección se decidió encender los leds secuencialmente de izquierda a aderecha, una vez llegue al final,
regrese encendiendo y apagando los leds hasta que cambiemos el estados del switch. 
*/
const int A = 13;
const int B = 12;
const int C = 11;
const int D = 10;
const int E = 9;
const int F = 8;
const int G = 7;
const int H = 6;
const int I = 5;
const int J = 4;
char  cont ;
int conta;
int k;
int contar;
int contar1;
int cont1;
int cont2;
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, INPUT);
  pinMode(H, INPUT);
  pinMode(I, INPUT);
  pinMode(J, INPUT);
}

void loop() {
  if (digitalRead(G) == LOW) {
    delay(1000);
    for (k = 0; k < 10; k++) {
      if (digitalRead(G) == HIGH) {
        k = 0;
        break;
      } else {
        digitalWrite(E, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(A, HIGH);
        delay(1000);
        digitalWrite(E, LOW);
        digitalWrite(C, LOW);
        digitalWrite(A, LOW);
        delay(1000);
      }
    }
  } else if (digitalRead(H) == LOW) {
    delay(1000);
    for (k = 0; k < 10; k++) {
      if (digitalRead(H) == HIGH) {
        k = 0;
        break;
      } else {
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        delay(1000);
        digitalWrite(F, LOW);
        digitalWrite(D, LOW);
        digitalWrite(B, LOW);
        delay(1000);
      }
    }
  }
  else if (digitalRead(I) == LOW) {
    delay(1000);

    for (conta = 13; conta > 7; conta--) {

      switch (conta) {
        case 8:
          cont = A;
          break;
        case 9:
          cont = B;
          break;
        case 10:
          cont = C;
          break;
        case 11:
          cont = D;
          break;
        case 12:
          cont = E;
          break;
        case 13:
          cont = F;
          break;
      }

      digitalWrite(cont, HIGH);
      delay(100);
      if (digitalRead(A) == HIGH) {
        conta = 13;
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);

        break;
      }
    }


  }
  else if (digitalRead(J) == LOW) {
    delay(100);

    for (contar = 13; contar > 7; contar--) {

      switch (contar) {
        case 8:
          cont1 = A;
          break;
        case 9:
          cont1 = B;
          break;
        case 10:
          cont1 = C;
          break;
        case 11:
          cont1 = D;
          break;
        case 12:
          cont1 = E;
          break;
        case 13:
          cont1 = F;
          break;
      }

      digitalWrite(cont1, HIGH);
      delay(100);

    }
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    for (contar1 = 8; contar1 < 14; contar1++) {

      switch (contar1) {
        case 8:
          cont2 = A;
          break;
        case 9:
          cont2 = B;
          break;
        case 10:
          cont2 = C;
          break;
        case 11:
          cont2 = D;
          break;
        case 12:
          cont2 = E;
          break;
        case 13:
          cont2 = F;
          break;
      }

      digitalWrite(cont2, HIGH);
      delay(100);

    }
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);


  }


}
