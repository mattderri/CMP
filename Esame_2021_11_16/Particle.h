class Particle{

 public:

  //Contructors
  Particle(); 
  Particle(const Particle& particle); 

  //Destructors
  ~Particle();

  //Getters
  double m() const;
  double q() const;
  double p() const;

  //Setters
  void Setm(double m);
  void Setq(double q);
  void Setp(double p);

  //Member functions
  double beta();
  double gamma();
  double betagamma();

 private:
  double m_;
  double q_;
  double p_;

  Particle(double mass, double charge, double momentum) {
    m_ = momentum;
    q_ = charge;
    p_ = mass;
  };
};
