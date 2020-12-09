int on = 0;
String dato;
int dato1 ;

#include <Servo.h>
Servo servo1;
void setup() {
  Serial.begin(9600);
  servo1.attach(6);
  servo1.write(0);
  attachInterrupt(0, modo, HIGH);
  attachInterrupt(1, encendido, HIGH);

}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    dato1 = dato.toInt();


  }
}
void encendido() {
  switch (on) {
    case 0:
      Serial.println("Inicio del sistema");
      Serial.println("Ingrese giro del motor 0<giro<180: ");
      on++;
      break;
    case 1:
           on++; 
      break;
     
    case 2:
      Serial.println("");
      Serial.println("Fin del programa");
      Serial.println("");
      on = 0;
      break;

  }
}
  void modo() {
    if (on == 1) {
      if (dato1 >= 0 && dato1 <= 180) {
        servo1.write(dato1);
      } else {
        Serial.println("");
        Serial.print("Ingrese un valor en el rago establecido");
        Serial.println("");
      }
    }
  }
