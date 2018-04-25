#include <iostream>
#include <cmath>
using namespace std;

void u_in(double* u,double x_min,double delta_x, int n){
  for (int i=0; i<n; i++){
    double x = x_min + i*delta_x;
    if(abs(x)  <= 0.5){
      u[i] = 0.5;
    }
    if(abs(x) > 0.5){
      u[i] = 0;
    }
  }
}

void derivada(double *u_nuevo, double *u_viejo, int n, double delta_x, double delta_t, double c){

  for(int i=1;i<n-1;i++)
      {
	u_nuevo[i]=u_viejo[i]-c*(delta_t/delta_x)*(u_viejo[i]-u_viejo[i-1]);
      }
}


int main(){
  double *u;
  double delta_x = 0.001, delta_t = 0.001;
  double x_min = -2.0, x_max = 2.0;
  double c =1;
  int nx = (x_max-x_min)/delta_x + 1;
  int nt = 700; 
  double *u_nuevo;
  double *u_viejo;
  double *u_ini;
  double *u1;
  double *u2;
  double *u3;
  u_nuevo= new double[nx];
  u_viejo= new double[nx];
  u_ini = new double[nx];
  u1 = new double[nx];
  u2 = new double[nx];
  u3 = new double[nx];
  u_in(u_ini,x_min,delta_x, nx);
  u_in(u_viejo,x_min,delta_x, nx);
  for(int j=1;j<nt;j++){
    derivada(u_nuevo, u_viejo, nx, delta_x, delta_t, c);
    for(int i=0;i<nx;i++)
    {
      u_viejo[i]=u_nuevo[i];
    }
  }
  double x=0;		
  for(int i=0;i<nx;i++)
    {
      x=x_min + i*delta_x;
      cout<<x<<" "<< u_ini[i]<< " " <<u_nuevo[i]<<endl;
    }
  return 0;
  
}
