#include "Material.h"

#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Material::Material(double rho,double A,double Z,double I) { 
  rho_=rho; //Densità [g/cm^3]
  A_=A;     //Massa atomica
  Z_=Z;     //Carica [e]
  I_=I;     //Energia di ionizzazione media [eV] 
}

//Getters
double Material::rho() const { return rho_; }
double Material::A() const { return A_; }
double Material::Z() const { return Z_; }
double Material::I() const { return I_; }

//Setters
void Material::set_rho(double rho) {rho_=rho; }
void Material::set_A(double A) {A_=A; }
void Material::set_Z(double Z) {Z_=Z; }
void Material::set_I(double I) {I_=I; }

//Utility
void Material::print(){
  cout << "Densità: " << rho_ << "g/cm^3" << endl;
  cout << "Massa atomica: " << A_ << endl;
  cout << "Carica: " << Z_ << "e" << endl;
  cout << "Energia di ionizzazione: " << I_ << "eV" << endl;
}

//Member Functions
double Material::dEdx(Particle& particle){
  
  double K=sqrt(particle.p()*particle.p()+particle.m()*particle.m())-particle.m();              //Energia cinetica [GeV]
  double soglia=0.05;       //Energia di soglia [GeV]
  double loss=0.;
  double k=0.3;             //[MeV/g*cm^2]
  double m=511000;          //Massa dell'elettrone [eV]
  
  if(K>=soglia){
    
    loss=k*rho_*particle.q()*particle.q()*Z_*(log(2*m*particle.betagamma()*particle.betagamma()/I_)-particle.beta()*particle.beta())/(particle.beta()*particle.beta()*A_);
      }
  else{
    loss=particle.p()*particle.p();
  }
  
  return loss;
  
}

