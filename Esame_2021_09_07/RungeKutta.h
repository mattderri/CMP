#ifndef RUNGEKUTTA_HH
#define RUNGEKUTTA_HH

#include "Velocity.h"
#include "SpeedCalculator.h"

#include <vector>

using std::vector;

class RungeKutta : public SpeedCalculator{
  
public:
  RungeKutta(Velocity v0,double beta,double m,double g,double dt);
  ~RungeKutta() {}

  virtual vector<Velocity> velocity(double tmin,double tmax) const;

private:
  double dt_;
};
#endif
