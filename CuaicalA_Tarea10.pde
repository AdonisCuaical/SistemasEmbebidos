/*Universidad Técnica del Norte 
         FICA_CITEL
     Sistemas Embebidos
Nombre: Cuaical Reascos Adonis Germánico
Fecha: 11/01/2021

*/

int i=60; 
int j=60;
int r=60;
int r1=60; 
int a=60; 
int s=60; 
void setup() {
  background(#FAC7F1);
  size (900, 600, P3D);
  fill(125);
  translate(60, 60, 0);
  sphere(50);
}

void draw() {


  // keyPressed();
}
void keyPressed() {
  background(#FAC7F1);
   switch(key) {

  case 'a':
   background(#FAC7F1);
    translate(i, j, a);
    sphere(50);
    if (a<850) {
      a=a+20;
      s=a; 
     
    } else {
      a=0;
    }
    break;
     case 's':
   background(#FAC7F1);
    translate(i, j, s);
    sphere(50);
    if (s>60) {
      s=s-20;
      a=s; 
    } else {
      s=0;
    }
    break;
  } 
  switch(keyCode) {
  case 39:
    background(#FAC7F1);
    translate(i, j, a);
    sphere(50);
    if (i<850) {
      i=i+20;
      r=i;
    } else {
      i=0;
    }
    break;
  case 40: 
    background(#FAC7F1);
    translate(i, j, a);
    sphere(50);
    if (j<550) {
      j=j+20;
      r1=j;
    } else {
      j=0;
    }
    break;
  case 37: 

    background(#FAC7F1);

    translate(r, j, a);
    sphere(50);
    if (r>60 ) {
      r=r-20;
      i=r;
    } else {
      r=i;
    }
    break;
  case 38: 

    background(#FAC7F1);

    translate(i, r1, a);
    sphere(50);
    if (r1>60) {
      r1=r1-20;
      j=r1;
    } else {
      r1=j;
    }
    break;
  }
}
