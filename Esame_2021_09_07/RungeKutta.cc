 #include "RungeKutta.h"

#include <cmath>
#include <vector>

using std::vector;

RungeKutta::RungeKutta(Velocity v0,double beta,double m,double g,double dt) : SpeedCalculator(v0,beta,m,g){
  dt_=dt;
}

vector<Velocity> RungeKutta::velocity(double tmin,double tmax) const{
  vector<Velocity> v;

  double v_x=v0().vx();
  double v_y=v0().vy();
  double k1x=0;
  double k2x=0;
  double k1y=0;
  double k2y=0;

  for(double t=tmin;t<tmax;t=t+h_){
    k1x=-dt_*v_x*beta()/m();
    k2x=-dt_*(v_x+k1x*dt_/2)*beta()/m();
    v_x+=k2x;

    k1y=-dt_*(g()+beta()/m()*v_y);
    k2y=-dt_*(g()+beta()/m()*(v_y+k1y*dt_/2));
    v_y+=k2y;

    v.push_back(Velocity(v_x,v_y));
  }

  return v;
}
