#include "Particle.h"

#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Particle::Particle(double m,double q,double p) { 
  m_=m;   //Massa [GeV]
  q_=q;   //Carica [e]
  p_=p;   //Momento [GeV]
}

//Getters
double Particle::m() const { return m_; }
double Particle::q() const { return q_; }
double Particle::p() const { return p_; }

//Setters
void Particle::set_m(double m) {m_=m; }
void Particle::set_q(double q) {q_=q; }
void Particle::set_p(double p) {p_=p; }

//Utility
void Particle::print(){
  cout << "Massa: " << m_ << "GeV" << endl;
  cout << "Carica: " << q_ << "e" << endl;
  cout << "Momento: " << p_ << "GeV" << endl;
}

//Member Functions
double Particle::E(){
  return sqrt(m_*m_+p_*p_);
}
double Particle::beta(){
  double E=sqrt(m_*m_+p_*p_);
  return p_/E;
}

double Particle::gamma(){
  double E=sqrt(m_*m_+p_*p_);
  return E/m_;
}

double Particle::betagamma(){
  return p_/m_;
}
