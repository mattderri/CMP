#ifndef SATELLITE1_HH
#define SATELLITE1_HH

#include "Velocity.h"
#include "Vector3D.h"
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

class Satellite{

 public:
  
  //Constructors
  Satellite(double m,Vector3D r,Velocity v,double A) {
    m_=m;
    r_=r;
    v_=v;
    A_=A;
  }
  //Satellite(double m,double x,double y,double z,Velocity v,double A);

  //Destructors
  ~Satellite() {}

  //Getters
  virtual double m() const {return m_;}
  virtual Vector3D r() const {return r_;}
  virtual Velocity v() const {return v_;}
  virtual double A() const {return A_;}

  //Setters
  virtual void set_m(double m) {m_=m;}
  virtual void set_r(Vector3D r) {r_=r;}
  virtual void set_v (Velocity v) {v_=v;}
  virtual void set_A(double A) {A_=A;}
  
  //Utility
  void print(){
    cout << "SATELLITE" << endl;
    cout << "Massa: " << m_ << " kg" << endl;
    cout << "Area della sezione trasversa: " << A_ << " m^2"<<endl;
    v_.print();
    r_.print();
  };

  //Operators
  //Velocity operator+(const Velocity& rhs) const;
  //const Velocity operator=(const Velocity& rhs);

 private:
  double m_;
  Vector3D r_;
  Velocity v_;
  double A_;

};
#endif
