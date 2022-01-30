#ifndef SPEEDCALCULATOR_HH
#define SPEEDCALCULATOR_HH

#include "Velocity.h"
#include <vector>

using std::vector;

class SpeedCalculator{

 public:

  //Constructors
  SpeedCalculator(Velocity v0,double beta,double m,double g){
    v0_=v0;
    beta_=beta;
    m_=m;
    g_=g;
}

  //Getters
  virtual Velocity v0() const {return v0_;}
  virtual double beta() const {return beta_;}
  virtual double m() const {return m_;}
  virtual double g() const {return g_;}

  //Setters
  virtual void set_v0(Velocity v0) {v0_=v0;}
  virtual void set_beta(double beta) {beta_=beta;}
  virtual void set_m(double m) {m_=m;}
  virtual void set_g(double g) {g_=g;}

  virtual vector<Velocity> velocity(double tmin,double tmax) const = 0;


  private:
  Velocity v0_;
  double beta_;
  double m_;
  double g_;
};
#endif
