#ifndef VECTOR3D_HH
#define VECTOR3D_HH

class Vector3D {

 public:
  Vector3D() {
    x_=0;
    y_=0;
    z_=0;
  }
  Vector3D(double x,double y,double z);

  //Destructors
  ~Vector3D() {}

  //Getters
  double x() const;
  double y() const;
  double z() const;

  //Setters
  void set_x(double x);
  void set_y(double y);
  void set_z(double z);

  //Utility
  void print();

  //Operators
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;
  const Vector3D operator=(const Vector3D& rhs);
  Vector3D operator*(const double& rhs) const;
  Vector3D operator/(const double& rhs) const;

 private:
  double x_;
  double y_;
  double z_;

};
#endif

  
