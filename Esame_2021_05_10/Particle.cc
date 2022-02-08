#include "Particle.h"

#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Particle::Particle(double m,double q,double E) { 
  m_=m;   //Massa [MeV]
  q_=q;   //Carica [e]
  E_=E;   //Energia [MeV]
}

//Getters
double Particle::m() const { return m_; }
double Particle::q() const { return q_; }
double Particle::E() const { return E_; }

//Setters
void Particle::set_m(double m) {m_=m; }
void Particle::set_q(double q) {q_=q; }
void Particle::set_E(double E) {E_=E; }

//Utility
void Particle::print(){
  cout << "Massa: " << m_ << "MeV" << endl;
  cout << "Carica: " << q_ << "e" << endl;
  cout << "Energia: " << E_ << "MeV" << endl;
}

//Member Functions
double Particle::beta(){
  double p=sqrt(E_*E_-m_*m_);
  return p/E_;
}

double Particle::gamma(){
  return E_/m_;
}

double Particle::betagamma(){
  double p=sqrt(E_*E_-m_*m_);
  return p/m_;
}
