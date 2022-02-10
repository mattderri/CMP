//AO
#include <iostream>
#include <fstream>
#include <iomanip>

#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "THStack.h"

#define c 3e8         //Velocità della luce [m/s]
#define tau_B 1.6e-12 //Tempo di vita medio mesone B [s]
#define tau_D 0.4e-12 //Tempo di vita medio mesone D [s]

using namespace std;

int main() {

  TString rootfname("./Output.root");
  TFile rfile(rootfname,"RECREATE");
  if(!rfile.IsOpen()){
    cout << "Problemi nel creare il file" << endl;
    exit(-1);
  }
  cout << "Storing output in root file " << rootfname << endl;

  TRandom* gen=new TRandom();
  gen->SetSeed(0);

  TLorentzVector p4_B;
  double m_B=5280; //Massa del mesone B [MeV]
  double p_B=2000; //Momento del mesone B [MeV]
  p4_B.SetPxPyPzE(p_B,0,0,sqrt(p_B*p_B+m_B*m_B));

  double m_pi=140; //Massa del pione [MeV]
  double m_D=1865; //Massa del mesone D [MeV]
  double m_K=494;  //Massa del kaone [MeV]

  //Momento dei prodotti di decadimento del mesone B
  double p=sqrt((m_B*m_B-(m_pi+m_D)*(m_pi+m_D))*(m_B*m_B-(m_pi-m_D)*(m_pi-m_D)))/(2*m_B);
  //Momento dei prodotti di decadimento del mesone D
  double p2=sqrt((m_D*m_D-(m_pi+m_K)*(m_pi+m_K))*(m_D*m_D-(m_pi-m_K)*(m_pi-m_K)))/(2*m_D);

  //Genero gli istogrammi
  TH1F hxB("hxB","Distanza percorsa dal mesone B con impulso 2GeV prima di decadere",200,0,10);
  TH1F hxD("hxD","Distanza percorsa dal mesone D prima di decadere",200,0,10);
  TH1F hDelta("hxD","Distanza tra il vertice di decadimento del mesone B e il vertice di decadimento del mesone D",200,0,10);
  TH1F hDelta_mis("hxD","Distanza misurata tra il vertice di decadimento del mesone B e il vertice di decadimento del mesone D",200,0,10);
  TH1F hK("hk","Distribuzione del momento del mesone K nel LAB",200,0,5000);
  TH1F hs("hs","Massa invariante",200,0,6000);

  ofstream ofile1;
  string ofname1("./dati.dat");
  ofile1.open(ofname1);
  ofile1 << "x_B" << "\t" << "x_D" << "\t" << "delta" << "\t" << "delta_mis" << endl;
  ofile1 << setprecision(3) << fixed;
    
  
  //Quadrimomento del pione, del mesone D e del kaone
  TLorentzVector p4_pi,p4_D,p4_K; 
  int i;
  //Distanza percorsa, distanza B decade, distanza D decade
  double xd,xB,xD; 
  double prob,pB,pD; 
  double step=0.001; //Incremento della distanza
  double s;          //Massa invariante
  double x,y,z;
  double delta,delta_mis;
  double xB_mis,xD_mis;

  for(i=0;i<int(1e4);i++){ //Genero 10^4 mesoni B
    
    xd=0.; 
    pB=1.; //Probabilità di non decadere a una distana x=0
    prob=0.;
    s=0.;
    gen->Sphere(x,y,z,1); //Genero tre direzioni casuali
    
    while(pB>prob){ //Itero finchè non decade
      xd+=step;
      //Probabilità di NON decadere dopo una distanza x
      pB=exp(-xd/p4_B.Beta()*p4_B.Gamma()*c*tau_B); 
      prob=((double) rand()/(RAND_MAX));
    }

    xB=xd;
    //Simulo una risoluzione sperimentale
    xB_mis=gen->Gaus(xB,xB*0.02); 
    hxB.Fill(xB); //Riempio l'istogramma

    //Quadrimomento del pione
    p4_pi.SetPxPyPzE(p*x,p*y,p*z,sqrt(m_pi*m_pi+p*p));
    //Quadrimomento del mesone D
    p4_D.SetPxPyPzE(-p*x,-p*y,-p*z,sqrt(m_D*m_D+p*p)); 
    //Calcolo la massa invariante
    s=sqrt((p4_pi.E()+p4_D.E())*(p4_pi.E()+p4_D.E())-(p4_pi.P()+p4_D.P())*(p4_pi.P()+p4_D.P())); 
    hs.Fill(s); //Riempio l'istogramma

    //Simulo il decadimento del mesone D
    pD=1.;
    prob=0.;

    while(pD>prob){
      xd+=step;
      pD=exp(-xd/p4_D.Beta()*p4_D.Gamma()*c*tau_D);
      prob=((double) rand()/(RAND_MAX));
    }

    xD=xd;
    xD_mis=gen->Gaus(xD,xD*0.02);
    hxD.Fill(xD);

    delta=xD-xB;
    delta_mis=xD_mis-xB_mis;
    hDelta.Fill(delta);
    hDelta_mis.Fill(delta_mis);

    ofile1 << xB << "\t" << xD << "\t" << delta << "\t" << delta_mis << endl;

    //Genero tre direzioni casuali
    gen->Sphere(x,y,z,1);
    //Quadrimomento del kaone
    p4_K.SetPxPyPzE(p2*x,p2*y,p2*z,sqrt(p2*p2+m_K*m_K));
    p4_K.Boost(p4_D.BoostVector()); //Boost nel LAB
    hK.Fill(p4_K.P()); //Riempio l'istogramma
  }

  TCanvas canv("canv","canvas for plotting",1280,1024);
  hxB.GetXaxis()->SetTitle("Distanza percorsa prima di decadere [m]");
  hxB.GetYaxis()->SetTitle("Eventi");
  hxB.Draw();
  canv.SaveAs("./xB_decadimento.pdf");

  hxD.GetXaxis()->SetTitle("Distanza percorsa prima di decadere [m]");
  hxD.GetYaxis()->SetTitle("Eventi");
  hxD.Draw();
  canv.SaveAs("./xD_decadimento.pdf");

  hDelta.GetXaxis()->SetTitle("Distanza [m]");
  hDelta.GetYaxis()->SetTitle("Eventi");
  hDelta.Draw();
  canv.SaveAs("./Delta_decadimento.pdf");

  hDelta_mis.GetXaxis()->SetTitle("Distanza [m]");
  hDelta_mis.GetYaxis()->SetTitle("Eventi");
  hDelta_mis.Draw();
  canv.SaveAs("./Delta_mis_decadimento.pdf");

  hK.GetXaxis()->SetTitle("Momento [MeV]");
  hK.GetYaxis()->SetTitle("Eventi");
  hK.Draw();
  canv.SaveAs("./K_momentum.pdf");
  

  hs.GetXaxis()->SetTitle("Massa invariante [MeV]");
  hs.GetYaxis()->SetTitle("Eventi");
  hs.Draw();
  canv.SaveAs("./massa_invariante.pdf");

  hxB.Write();
  hs.Write();
  hxD.Write();
  hDelta.Write();
  hDelta_mis.Write();
  hK.Write();

  rfile.Close();
  
  return 0;
}
