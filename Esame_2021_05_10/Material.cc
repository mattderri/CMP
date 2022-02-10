#include "Material.h"

#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TF1.h"

#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Material::Material(double rho,double A,double Z,double I,double X0,double Ec,double delta) { 
  rho_=rho;    //Densità [g/cm^3]
  A_=A;        //Massa atomica
  Z_=Z;        //Carica [e]
  I_=I;        //Energia di ionizzazione media [eV]
  X0_=X0;      //Lunghezza di radiazione
  Ec_=Ec;      //Energia critica
  delta_=delta; //Delta
  srand48(time(NULL));
}

//Getters
double Material::rho() const { return rho_; }
double Material::A() const { return A_; }
double Material::Z() const { return Z_; }
double Material::I() const { return I_; }
double Material::X0() const { return X0_; }
double Material::Ec() const { return Ec_; }
double Material::delta() const { return delta_; }

//Setters
void Material::set_rho(double rho) {rho_=rho; }
void Material::set_A(double A) {A_=A; }
void Material::set_Z(double Z) {Z_=Z; }
void Material::set_I(double I) {I_=I; }
void Material::set_X0(double X0) {X0_=X0; }
void Material::set_Ec(double Ec) {Ec_=Ec; }
void Material::set_delta(double delta) {delta_=delta; }

//Utility
void Material::print(){
  cout << "Densità: " << rho_ << "g/cm^3" << endl;
  cout << "Massa atomica: " << A_ << endl;
  cout << "Carica: " << Z_ << "e" << endl;
  cout << "Energia di ionizzazione: " << I_ << "eV" << endl;
  cout << "Lunghezza di radiazione: " << X0_ << "cm" << endl;
  cout << "Energia critica: " << Ec_ << "MeV" << endl;
  cout << "Delta: " << delta_ << endl;
}

//Member Functions
void Material::loss(Particle& particle,double E0,double x,TRandom* gen,double dx){
  
  double k=0.3;             //[MeV/g*cm^2]
  double m=511000;          //Massa dell'elettrone [eV]
  double loss,loss_mis;
  double prob,p;

  if(particle.E()>Ec_){  //Bremsstrahlung

    prob=exp(-x/X0_);
    p=((double) lrand48()/(RAND_MAX));
    if(p>prob){
      particle.set_E(E0*exp(-x/X0_));
    }
  }

  else{ //Bethe-Bloch
    loss=k*rho_*Z_*(log(4*m*m*particle.betagamma()*particle.betagamma()*particle.betagamma()*particle.betagamma()/(I_*I_))-particle.beta()*particle.beta()-delta_/2)/(2*particle.beta()*particle.beta()*A_);

    loss_mis=gen->Gaus(loss,loss*0.05);
    particle.set_E(particle.E()-loss_mis*dx);
  }

  if(particle.E()<particle.m()){
    particle.set_E(particle.m());
    }
  
}
