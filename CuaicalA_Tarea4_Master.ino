#include <Wire.h>
#include<LiquidCrystal.h>
//<librería.h> librería esta en la raiz del programa
//"libreria.h" librería en la ubicación del archivo
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //RS,E,D4,D5,D6,D7
char c;
int cont = 0;
int n; 
String palabra;
String mensaje = "";
void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Codificacion : ");
  lcd.setCursor(0,1);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println("Ingrese palabra");
    palabra = Serial.readString();
    n = palabra.length() + 1;
    char pal[n];
    palabra.toCharArray(pal, n);
    Wire.beginTransmission(4);// Enviar informacion al esclavo con id 4
    Wire.write(pal, n);
    Serial.println(String("Envio: ") + String(pal));
    Wire.endTransmission();
    delay(1000);
    Wire.requestFrom(4, n); // Solicitud de mensaje
    Serial.println("Mensaje recibido: ");
    while (Wire.available()) {
      c = Wire.read();
      lcd.print(n); 
      Serial.print(c);
     
      
    }n=0; 
  }
}
