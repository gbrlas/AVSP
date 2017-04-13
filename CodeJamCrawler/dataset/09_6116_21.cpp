#include <iostream> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <bitset> 

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define eps 1e-10
double dist(int x1,int y1,int x2,int y2){

   return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

bool es(vector<int> x,vector<int> y,vector<int> R,int N,double radio){
    double aux1,aux2,aux3;
    if(N==1) 
    return (R[0]<=radio);
    if(N==2) 
    return max(R[0],R[1])<=radio;
    else
    {
   aux3=max(dist(x[0],y[0],x[2],y[2])+R[0]+R[2],R[1]+0.0);
   aux1=max(dist(x[0],y[0],x[1],y[1])+R[0]+R[1],R[2]+0.0);
   aux2=max(dist(x[1],y[1],x[2],y[2])+R[1]+R[2],R[0]+0.0);
  
   
   if(aux1<=2*radio||aux2<=2*radio||aux3<=2*radio)
   return true;
   else 
   return false;
   }
    
    return true;
}

int main(){

int C,N;
cin>>C;

for(int ii=0;ii<C;ii++)
{
    cin>>N;
    vector<int> X(N);
 vector<int> Y(N);
 vector<int> RR(N);
 for(int i=0;i<N;i++) 
 {
    cin>>X[i]>>Y[i]>>RR[i];
 }
 double izq=0,der=2000;
 while(fabs(izq-der)>eps){
  double mid=(izq+der)/2;
  if(es(X,Y,RR,N,mid)) 
    der=mid;
  else izq=mid;
 }
 double res=(izq+der)/2;
 printf("Case #%d: %.7lf\n",ii+1,res);

}

return 0;
}

 

