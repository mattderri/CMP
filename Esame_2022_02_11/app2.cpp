//Includo la classe Capacitor.h
#include "Capacitor.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

  double C1=10.;
  double C2=10.;

  Capacitor capacitor1(C1);
  Capacitor capacitor2(C2);
  //Serie tra C1 e C2
  Capacitor capacitor_series=capacitor1.operator+(capacitor2);
  //Parallelo tra C1 e C2
  Capacitor capacitor_parallel=capacitor1.operator||(capacitor2);
  cout << "Serie tra i due condensatori:" << endl;
  capacitor_series.print();
  cout << "Parallelo tra i due condensatori:" << endl;
  capacitor_parallel.print();
  
  return 0;
}
