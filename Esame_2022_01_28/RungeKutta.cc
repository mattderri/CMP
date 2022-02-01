#include "RungeKutta.h"

#define G 6.67e-11
#define C_d 2
#define R 6.371e6

#include <cmath>
#include <vector>

using std::vector;

RungeKutta::RungeKutta(Satellite sat,Atmosphere atm, Planet planet,double dt):FlySatellite(sat,atm,planet){
  dt_=dt;
}
								    
vector<Velocity> RungeKutta::satellite(double tmin,double tmax) const{
  Satellite sat1;
  vector<Vector3D> r1;
  vector<Velocity> v;

  double k1x=0;
  double k2x=0;
  double k1y=0;
  double k2y=0;
  double k1z=0;
  double k2z=0;

  double h1x=0;
  double h2x=0;
  double h1y=0;
  double h2y=0;
  double h1z=0;
  double h2z=0;
  
  double vx=sat().v().vx();
  double vy=sat().v().vy();
  double vz=sat().v().vz();
  
  double x=sat().r().x();
  double y=sat().r().y();
  double z=sat().r().z();
  
  double T=atm().T();
  

  for(double t=tmin;t<tmax;t=t+dt_){

    double h=sat().h(x,y,z);
    double mu=atm().mu(h);
    double rho=atm().rho(h,mu,T);

    v.push_back(Velocity(vx,vy,vz));
    
    k1x=(-G*planet().M()*x/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx,vy,vz),sat().A(),C_d))*dt_;
    k1y=(-G*planet().M()*y/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx,vy,vz),sat().A(),C_d))*dt_;
    k1z=(-G*planet().M()*z/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx,vy,vz),sat().A(),C_d))*dt_;

    h1x=vx*dt_;
    h1y=vy*dt_;
    h1z=vz*dt_;
    
    k2x=(-G*planet().M()*x/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx+k1x,vy+k1y,vz+k1z),sat().A(),C_d))*dt_;
    k2y=(-G*planet().M()*y/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx+k1x,vy+k1y,vz+k1z),sat().A(),C_d))*dt_;
    k2z=(-G*planet().M()*z/(pow(sat().r2(x+R,y+R,z+R),1.5))+atm().D(rho,sat().v2(vx+k1x,vy+k1y,vz+k1z),sat().A(),C_d))*dt_;
    
    vx+=k2x;
    vy+=k2y;
    vz+=k2z;

    x+=h1x;
    z+=h1y;
    y+=h1z;
    
  }

  return v;

}
  
