#ifndef SATELLITE_HH
#define SATELLITE_HH

class Satellite{

 public:
  
  //Constructors
  Satellite() {
    m_=0;
    x_=0;
    y_=0;
    z_=0;
    vx_=0;
    vy_=0;
    vz_=0;
    A_=0;
  }
  Satellite(double m,double x,double y,double z,double vx,double vy,double vz,double A);

  //Destructors
  ~Satellite() {}

  //Getters
  double m() const;
  double x() const;
  double y() const;
  double z() const;
  double vx() const;
  double vy() const;
  double vz() const;
  double A() const;

  //Setters
  void set_m(double m);
  void set_x(double x);
  void set_y(double y);
  void set_z(double z);
  void set_vx(double vx);
  void set_vy(double vy);
  void set_vz(double vz);
  void set_A(double A);
  
  //Utility
  void print();

  //Operators
  //Velocity operator+(const Velocity& rhs) const;
  //const Velocity operator=(const Velocity& rhs);

 private:
  double m_;
  double x_;
  double y_;
  double z_;
  double vx_;
  double vy_;
  double vz_;
  double A_;

};
#endif
