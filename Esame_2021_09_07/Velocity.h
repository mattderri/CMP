#ifndef VELOCITY_HH
#define VELOCITY_HH

class Velocity{

 public:
  
  //Constructors
  Velocity() {
    vx_=0;
    vy_=0;
  }
  Velocity(double vx,double vy);

  //Destructors
  ~Velocity() {}

  //Getters
  double vx() const;
  double vy() const;

  //Setters
  void set_vx(double vx);
  void set_vy(double vy);

  //Utility
  void print();

  //Operators
  Velocity operator+(const Velocity& rhs) const;
  const Velocity operator=(const Velocity& rhs);

 private:
  double vx_;
  double vy_;

};
#endif
