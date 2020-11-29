#include <Wire.h>
char c;
int aux;
String aux1;
String pr = "";
char salida;
char val[40];
int cont = 0;
char imp;
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);

}
void loop() {
  delay(100);
}
void receiveEvent(int bytes) {

  while (Wire.available()) {
    c = Wire.read();
    Serial.print(c);
    val[cont] = c;
    cont++;

  }
  aux = cont;

  cont = 0;
  for (int j = 0; j < aux+1 ; j++) {
    imp = codificacion(val[j]);
    //Serial.print(imp);
    pr = pr + imp;

  }
  aux1 = pr;
  pr = "";

}
void requestEvent() {

 Serial.print("Codificando: ");
 Serial.print(aux1);
  int tam = aux1.length() + 1;
  char ca[tam];
  aux1.toCharArray(ca, tam);


  Wire.write(ca, tam);


}
char codificacion(char valus) {

  switch (valus) {
    case 'a':
      salida = '@';
      break;
    case 'e':
      salida = '#';
      break;
    case 'i':
      salida =  '!';
      break;
    case 'o':
      salida =  '*';
      break;
    case 'u':
      salida =  '$';
      break;
    default:
      salida =  valus;
      break;
  }
  return salida;
}
