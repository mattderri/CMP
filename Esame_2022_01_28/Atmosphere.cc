#include "Atmosphere.h"
#include "Satellite.h"

#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Atmosphere::Atmosphere(double F,double A_p) {
  F_=F;
  A_p_=A_p;
}

//Getters
double Atmosphere::F() const {return F_;}
double Atmosphere::A_p() const {return A_p_;}

//Setters
void Atmosphere::set_F(double F) {F_=F;}
void Atmosphere::set_A_p(double A_p) {A_p_=A_p;}

//Utility
void Atmosphere::print(){
  cout << "ATMOSFERA" << endl;
  cout << "Flusso solare: " << F_ << " SFU" <<endl;
  cout << "Indice geomagnetico: " << A_p_ << endl;
}

double Atmosphere::mu(double h){
  double mu=27-0.012*((h/1000)-200);
  return mu;
}

double Atmosphere::T(){
  double T=900+2.5*(F_-70)+1.5*A_p_;
  return T;
}

double Atmosphere::rho(double h,double mu,double T){
  double rho=6e-10*exp(-(((h/1000)-175)*mu)/(T));
  return rho;
}

double Atmosphere::D(double rho,double v2,double A,double C_d){
  double D=-0.5*rho*v2*A*C_d;
  return D;
}
