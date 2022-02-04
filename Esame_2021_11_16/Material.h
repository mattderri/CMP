class Material{

 public:

  //Contructors
  Material(); 
  Material(double density, double mass, double charge, double ionisation); 
  Material(const Material& material); 

  //Destructors
  ~Material();

  //Getters
  double rho() const;
  double A() const;
  double Z() const;
  double I() const;
  
  //Setters
  void Setrho(double rho);
  void SetA(double A);
  void SetZ(double Z);
  void SetI(double I);

  //Member functions
  double dEdx();

 private:
  double rho_;
  double A_;
  double Z_;
  double I_;
};
