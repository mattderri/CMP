#include "RungeKutta.h"

#include <cmath>
#include <vector>

using std::vector;

RungeKutta::RungeKutta(Satellite sat,Atmosphere atm, Planet planet,double dt):FlySatellite(sat,atm,planet){
  dt_=dt;
}
								    
vector<Satellite> RungeKutta::satellite(double tmin,double tmax) const{
  vector<Satellite> sat;

  double v_x=sat().v().

  
