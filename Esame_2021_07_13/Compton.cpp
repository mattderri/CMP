#include <iostream>
#include <time.h>

#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TF1.h"

#define m_e 511 //Massa dell'elettrone [KeV]

using namespace std;

//double E_Compton(double Ei, double theta);

int main(){

  TString rootfname("./Compton_scattering.root");
  TFile rfile(rootfname, "RECREATE");
  if( !rfile.IsOpen() ) {
    cout << "problems creating root file. existing... " << endl;
    exit(-1);
  }
  cout << "storing output in root file " << rootfname << endl;

  TRandom* gen=new TRandom();
  gen->SetSeed(time(NULL));

  TF1* f1=new TF1("f1", "1+cos(x)*cos(x)",0,M_PI);

  double E_0=662; //Energia del fotone [KeV]
  double resolution=0.025; //Risoluzione

  //Istogrammi (nome,titolo,numero di bin,range)
  TH1F hCosTheta("hCosTheta", "distribuzione dei cos(theta) generati", 200, -1, 1);
  TH1F hScat("hScat", "Distribuzione dell'energia dei fotoni diffusi", 300, 0, E_0*(1+10*resolution)+10);  
  TH1F hTot("hTot", "Distribuzione dell'energia di tutti i fotoni", 300, 0,  E_0*(1+10*resolution)+10);

  int i,p;
  double theta,E_f,E_mis;
  
  for(i=0;i<1e6;i++){

    p=gen->Integer(101);
    
    if(p<=65){
      
      theta=f1->GetRandom();
      hCosTheta.Fill(cos(theta));
      E_f=E_0/(1+(E_0/m_e)*(1-cos(theta)));
      E_mis=gen->Gaus(E_f,E_f*resolution);
      hScat.Fill(E_mis);
      hTot.Fill(E_mis);
    }

    else{

      E_mis=gen->Gaus(E_0,E_0*resolution);
      hTot.Fill(E_mis);
    }

  }

  TCanvas canv("canv","canvas for plotting",1280,1024);
  hCosTheta.GetXaxis()->SetTitle("cos(theta)");
  hCosTheta.GetYaxis()->SetTitle("cos(theta)");
  hCosTheta.Draw();
  canv.SaveAs("./costheta.pdf");
  

  return 0;

}
