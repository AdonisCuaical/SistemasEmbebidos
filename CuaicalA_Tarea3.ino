const int A = 13;
const int B = 12;
const int C = 11;
const int D = 10;
int cont = 0;
int num;
String respuesta;
int cr = 0;
int numa = 0;
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    delay(200);
    if (cont < 5) {

      num = numeroAleatorio();
      preguntas(num);
      respuesta = Serial.readString();
      respuesta.toLowerCase();
      verificacion(num, respuesta);
      cont++;
    }
    else if (cont >= 5) {
      envioDisplay(cr);
      Serial.println("____________________________");
      cont = 0;
    }
  }
}
void preguntas(int p) {
  switch (p) {
    case 1:
      Serial.println(" ");
      Serial.println("   ¿La capital del Carchi es Tulcán?  Si o No");
      break;
    case 2:
      Serial.println(" ");
      Serial.println("   ¿El factorial de 0 (0!) es 1?  Si o No");
      break;
    case 3:
      Serial.println(" ");
      Serial.println("   ¿En el S.I un micro significa 10^-2?  Si o No");
      break;
    case 4:
      Serial.println(" ");
      Serial.println("   ¿El número pi resulta de medir el perímetro de la circunferencia unitaria ?  Si o No");
      break;
    case 5:
      Serial.println(" ");
      Serial.println("   ¿El logaritmo es una madida?  Si o No");
      break;
    case 6:
      Serial.println(" ");
      Serial.println("   ¿Una compuerta AND suma las opciones?  Si o No");
      break;
    case 7:
      Serial.println(" ");
      Serial.println("   ¿El voltage se define como V=I*R?  Si o No" );
      break;
    case 8:
      Serial.println(" ");
      Serial.println("   ¿La velocidad de la luz es 3*10^8 m/s?  Si o No");
      break;


  }
}
String t;
void verificacion(int c , String text) {
  switch (c) {
    case 1:
      t = "si";
      break;
    case 2:
      t = "si";
      break;
    case 3:
      t = "no";
      break;
    case 4:
      t = "si";
      break;
    case 5:
      t = "no";
      break;
    case 6:
      t = "no";
      break;
    case 7:
      t = "si";
      break;
    case 8:
      t = "si";
      break;
  }
  if (text == t) {
    cr++;
  }
}

void envioDisplay (int i) {
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
int y;
int z;
int m ;
int g; 
int verf=0; 
int vec[8];
int numeroAleatorio() {
  y = random(1, 8);
  vec[cont]=y;
  if (cont>0){
  g=numerov(y);
  }else {
    g=y; 
    } 
  return g; 
}
int numerov(int x){
  for(int j=0; j<cont+1; j++){
    if(vec[j]== x){
      verf++; 
      } 
    }
    if (verf>0){
      z=numeroAleatorio(); 
      }else {
        z=x; 
        }
    return z; 
  }
