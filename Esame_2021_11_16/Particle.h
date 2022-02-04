#ifndef PARTICLE_HH
#define PARTICLE_HH

class Particle{

 public:

  //Contructors
  Particle(){
    m_=0;
    q_=0;
    p_=0;
  }
  Particle(double m,double q,double p); 

  //Destructors
  ~Particle() {};

  //Getters
  double m() const;
  double q() const;
  double p() const;

  //Setters
  void set_m(double m);
  void set_q(double q);
  void set_p(double p);

  //Member functions
  double E();
  double beta();
  double gamma();
  double betagamma();

  //Utility
  void print();

 private:
  double m_;
  double q_;
  double p_;
};
#endif
