#ifndef PARTICLE_HH
#define PARTICLE_HH

class Particle{

 public:

  //Contructors
  Particle(){
    m_=0;
    q_=0;
    E_=0;
  }
  Particle(double m,double q,double E); 

  //Destructors
  ~Particle() {};

  //Getters
  double m() const;
  double q() const;
  double E() const;

  //Setters
  void set_m(double m);
  void set_q(double q);
  void set_E(double E);

  //Member functions
  double beta();
  double gamma();
  double betagamma();

  //Utility
  void print();

 private:
  double m_;
  double q_;
  double E_;
};
#endif
