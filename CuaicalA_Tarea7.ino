# include <EEPROM.h>
String clave = "4563";
int direccion = 0;
String obtcl;
String data;
String lectura;
int l;
String c;
void setup() {
  Serial.begin(9600);
  if(EEPROM.get(0,data)=="  "){
  EEPROM.put(0, clave);
  direccion = sizeof(clave) + direccion;
  }
}

void loop() {


  if (direccion >= EEPROM.length()) {
    direccion = 0;
    delay(1000);
  }

  Serial.println(" ");
  Serial.println("Ingrese su clave: ");
  delay(1000);
  obtcl = Serial.readString();
  data = EEPROM.get(0, data);
  Serial.println(data);
  if (obtcl == data) {
    Serial.println(" ");
    Serial.println("Ingrese la nueva clave: ");
    delay(1000);
    clave = Serial.readString();
    EEPROM.put(0, clave);
    direccion=0; 
    direccion+= sizeof(clave); 
    Serial.println("");
    Serial.println("Contrasenia actualizada.....");
    Serial.println("");
    lectura = EEPROM.get(direccion, c);
    Serial.print(lectura);

  }
  else {
    Serial.println("");
    Serial.println("No se encontraron coincidencias");
    Serial.println("");
  }
  Serial.println("");


  obtcl = "";
  data = "";


}
