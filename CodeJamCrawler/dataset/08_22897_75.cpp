#include <cstdlib>
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace std;
ifstream fin("B.in");
ofstream fout("output.out");

struct pair
{
       int a,b;
};
int ta,tb;
int convert (string &s)
{
    return (((s[0]-'0')*10 + (s[1] -'0'))*60 + ((s[3] - '0')*10 + (s[4] -'0')));
}
int getminind(int b[],int & nb)
{
    int minind =0;
    for(int i=0;i<nb;i++)
    {
            if(b[i] < b[minind])
            {
             minind = i;
            }
    }
    return minind;
}
int minindc(int b[],int &nb,int val)
{
    int ret = -1;
    for(int i=0;i<nb;i++)
    {
     if (b[i] >= val)
     {
      if (ret == -1) ret = i;
      else if (b[i] < b[ret]) ret = i;
     }
    }
    return ret;
}
void swap(int b1[],int b2[],int i,int j)
{
     int temp = b1[i]; b1[i] =b1[j]; b1[j] =temp;
     temp = b2[i]; b2[i] = b2[j]; b2[j] =temp;
}
void solve(int a1[],int a2[],int b1[],int b2[],int &na,int &nb)
{
    if (na == 0) {fout<<ta<<" "<<tb+nb<<endl; return;}
    if (nb == 0) {fout<<ta+na<<" "<<tb<<endl; return;}
    int p = getminind(a1,na);
    int q = getminind(b1,nb);
    if(a1[p] < b1[q])
    {
     int endpt = a2[p];
     swap(a1,a2,p,0);
     a1 =a1 +1;
     a2=a2+1;
     na--;
     while(1)
     {
      int bavl = minindc(b1,nb,endpt);
      if(bavl == -1)
      {
       ta++;
       solve(a1,a2,b1,b2,na,nb);
       return;
      }
      else
      {
          endpt = b2[bavl];
          swap(b1,b2,0,bavl);
          b1=b1+1;
          b2=b2+1;
          nb--;
      }
      int aavl = minindc(a1,na,endpt);
      if(aavl == -1)
      {
       ta++;
       solve(a1,a2,b1,b2,na,nb);
       return;
      }
      else
      {
          endpt = a2[aavl];
          swap(a1,a2,0,aavl);
          a1=a1+1;
          a2=a2+1;
          na--;
      }
     }
    }
    if(a1[p] >= b1[q])
    {
     int endpt = b2[q];
     swap(b1,b2,q,0);
     b1 =b1 +1;
     b2=b2+1;
     nb--;
     while(1)
     {      
      int aavl = minindc(a1,na,endpt);
      if(aavl == -1)
      {
       tb++;
       solve(a1,a2,b1,b2,na,nb);
       return;
      }
      else
      {
          endpt = a2[aavl];
          swap(a1,a2,0,aavl);
          a1=a1+1;
          a2=a2+1;
          na--;
      }
      int bavl = minindc(b1,nb,endpt);
      if(bavl == -1)
      {
       tb++;
       solve(a1,a2,b1,b2,na,nb);
       return;
      }
      else
      {
          endpt = b2[bavl];
          swap(b1,b2,0,bavl);
          b1=b1+1;
          b2=b2+1;
          nb--;
      }
     }
    }
    
}
int main()
{
    int n;
    fin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
     int t,na,nb;
     fin>>t>>na>>nb;
     int a1[na],a2[na],b1[nb],b2[nb];
     string s;
     for(j=0;j<na;j++)
     {
      fin>>s;
      a1[j] = convert(s);
      fin>>s;
      a2[j] = convert(s) + t;
     }
     for(j=0;j<nb;j++)
     {
      fin>>s;
      b1[j] = convert(s);
      fin>>s;
      b2[j] = convert(s)+t;
     }
     ta=0;
     tb =0;
     fout<<"Case #"<<i+1<<": ";
     solve(a1,a2,b1,b2,na,nb);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
