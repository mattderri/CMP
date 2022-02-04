#include <iostream>
#include <cmath>

using namespace std;

//Constructors

Material::Material() { 
  rho_=0.; //Densità [g/cm^3]
  A_=0.;   //Masssa atomica
  Z_=0.;   //Carica [e]
  I_=0;    //Energia di ionizzazione media [eV] 
}
Material::Material(double density, double mass, double charge, double ionisation) { 
  rho_=density;    //Densità [g/cm^3]
  A_=mass;         //Masssa atomica
  Z_=charge;       //Carica [e]
  I_=ionisation;   //Energia di ionizzazione media [eV]
}
Material::Material(const Material& material) { 
  rho_=material.rho_; //Densità [g/cm^3]
  A_=material.A_;     //Masssa atomica
  Z_=material.Z_;     //Carica [e]
  I_=material.I_;     //Energia di ionizzazione media [eV]
}

//Getters

double Material::Getrho() const { return rho_; }
double Material::GetA() const { return A_; }
double Material::GetZ() const { return Z_; }
double Material::GetI() const { return I_; }

//Setters

double Material::Setrho(double rho) const { return rho_=rho; }
double Material::SetA(double A) const { return A_=A; }
double Material::SetZ(double Z) const { return Z_=Z; }
double Material::SetI(double I) const { return I_=I; }

//Member Functions

double Material::dEdX(Particle& particle){
  double K=sqrt(particle.p()*particle.p()+particle.m()*particle.m())-particle.m(); //[GeV]
  double soglia=0.05; //Energia di soglia [GeV]
  double loss=0.;
  double k=0.3; //[MeV/g*cm^2]
  double m=511000; //Massa dell'elettrone [eV]
  if(K>soglia){
    loss=k*rho_*particle.q()*particle.q()*Z_*[log(2*m*particle.betagamma()*particle.betagamma()/I_)-particle.beta()*particle.beta()-delta/2]/(particle.beta()*particle.beta()*A_);
      }
  else{
    loss=particle.p()*particle.p();
  }
  return loss;
  
}
