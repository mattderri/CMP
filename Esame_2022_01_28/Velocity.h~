#ifndef VELOCITY_HH
#define VELOCITY_HH

class Velocity{

 public:
  
  //Constructors
  Velocity() {
    vx_=0;
    vy_=0;
    vz_=0;
  }
  Velocity(double vx,double vy,double vz);

  //Destructors
  ~Velocity() {}

  //Getters
  double vx() const;
  double vy() const;
  double vz() const;

  //Setters
  void set_vx(double vx);
  void set_vy(double vy);
  void set_vz(double vz);

  //Utility
  void print();

  //Operators
  Velocity operator+(const Velocity& rhs) const;
  const Velocity operator=(const Velocity& rhs);

 private:
  double vx_;
  double vy_;
  double vz_;

};
#endif
