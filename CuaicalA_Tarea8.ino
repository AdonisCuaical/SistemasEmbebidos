# include <avr/power.h>
# include <avr/sleep.h>
# include <avr/wdt.h>
# include <MsTimer2.h>
void (* resetFunc)(void) = 0;
int r = 0;
int on = 0;

boolean y = false;
void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000, reloj);
  MsTimer2::start();
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  attachInterrupt(0, configuracion, LOW);
  attachInterrupt(1, datos, LOW);

}

void loop() {
  if (r == 60) {
    Serial.println("Reiniciando Sistema....");
    delay(1000);
    resetFunc();
  } else {
    power_adc_enable();
   // Serial.println(String("Lectura: ") + String(analogRead(0)));
    sleep_enable();
  }
}
void reloj() {
  if (r < 60) {
    r++;
    

  }
}
void configuracion() {
  switch (on){
    case 0:
    Serial.println("CAD activado....");
    on++ ; 
    break;
    case 1: 
    Serial.println("Ingrese el valor"); 
    on++; 
    break; 
    case 2: 
    on=0; 
    break;  
    }
}
void datos(){
  if(on==1){
    power_adc_enable();
    Serial.println(String("Lectura: ") + String(analogRead(0)));
    sleep_enable();
    }
  }
