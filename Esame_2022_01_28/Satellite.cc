#include "Velocity.h"
#include "Vector3D.h"
#include "Satellite.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//Constructors
Satellite::Satellite(double m,Vector3D r,Velocity v,double A) {
  m_=m;
  r_=r;
  v_=v;
  A_=A;
}

//Getters
double Satellite::m() const {return m_;}
Vector3D Satellite::r() const {return r_;}
Velocity Satellite::v() const {return v_;}
double Satellite::A() const {return A_;}

//Setters
void Satellite::set_m(double m) {m_=m;}
void Satellite::set_r(Vector3D r) {r_=r;}
void Satellite::set_v (Velocity v) {v_=v;}
void Satellite::set_A(double A) {A_=A;}
  
//Utility
double Satellite::v2(double vx,double vy,double vz){
  double v=vx*vx+vy*vy+vz*vz;
  return v;
}

double Satellite::r2(double x,double y,double z){
  double r=x*x+y*y+z*z;
  return r;
}

double Satellite::h(double x,double y,double z){
  double h=sqrt(x*x+y*y+z*z);
  return h;
}

void Satellite::print(){
  cout << "SATELLITE" << endl;
  cout << "Massa: " << m_ << " kg" << endl;
  cout << "Area della sezione trasversa: " << A_ << " m^2"<<endl;
  v_.print();
  r_.print();
}
