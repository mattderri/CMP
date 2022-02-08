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
    cout << "problems creating root file. existing... " << endl;
    exit(-1);
  }
  cout << "storing output in root file " << rootfname << endl;

  TH1F hxmax10("hxmax10","Penetrazione massima per elettroni con energia 10MeV",200,0,1);
  TH1F hxmax1("hxmax1","Penetrazione massima per elettroni con energia 1GeV",200,0,1);
  TH1F hxmax100("hxmax100","Penetrazione massima per elettroni con energia 100GeV",200,0,1);

  Material Pb(11.35,207,82,823,0.56,7.4,0.6);

  double step=0.01; //[cm]
  double x;

  int i;

  for(i=0;i<int(1e4);i++){

    x=0;
    Particle electron10(0.511,1,10); //Elettrone con energia 10MeV
  
    while(electron10.E()>electron10.m()){
      Pb.loss(electron10,x);
      x+=step;
    }

    hxmax10.Fill(x);

  }

  for(i=0;i<int(1e4);i++){

    x=0;
    Particle electron1(0.511,1,1e3); //Elettrone con energia 1GeV
  
    while(electron1.E()>electron1.m()){
      Pb.loss(electron1,x);
      x+=step;
    }

    hxmax1.Fill(x);

  }

  x=0.;

  for(i=0;i<int(1e4);i++){

    x=0;
    Particle electron100(0.511,1,1e5); //Elettrone con energia 100GeV
  
    while(electron100.E()>electron100.m()){
      Pb.loss(electron100,x);
      x+=step;;
    }

    hxmax100.Fill(x);

  }

  TCanvas canv("canv","canvas for plotting",1280,1024);

  hxmax10.Draw();
  canv.SaveAs("./xmax-10mev.pdf");

  hxmax1.Draw();
  canv.SaveAs("./xmax-1gev.pdf");

  hxmax100.Draw();
  canv.SaveAs("./xmax-100gev.pdf");

  hxmax10.Write();
  hxmax1.Write();
  hxmax100.Write();

  rfile.Close();
  
  return 0;

}
