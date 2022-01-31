#include "Velocity.h"

#include <iostream>

using namespace std;

//Constructors
Velocity::Velocity(double vx,double vy) {
  vx_=vx;
  vy_=vy;
}

//Getters
double Velocity::vx() const {return vx_;}
double Velocity::vy() const {return vy_;}

//Setters
void Velocity::set_vx(double vx) {vx_=vx;}
void Velocity::set_vy(double vy) {vy_=vy;}

//Utility
void Velocity::print(){
  cout << "Velocity: (" << vx_ << "," << vy_ << ")" << endl;
}

//Operators
Velocity Velocity::operator+(const Velocity& rhs) const {
  double vx=vx_+rhs.vx_;
  double vy=vy_+rhs.vy_;
  return Velocity(vx,vy);
}
const Velocity Velocity::operator=(const Velocity& rhs) {
  vx_ = rhs.vx_;
  vy_ = rhs.vy_;
  return *this;
}
