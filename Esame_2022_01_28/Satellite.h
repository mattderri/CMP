#ifndef SATELLITE_HH
#define SATELLITE_HH

#include "Velocity.h"
#include "Vector3D.h"

class Satellite{

 public:
  
  //Constructors
  Satellite(){
    m_=0;
    A_=0;
  }
  Satellite(double m,Vector3D r,Velocity v,double A);

  //Destructors
  ~Satellite() {}

  //Getters
  double m() const; 
  Vector3D r() const;
  double x() const;
  double y() const;
  double z() const;
  Velocity v() const;
  double vx() const;
  double vy() const;
  double vz() const;
  double A() const;

  //Setters
  void set_m(double m); 
  void set_r(Vector3D r); 
  void set_v (Velocity v);
  void set_A(double A);
  
  //Utility
  double v2(double vx,double vy,double vz);

  double r2(double x,double y,double z);

  double h(double x,double y,double z);

  void print();
  
 private:
  double m_;
  Vector3D r_;
  Velocity v_;
  double A_;

};
#endif
