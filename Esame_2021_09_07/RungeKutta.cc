 #include "RungeKutta.h"

#include <cmath>
#include <vector>

using std::vector;

RungeKutta::RungeKutta(Velocity v0,double beta,double m,double g,double h) : SpeedCalculator(v0,beta,m,g){
  h_=h;
}

vector<Velocity> RungeKutta::velocity(double tmin,double tmax) const{
  vector<Velocity> v;

  double newvx=v0().vx();
  double newvy=v0().vy();
  double k1x=0;
  double k2x=0;
  double k1y=0;
  double k2y=0;

  for(double t=tmin;t<tmax;t=t+h_){
    k1x=-h_*newvx*beta()/m();
    k2x=-h_*(newvx+k1x*h_/2)*beta()/m();
    newvx+=k2x;

    k1y=-h_*(g()+beta()/m()*newvy);
    k2y=-h_*(g()+beta()/m()*(newvy+k1y*h_/2));
    newvy+=k2y;

    v.push_back(Velocity(newvx,newvy));
  }

  return v;
}
