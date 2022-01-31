#ifndef RUNGEKUTTA_HH
#define RUNGEKUTTA_HH

#include "Satellite.h"
#include "FlySatellite.h"

#include <vector>

using stad::vector;

class RUngeKutta:public FlySatellite{

 public:
  RungeKutta(Satellite sat,Atmosphere atm,Planet planet,dt);
  ~RungeKutta() {}

  virtual vector<Satellite> satellite(double tmin,double tmax) const;

 private:
  double dt_
    };
#endif
  
