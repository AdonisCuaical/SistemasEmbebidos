# include <avr/power.h>
# include <avr/sleep.h>
# include <avr/wdt.h>
# include <EEPROM.h>
String modo = "";
int dato;
int on = 0;
String opcion;
void setup() {
  Serial.begin(9600);
  dato = EEPROM.read(0);
  eleccion(dato);
  attachInterrupt(0, modos, LOW);
  attachInterrupt(1, eleccion, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
void eleccion(int a) {
  switch (a) {
    case 1:
    Serial.println("15Ms"); 
      wdt_enable(WDTO_15MS);
      break;
    case 2:
    Serial.println("30Ms");
      wdt_enable(WDTO_30MS);
      break;
    case 3:
    Serial.println("60Ms");
      wdt_enable(WDTO_60MS);
      break;
    case 4:
    Serial.println("120Ms");
      wdt_enable(WDTO_120MS);
      break;
    case 5:
    Serial.println("250Ms");
      wdt_enable(WDTO_250MS);
      break;
    case 6:
    Serial.println("500Ms");
      wdt_enable(WDTO_500MS);
      break;
    case 7:
    Serial.println("1S");
      wdt_enable(WDTO_1S);
      break;
    case 8:
    Serial.println("2S");
      wdt_enable(WDTO_2S);
      break;
    case 9:
    Serial.println("4S");
      wdt_enable(WDTO_4S);
      break;
    case 10:
    Serial.println("8S");
      wdt_enable(WDTO_8S);
      break;
  }

}
void modos() {
  switch (on) {
    case 0:
      Serial.println("Sistema encendido");
      on++;
      break;
    case 1:
      Serial.println("Seleccione el valor de Reset"); 
      on++; 
      break;
      case 2:
      on=0;  
      break; 
  }

} void eleccion() {
  if (on == 1) {
   dato=analogRead(0); 
   dato=map(dato,0,1023,1,10);
   delay(1000); 
   EEPROM.write(0,dato);
   Serial.println(dato); 
    eleccion(dato); 
  }
}
