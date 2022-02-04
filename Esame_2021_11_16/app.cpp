#include "Particle.h"
#include "Material.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  Particle alpha(3.73,4,10);
  Particle proton(0.94,1,10);
  Material Si(2.33,28,14,173);
  cout << "PARTICELLA ALPHA" << endl;
  alpha.print();
  cout << "PROTONE" << endl;
  proton.print();
  cout << "SILICIO" << endl;
  Si.print();

  double loss_p;
  double loss_a;
  double E_p=proton.E();
  double E_a=alpha.E();
  double x=0.;
  double dx=0.001;

  ofstream ofile1;
  ofstream ofile2;
  string ofname1("./Proton_loss.dat");
  string ofname2("./Alpha_loss.dat");
  ofile1.open(ofname1);
  ofile2.open(ofname2);
  ofile1 << "dE/dx" << "\t" << "x" << "\t" << "p" << "\t" << "betagamma" << endl;
  ofile2 << "dE/dx" << "\t" << "x" << "\t" << "p" << "\t" << "betagamma" << endl;

  while(proton.p()!=0){
    x=x+dx;
    loss_p=Si.dEdx(proton);
    E_p=E_p-loss_p*x;
    if(E_p>proton.m()){
      proton.set_p(sqrt(E_p*E_p-proton.m()*proton.m()));
    }
    else{
      proton.set_p(0);
    }
    ofile1 << setprecision(3) << fixed;
    ofile1 << loss_p << "\t" << x << "\t" << proton.p() << "\t" << proton.betagamma() << endl; 
  }

  x=0;;

  while(alpha.p()!=0){
    x=x+dx;
    loss_a=Si.dEdx(alpha);
    E_a=E_a-loss_a*x;
    if(E_a>alpha.m()){
      alpha.set_p(sqrt(E_a*E_a-alpha.m()*alpha.m()));
    }
    else{
      alpha.set_p(0);
    }
    ofile2 << setprecision(3) << fixed;
    ofile2 << loss_a << "\t" << x << "\t" << alpha.p() << "\t" << alpha.betagamma() << endl; 
  }

   cout << "PROTONE" << endl;
   proton.print();
   cout << "PARTICELLA ALPHA" << endl;
   alpha.print();
  

  return 0;

}
