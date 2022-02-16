//Includo la classe Capacitor.h
#include "Capacitor.h"

#include <iostream>
#include <fstream>
#include <iomanip>

//Includo le classi di ROOT per generare numeri casuali
#include "TRandom3.h"
#include "TFile.h"

using namespace std;

int main() {

  TString rootfname("./CapacitorOutput.root");
  TFile rfile(rootfname,"RECREATE");
  if(!rfile.IsOpen()){
    cout << "Problemi nel creare il file" << endl;
    exit(-1);
  }
  cout << "Storing output in root file " << rootfname << endl;

  TRandom* gen=new TRandom();
  gen->SetSeed(0);

  //Apro il file di output
  ofstream ofile;
  string ofname("./true.dat");
  ofile.open(ofname);
  ofile << "C1" << "\t" << "C_eq" << endl;
  ofile << setprecision(2) << fixed;
 
  double C1;
  double C2=10.;
  double C3=5.;
  double C4=15.;

  Capacitor capacitor2(C2);
  Capacitor capacitor3(C3);
  Capacitor capacitor4(C4);
  //Parallelo tra C3 e C4
  Capacitor c_eq_2=capacitor3.operator||(capacitor4);

  int i;
  int N=int(1e3);

  Capacitor capacitor1(1.);
  
  for(i=0;i<N;i++){
    //Genero casualmente C1 tra (0 e 99)+1
    C1=gen->Integer(100)+1;  
    //Capacitor capacitor1(C1);
    capacitor1.set_C(C1);
    //Parallelo tra C1 e C2
    Capacitor c_eq_1=capacitor1.operator||(capacitor2);
    //Serie tra i due condensatori equivalenti
    Capacitor c_eq=c_eq_1.operator+(c_eq_2);

    //Stampo sul file di output i valori di C1 e C_eq
    ofile << C1 << "\t" << c_eq.C() << endl;
    
  }

  delete gen;
  
  return 0;
}
