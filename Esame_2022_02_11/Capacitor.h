#ifndef Capacitor_h
#define Capacitor_h

class Capacitor{

 public:

  //Contructors
  Capacitor(){
    C_=0;
  }
  Capacitor(double capacitance); 

  //Destructors
  ~Capacitor() {};

  //Getters
  double C() const;

  //Setters
  void set_C(double C);

  //Utility
  void print();

  //Overload operators
  Capacitor operator+(const Capacitor& rhs) const;
  Capacitor operator||(const Capacitor& rhs) const;

 private:
  double C_;
};
#endif
