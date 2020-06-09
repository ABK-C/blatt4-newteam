#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double zufall(int a, int c, int m)
{
  static int I;
  I=(a * I + c)%m;
  return double(I)/double(m);
}



int main()
 {
  
  int a1 = 5;
  int a2 = 205;
  int c1 = 3;
  int c2 = 29573;
  int m1 = 16;
  int m2 = 139968;
  int N = 1000000;
  int P_in = 0;


 for(int i = 0; i < N; ++i)
 {
   double Px = zufall(a2,c2,m2);
   double Py = zufall(a2,c2,m2);


   if(sqrt((Px*Px)+(Py*Py))<1)
   {
    ++P_in;
   }
 }
  double pi = 4.0 *P_in/N;
  double dpi =1.0 *P_in;
    dpi = dpi/N;
    dpi = 4.0 * dpi;
     cout << "d_Pi = " << dpi <<  ":" << pi << "\n";
  
  double p = 3.141592654/4.0;
  double EW = p*N;
  double Var = p*(1-p)*N;
  double sigma = 4*sqrt(Var)/N;

  cout << "V[N_in] = " << Var <<"\n";
  cout << "E[N_in] = " << EW <<"\n";
  cout << "N_in = " << P_in << "\n";
  cout << "Pi = " << pi << "\n";
  cout << "Sigma_Pi = " << sigma << "\n";
}