//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long tests,ts,n,u,ind[10000],usd[100000];
double r[1000],l,w,cx,mx,cy,my,ty,tx,x[10000],y[10000];


void newline()
{
     cx=mx;cy=-1000000;
}

bool canpush()
{
     for (int i=0;i<n;i++)
     {
         tx=cx+r[i];
         ty=cy+r[i];
         if (tx<0)tx=0;
         if (ty<0)ty=0;
         if (tx+r[i]<w+eps&&ty+r[i]<l+eps&&usd[i]==0)return true;
     }
     return false;
}

void pushh()
{
     for (int i=0;i<n;i++)
     {
         if (cx+r[i]<w+eps&&cy+r[i]<l+eps&&usd[i]==0)
         {
                                    x[ind[i]]=cx+r[i];
                                    y[ind[i]]=cy+r[i];
                                    if (x[ind[i]]<0)x[ind[i]]=0;
                                    if (y[ind[i]]<0)y[ind[i]]=0;
                                    mx=max(mx,x[ind[i]]+r[i]);
                                    cy=y[ind[i]]+r[i];
                                    u++;
                                    usd[i]=1;
                                    break;
         }
     }
}


int main(){
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{cx=-1000000;
 cy=-1000000;
 mx=my=-1000000;

    ts++;
    cin>>n>>w>>l;
    for (int i=0;i<n;i++)
    cin>>r[i];
    for (int i=0;i<n;i++)
    ind[i]=i;
    
    //sort(r,r+n);
    //reverse(r,r+n);
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
    {
        if (r[i]<r[j]){swap(r[i],r[j]);
        swap(ind[i],ind[j]);}
    }
    
   /* cout<<endl<<endl;
   cout<<n<<" "<<w<<" "<<l<<endl;
   for (int i=0;i<n;i++)cout<<r[i]<<" ";
   cout<<endl;
    */cout<<"Case #"<<ts<<":";
   
    for (int i=0;i<n;i++)
    usd[i]=0;
    u=0;
    
    while (u<n){
     if (canpush())
     pushh();
     else newline(); 
   //  cout<<u<<" "<<cx<<" "<<cy<<" "<<x[u-1]<<" "<<y[u-1]<<endl;
    }
    
    cout.precision(6);
    
    for (int i=0;i<n;i++)
    cout<<fixed<<" "<<x[i]<<" "<<y[i];
    cout<<endl;
  //  cout<<w<<" "<<l<<" "<<endl;
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    if (i!=j)
    {
        if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<(r[ind[i]]+r[ind[j]])*(r[ind[i]]+r[ind[j]])-eps);//cout<<i<<" "<<j<<"A"<<" "<<(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<<" "<<endl;
    }
}

cin.get();cin.get();
return 0;}

















