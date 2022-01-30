#include "Analytical.h"

#include <cmath>
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

Analytical::Analytical(Velocity v0,double beta,double m,double g,double dt) : SpeedCalculator(v0,beta,m,g){
  dt_=dt;
}

vector<Velocity> Analytical::velocity(double tmin,double tmax) const{
  vector<Velocity> v;

  double v_x=0.;
  double v_y=0.;
  
  for(double t=tmin;t<tmax;t+=dt_){

		
    v_x=v0().vx()*exp(-beta()*t/m());
    v_y=v0().vy()*exp(-beta()*t/m())-m()*g()/beta()*(1-exp(-beta()*t/m()));
		
    v.push_back(Velocity(v_x,v_y));
  }

  return v;
}
