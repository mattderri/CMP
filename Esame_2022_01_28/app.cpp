#include "Satellite.h"
#include "Planet.h"
#include "Atmosphere.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#define M 5.972e24 //Massa della Terra [kg]
#define R 6371.    //Raggio della Terra [km]
#define F 80.      //Flusso solare [SFU]
#define A 50.      //Indice geomagnetico
#define m 1200.    //Massa del satellite [kg]

using namespace std;

int main() {

  Satellite sat(m,10,10,10,10,0,0,25);
  sat.print();
  Planet Earth(M,R);
  Earth.print();
  Atmosphere atm(1000,F,A);
  atm.print();

  
  return 0;

}
