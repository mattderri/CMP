#include "Satellite.h"
#include "Planet.h"
#include "Atmosphere.h"
#include "Velocity.h"
#include "Vector3D.h"
#include "RungeKutta.h"
#include "FlySatellite.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

#define M 5.972e24 //Massa della Terra [kg]
#define R 6371e3    //Raggio della Terra [m]
#define F 80.      //Flusso solare [SFU]
#define A_p 50.    //Indice geomagnetico
#define m 1200.    //Massa del satellite [kg]
#define G 6.67e-11 //Costante di gravitazione universale [N*m^2*kg^-2]
#define C_d 2      //Drag coefficient [adimensionale]

using namespace std;

int main() {

  double r_0=250;
  double dt=0.01;
  double tmin=0.;
  double tmax=100.;

  Vector3D r(0,r_0,0);
  Velocity v(0,0,0);
  Satellite sat(m,r,v,0);
  sat.print();
  Planet Earth(M,R);
  Earth.print();
  Atmosphere atm(F,A_p);
  atm.print();

  RungeKutta rk(sat,atm,Earth,dt);

  vector<Satellite> sat_rk;

  sat_rk=rk.simulation(tmin,tmax);

  double t=0;
  ofstream ofile1;
  string ofname1("./RK_results.csv");
  ofile1.open(ofname1);
  ofile1 << "x" << "\t" << "y" << "\t" << "z" << "\t" << "v_x" << "\t" << "v_y" << "\t" << "v_z" << "\t" << "t" << endl;
  for(vector<Satellite>::const_iterator it=sat_rk.begin(); it != sat_rk.end(); ++it) {
    ofile1 << setprecision(5) << fixed;
    ofile1 << it->x() << "\t" << it->y() << "\t" << it->z() << "\t" << it->vx() << "\t" << it->vy() << "\t" << it->vz() << "\t" << t << endl;
    t+=dt;
  }

  ofile1.close();
  
  return 0;

}
