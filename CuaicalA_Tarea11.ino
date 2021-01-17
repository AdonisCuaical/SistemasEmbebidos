int matriz[14][2] = {
  {170, 67},
  {180, 80},
  {170, 65},
  {178, 75},
  {160, 55},
  {163, 60},
  {165, 63},
  {170, 70},
  {164, 62},
  {176, 77},
  {164, 60},
  {170, 76},
  {170, 56},
  {168, 60},
};
int col = 0;
int fil = 0;
int Ex = 0;
int Ey = 0;
double Sx = 0;
double Slny = 0;
long double ExElny; 
long double x_2 = 0;
long double Sx_2 = 0;
long double Sxlny = 0;
long int Exy = 0;
long int Ex2 = 0;
long int Ex_2 = 0;
int n = 14;
float Bo;
long double B; 
long double lnA; 
float m;
String dato;
int estatura;
int peso;
int peso1; 
int m1;
long double lny; 
long double A; 


void setup() {
  Serial.begin(9600);
  regresionExponencial();  
  regresionLineal(); 
}
void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    estatura = dato.toInt();
    peso = m * estatura + Bo;
    peso1= A*exp(B*estatura); 
    Serial.println("");
    Serial.println(String("Peso con regresion lineal: ") + String(peso) + String("kg"));
    Serial.println(String("Peso con regresion exponencial: ") + String(peso1) + String("kg"));
    
    Serial.println("Ingrese su estatura: ");
    }
  
  
  }


void regresionLineal() {
  for (fil = 0; fil < n; fil++) {
    Ex = Ex + matriz[fil][0];
    Ey = Ey + matriz[fil][1];
    Exy = Exy + (matriz[fil][0] * matriz[fil][1]);
    Ex2 = Ex2 + pow(matriz[fil][0], 2);
  }
  
  Ex_2 = pow(Ex, 2);
  Bo = (float(Ex2 * Ey) - float(Ex * Exy)) / (float(n * Ex2 - Ex_2));
  m1 = (n * Exy) - (Ex * Ey);
  m = float(m1) / (float(n * Ex2 - Ex_2));
  //m = (float(n * Exy) - float(Ex * Ey)) / (float(n * Ex2 - Ex_2));
  Serial.println("El modelo lineal es: ");
  Serial.println(String("y= ") + String(m) + String("x")+ String(Bo));
  Serial.println("Ingrese su estatura: ");


}
void regresionExponencial() {
  for (fil = 0; fil < n; fil++) {
    Sxlny = Sxlny + matriz[fil][0] * log(matriz[fil][1]);
    Sx = Sx + matriz[fil][0];
    Slny = Slny + log(matriz[fil][1]);
    x_2 = x_2 + pow(matriz[fil][0], 2);
    lny=lny +log(matriz[fil][1]); 
  }
  ExElny=Sx*lny; 
  Sx_2=pow(Sx,2); 
  B=double((double(n*Sxlny)-double(ExElny))/(double((n*x_2)-Sx_2))); 
  lnA=double(lny/n)-double(B*(Sx/n)); 
  A=double(exp(lnA)); 
  Serial.println("El modelo exponencial es: ");
  Serial.println(String("y= ") + String(double(A)) +String("e")+String("^")+String("(")+String(double(B))+String("x")+String(")"));
   

}
