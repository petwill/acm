#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;
static double Tmax = 10, Tmin = 0.1, r = 0.999999;
static int k = 100;
inline void random_sele(int &fl, int &fp, int arr[], int n)
{
 do
 {
  fl = rand() % n;
  fp = rand() % n;
 } while (fl == arr[fp] || arr[fl] == arr[fp]);
};
inline bool accept(double r1, double r2, double T)
{
 const unsigned int MASK((1 << 30) - 1);
 double p = 1.0 / (1.0 + exp((r2 - r1) / T));
 unsigned int temp1=((rand()<<20)^(rand()<<10)^rand())&MASK;
 unsigned int temp2=((rand()<<20)^(rand()<<10)^rand())&MASK;
 double res=(1.0*temp1+1.0*temp2/MASK);
 return res < p*MASK;
}
void set_SA()
{
 printf("        Tmax            Tmin           r             k\n");
 printf("     %.8f     %.8f     %.8f       %d \n",Tmax,Tmin,r,k);
 printf("Input Tmax,Tmin,r,k:\n");
 scanf("%lf%lf%lf%d",&Tmax,&Tmin,&r,&k);
}
void TSP_SA(int arr[], double &evl, int n, double map[][2000])
{
 double r1, r2, T = Tmax;
 int i, fl, sl, fp, sp;
 int show_s=0;
 srand(11827);
 while (T >= Tmin)
 {
  for (i = 0; i < k; i++)
  {
   random_sele(fl, fp, arr, n);
   sl = arr[fl], sp = arr[fp];
   r1 = map[fl][sl] + map[fp][sp] + map[sp][arr[sp]];
   r2 = map[fl][sp] + map[sp][sl] + map[fp][arr[sp]];
   if (accept(r1, r2, T))
   {
    arr[fp] = arr[sp];
    arr[fl] = sp;
    arr[sp] = sl;
    sl = sp;
    evl = evl + r2 - r1;
   }
  }
  if(++show_s==1000000/k)
  {
   printf("T=%f evl=%f\n",T,evl);
   show_s=0;
  }
  T *= r;
 }
}
