#include "Particle.h"
#include "Material.h"

#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TF1.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  TString rootfname("./Electron_energyloss.root");
  TFile rfile(rootfname, "RECREATE");
  if( !rfile.IsOpen() ) {
    cout << "Problems creating root file. Existing... " << endl;
    exit(-1);
  }
  cout << "Storing output in root file " << rootfname << endl;

  TRandom* gen=new TRandom();
  gen->SetSeed(time(0));

  Material Pb(11.35,207.,82.,823.,0.56,7.4,0.6);

  double step=0.001; //[cm]
  double x10,x1,x100,x102;
  double xmean10,xmean1,xmean100;
  double xrms10,xrms1,xrms100;

  int i;
  double N=1e4;

  ofstream ofile10;
  string ofname10("./10MeV.dat");
  ofile10.open(ofname10);
  ofile10 << "x" << endl;
  ofile10 << setprecision(3) << fixed;

  for(i=0;i<int(1e4);i++){

    x10=0;
    Particle electron10(0.511,1,10); //Elettrone con energia 10MeV
    
    while(electron10.E()>electron10.m()){
      Pb.loss(electron10,10,x10,gen,step);
      x10+=step;
    }

    ofile10 << x10 << endl;

    xmean10+=x10/N;
    xrms10+=x10*x10;

  }

  xrms10=sqrt(xrms10/N);

  ofstream ofile1;
  string ofname1("./1GeV.dat");
  ofile1.open(ofname1);
  ofile1 << "x" << endl;
  ofile1 << setprecision(3) << fixed;

  for(i=0;i<int(1e4);i++){

    x1=0;
    Particle electron1(0.511,1,1e3); //Elettrone con energia 1GeV
    ofile1 << endl;
    while(electron1.E()>electron1.m()){
      Pb.loss(electron1,1e3,x1,gen,step);
      x1+=step;
    }

    ofile1 << x1 << endl;

    xmean1+=x1/N;
    xrms1+=x1*x1;

  }

  xrms1=sqrt(xrms1/N);
  
  ofstream ofile100;
  string ofname100("./100GeV.dat");
  ofile100.open(ofname100);
  ofile100 << "x" << endl;
  ofile100 << setprecision(3) << fixed;

  for(i=0;i<int(1e4);i++){

    x100=0;
    Particle electron100(0.511,1,1e5); //Elettrone con energia 100GeV
  
    while(electron100.E()>electron100.m()){
      Pb.loss(electron100,1e5,x100,gen,step);
      x100+=step;
    }

    ofile100 << x100 << endl;
    
    xmean100+=x100/N;
    xrms100+=x100*x100;

  }

  xrms100=sqrt(xrms100/N);

  rfile.Close();

  cout << endl;
  cout << setprecision(3) << fixed;
  cout << "10000 elettroni di energia 10MeV:" << endl;
  cout << "Penetrazione massima media: " << xmean10 << " cm" << endl;
  cout << "RMS: " << xrms10 << " cm" << endl;
  cout << "10000 elettroni di energia 1GeV:" << endl;
  cout << "Penetrazione massima media: " << xmean1 << " cm" << endl;
  cout << "RMS: " << xrms1 << " cm" << endl;
  cout << "10000 elettroni di energia 100GeV:" << endl;
  cout << "Penetrazione massima media: " << xmean100 << " cm" << endl;
  cout << "RMS: " << xrms100 << " cm" << endl;
  
  delete gen;
  
  return 0;

}
