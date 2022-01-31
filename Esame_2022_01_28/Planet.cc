#include "Planet.h"

#include <iostream>

using namespace std;

//Constructors
Planet::Planet(double M,double R) {
  M_=M;
  R_=R;
}

//Getters
double Planet::M() const {return M_;}
double Planet::R() const {return R_;}

//Setters
void Planet::set_M(double M) {M_=M;}
void Planet::set_R(double R) {R_=R;}

//Utility
void Planet::print(){
  cout << "Massa del pianeta: " << M_ << " kg" << endl;
  cout << "Raggio del pianeta: " << R_ << " km" << endl;
}
