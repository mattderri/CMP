#ifndef MATERIAL_HH
#define MATERIAL_HH

#include "Particle.h"

class Material{

 public:

  //Contructors
  Material(){
    rho_=0;
    A_=0;
    Z_=0;
    I_=0;
  }
  Material(double rho,double A,double Z,double I); 

  //Destructors
  ~Material() {};

  //Getters
  double rho() const;
  double A() const;
  double Z() const;
  double I() const;
  
  //Setters
  void set_rho(double rho);
  void set_A(double A);
  void set_Z(double Z);
  void set_I(double I);

  //Utility
  void print();

  //Member functions
  double dEdx(Particle& particle);

 private:
  double rho_;
  double A_;
  double Z_;
  double I_;
};
#endif
