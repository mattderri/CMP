#ifndef RUNGEKUTTA_HH
#define RUNGEKUTTA_HH

#include "Satellite.h"
#include "FlySatellite.h"
#include "Velocity.h"

#include <vector>

using std::vector;

class RungeKutta:public FlySatellite{

 public:
  RungeKutta(Satellite sat,Atmosphere atm,Planet planet,double dt);
  ~RungeKutta() {}

  virtual vector<Velocity> satellite(double tmin,double tmax) const;

 private:
  double dt_;
    };
#endif
  
