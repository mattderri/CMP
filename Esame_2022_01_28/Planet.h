#ifndef PLANET_HH
#define PLANET_HH

class Planet{

 public:
  
  //Constructors
  Planet() {
    M_=0;
    R_=0;
  }
  Planet(double M,double R);

  //Destructors
  ~Planet() {}

  //Getters
  double M() const;
  double R() const;

  //Setters
  void set_M(double M);
  void set_R(double R);

  //Utility
  void print();

  //Operators
  //Velocity operator+(const Velocity& rhs) const;
  //const Velocity operator=(const Velocity& rhs);

 private:
  double M_;
  double R_;

};
#endif
