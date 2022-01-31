#ifndef ATMOSPHERE_HH
#define ATMOSPHERE_HH


class Atmosphere{

 public:
  
  //Constructors
  Atmosphere() {
    h_=0;
    F_=0;
    A_p_=0;
  }
  Atmosphere(double h,double F,double A);

  //Destructors
  ~Atmosphere() {}

  //Getters
  double h() const;
  double F() const;
  double A_p() const;

  //Setters
  void set_h(double h);
  void set_F(double F);
  void set_A_p(double A_p);

  //Utility
  void print();
  double mu(double h);
  double T(double F,double A_p);
  double rho(double h,double mu, double T);
  double D(double rho, double v,double A, double C_d);

 private:
  double h_;
  double F_;
  double A_p_;

};
#endif
