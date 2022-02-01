#ifndef FLYSATELLITE_HH
#define FLYSATELLITE_HH

#include "Velocity.h"
#include "Vector3D.h"
#include "Satellite.h"
#include "Atmosphere.h"
#include "Planet.h"
#include <vector>

using std::vector;

class FlySatellite{
  
 public:

  //Constructors
  FlySatellite(Satellite sat,Atmosphere atm,Planet planet){
    sat_=sat;
    atm_=atm;
    planet_=planet;

  }

  //Getters
  virtual Satellite sat() const {return sat_;}
  virtual Atmosphere atm() const {return atm_;}
  virtual Planet planet() const {return planet_;}

  //Setters
  virtual void set_sat(Satellite sat) {sat_=sat;}
  virtual void set_atm(Atmosphere atm) {atm_=atm;}
  virtual void set_planet(Planet planet) {planet_=planet;}

  virtual vector<Satellite> simulation(double tmin, double tmax) const=0;

 private:
  Satellite sat_;
  Atmosphere atm_;
  Planet planet_;
};
#endif
