#ifndef MATERIAL_HH
#define MATERIAL_HH

#include "Particle.h"
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TF1.h"

class Material{

 public:

  //Contructors
  Material(){
    rho_=0;
    A_=0;
    Z_=0;
    I_=0;
    X0_=0;
    Ec_=0;
    delta_=0;
    srand(time(NULL));
  }
  Material(double rho,double A,double Z,double I,double X0,double Ec,double delta); 

  //Destructors
  ~Material() {};

  //Getters
  double rho() const;
  double A() const;
  double Z() const;
  double I() const;
  double X0() const;
  double Ec() const;
  double delta() const;
  
  //Setters
  void set_rho(double rho);
  void set_A(double A);
  void set_Z(double Z);
  void set_I(double I);
  void set_X0(double X0);
  void set_Ec(double Ec);
  void set_delta(double delta);

  //Utility
  void print();

  //Member functions
  void loss(Particle& particle,double E0,double x,TRandom* gen,double dx);

 private:
  double rho_;
  double A_;
  double Z_;
  double I_;
  double X0_;
  double Ec_;
  double delta_;
};
#endif
