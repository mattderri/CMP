#include "Capacitor.h"

#include <iostream>
#include <limits>

using namespace std;

//Constructors
Capacitor::Capacitor(double capacitance){
 
  while(capacitance<0){
    cout << "È stato definito un condensatore con capacità negativa! Inserire una capacità postiva:" << endl;
    cin >> capacitance;
    }

  /*if(capacitance<0){
    cout << "È stato definito un condensatore con una capacità negativa! Interrompo l'esecuzione del programma" << endl;
    exit(-1);
    }*/

  C_=capacitance; //[pF]

}

//Getters
double Capacitor::C() const { return C_; }

//Setters
void Capacitor::set_C(double C) {C_=C; }

//Member functions
void Capacitor::print() const {
  cout << "Il condensatore ha capacità " << C_  << "pF" << endl;
}

//Overload operators
Capacitor Capacitor::operator+(const Capacitor& rhs) const {
  //Condensatori in serie: 1/C=1/C1+1/C2=>C=(C1*C2)/(C1+C2)
  double C=(C_*rhs.C_)/(C_+rhs.C_); 
  return Capacitor(C); 
}

Capacitor Capacitor::operator||(const Capacitor& rhs) const {
  //Condensatori in parallelo: C=C1+C2
  double C=C_+rhs.C_;
  return Capacitor(C);
}
