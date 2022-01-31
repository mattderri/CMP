#include "Vector3D.h"

#include <iostream>

using namespace std;

//Constructors
Vector3D::Vector3D(double x,double y,double z) {
  x_=x;
  y_=y;
  z_=z;
}

//Getters
double Vector3D::x() const {return x_;}
double Vector3D::y() const {return y_;}
double Vector3D::z() const {return z_;}

//Setters
void Vector3D::set_x(double x) {x_=x;}
void Vector3D::set_y(double y) {y_=y;}
void Vector3D::set_z(double z) {z_=z;}

//Utility
void Vector3D::print(){
  cout << "Posizione: (" << x_ << "," << y_ << "," << z_ << ") m" << endl;
}

//Operators
Vector3D Vector3D::operator+(const Vector3D& rhs) const{
  double x=x_+rhs.x_; 
  double y=y_+rhs.y_;
  double z=z_+rhs.z_;
  return Vector3D(x,y,z);
}

const Vector3D Vector3D::operator=(const Vector3D& rhs) {
  x_=rhs.x_;
  y_=rhs.y_;
  z_=rhs.z_;
  return *this;
}
