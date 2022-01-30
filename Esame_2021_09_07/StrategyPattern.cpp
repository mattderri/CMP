#include "Velocity.h"
#include "Analytical.h"
#include "RungeKutta.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#define V0X  15.0   //[m/s]
#define V0Y  15.0   //[m/s[
#define M    25.0   //[kg[
#define BETA 0.15   //[N*s/m]
#define G    9.81   //[m/S]

using namespace std;

int main() {

  double dt=0.001;
  double h=0.001;
  Velocity v0(V0X,V0Y);
  v0.print();

  Analytical analytical(v0,BETA,M,G,dt);
  RungeKutta rungekutta(v0,BETA,M,G,h);

  double tmin=0.;
  double tmax=1.5;

  vector<Velocity> v_an;
  vector<Velocity> v_rk;
  v_an=analytical.velocity(tmin,tmax);
  v_rk=rungekutta.velocity(tmin,tmax);

  double t=0;
  ofstream ofile1;
  string ofname1("./Analytical_results.csv");
  ofile1.open(ofname1);
  ofile1 << "v_x" <<"\t"<< "v_y" <<"\t"<< "t" << endl;
  for(vector<Velocity>::const_iterator it=v_an.begin(); it != v_an.end(); ++it) {
    ofile1 << setprecision(5) << fixed;
    ofile1 << it->vx() <<"\t" << it->vy() <<"\t" << t << endl;
    t+=h;
  }

  ofile1.close();

  t=0;
  ofstream ofile2;
  string ofname2("./RungeKutta_results.csv");
  ofile2.open(ofname2);
  ofile2 << "v_x" << "\t" << "v_y" << "\t" << "t" << endl;
  for(vector<Velocity>::const_iterator it=v_rk.begin(); it != v_rk.end(); ++it) {
    ofile2 << setprecision(5) << fixed;
    ofile2 << it->vx() << "\t" << it->vy() << "\t" << t << endl;
    t+=h;
  }

  ofile2.close();
  
  return 0;
  
}
