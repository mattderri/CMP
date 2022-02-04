#include <iostream>
#include <cmath>

using namespace std;

//Constructors

Particle::Particle() { 
  m_=0.;   //Massa [GeV]
  q_=0.;   //Carica [e]
  p_=0.;   //Momento [GeV]
}
Particle::Particle(double mass, double charge, double momentum) { 
  m_= mass;       //Massa [GeV]
  q_= charge;     //Carica [e]
  p_= momentum;   //Momento [GeV]
}
Particle::Particle(const Particle& particle) { 
  m_=particle.m_;   //Massa [GeV]
  q_=particle.q_;   //Carica [e]
  p_=particle.p_;   //Momento [GeV]
}

//Getters

double Particle::Getm() const { return m_; }
double Particle::Getq() const { return q_; }
double Particle::Getp() const { return p_; }

//Setters

void Particle::Setm(double m) const {return m_=m; }
void Particle::Setq(double q) const {return q_=q; }
void Particle::Setp(double p) const {return p_=p; }

//Member Functions

double Particle::beta(){
  double E=sqrt(m_*m_+p_*p_);
  return p_/E;
}

double Particle::gamma(){
  double E=sqrt(m_*m_+p_*p_);
  return E/m_;
}

double Particle::betagamma(){
  return p_*m_;
}
