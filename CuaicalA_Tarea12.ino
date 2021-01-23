#import "datos.h"
#import "datosPrueba.h"
int auxmax = 0; // para columna 1
int auxmax1 = 0; // para columna 2
int auxmin1 = 2000;
int auxmin = 2000;


void setup() {
  Serial.begin(9600);

}

void loop() {
  //algoritmoKnn();
  //normalizarDatos();
  algoritmoKnn(3);// tomar en cuenta que si el numero de vecinos es par puede existir empate ..
  
}
void maxmin() {

  for (int i = 0; i < 100; i++) {
    if (lectura[i][0] > auxmax) {
      auxmax = lectura[i][0];
    } else {
      auxmax = auxmax;
    }
    if (lectura[i][1] > auxmax1) {
      auxmax1 = lectura[i][1];

    } else {
      auxmax1 = auxmax1;
    }
    if (lectura[i][0] < auxmin) {
      auxmin = lectura[i][0];
    } else {
      auxmin = auxmin;
    }
    if (lectura[i + 1][1] < auxmin1) {
      auxmin1 = lectura[i][1];
    } else {
      auxmin1 = auxmin1;
    }

  }
  /*Serial.println(auxmax);
    Serial.println(auxmax1);
    Serial.println(auxmin);
    Serial.println(auxmin1);
  */

}
void normalizarDatos() {
  maxmin();
  for (int i = 0; i < 100; i++) {
    lectura[i][0] = (lectura[i][0] - auxmin) / (auxmax - auxmin);
    lectura[i][1] = (lectura[i][1] - auxmin1) / (auxmax1 - auxmin1);
    //Serial.println(String(lectura[i][0])+String("-")+String(lectura[i][1]));
  }
  for (int i = 0; i < 30; i++) {
    dtPrueba[i][0] = (dtPrueba[i][0] - auxmin) / (auxmax -  auxmin);
    dtPrueba[i][1] = (dtPrueba[i][1] - auxmin1) / (auxmax1 - auxmin1);
    //Serial.println(String(lectura[i][0])+String("-")+String(lectura[i][1]));
  }

}
void algoritmoKnn(int num) {
  double auxl;
  double auxil;

  double dist[100][2];
  double distancia;
  //normalizarDatos();
  for (int j = 0; j < 30; j++) {
    for (int i = 0; i < 100; i++) {
      distancia = sqrt(pow(dtPrueba[j][0] - lectura[i][0], 2) + pow(dtPrueba[j][1] - lectura[i][1], 2));
      dist[i][0] = i;
      dist[i][1] = distancia;

    }
    for (int p = 0; p < 100; p++) {
      for (int t = 0; t < 100 - 1 ; t++) {
        if (dist[t][1] > dist[t + 1][1]) {
          auxl = dist[t][1];
          dist[t][1] = dist[t + 1][1];
          dist[t + 1][1] = auxl;
          // posición
          auxil = dist[t][0];
          dist[t][0] = dist[t + 1][0];
          dist[t + 1][0] = auxil;
          //Serial.println(dist[t][0]);


        }
        //Serial.println(auxl);

      }
      // Serial.println(minimo);

    }
    int cont = 0;
    int cont1 = 0;
    for (int n = 0; n < num; n++) {
      if (lectura[int(dist[0][n])][2] == 1) {
        cont++;
      } else if (lectura[int(dist[0][n])][2] == 2) {
        cont1++;

      }
    }
    Serial.println(String(cont) + String(cont1));
    delay(500);
    if (cont > cont1) {
      Serial.println(String(j) + String(".") + String("{") + String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(1) + String("},"));
      cont = 0;
      cont1 = 0;
    }
    if (cont1 > cont) {

      Serial.println(String(j) + String(".") + String("{") + String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(2) + String("},"));

      cont = 0;
      cont1 = 0;
    }



  }

}
