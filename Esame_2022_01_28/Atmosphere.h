#ifndef ATMOSPHERE_HH
#define ATMOSPHERE_HH

#include "Satellite.h"


class Atmosphere{

 public:
  
  //Constructors
  Atmosphere() {
    F_=0;
    A_p_=0;
  }
  Atmosphere(double F,double A_p);

  //Destructors
  ~Atmosphere() {}

  //Getters
  double F() const;
  double A_p() const;

  //Setters
  void set_F(double F);
  void set_A_p(double A_p);

  //Utility
  void print();
  double mu(double h);
  double T();
  double rho(double h,double mu,double T);
  double D(double rho,double v,double A,double C_d);

 private:
  double F_;
  double A_p_;

};
#endif
