#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

int si(string a);
int main()
{
 int te,i,j;
 cin>>te;
 for(i=0;i<te;i++)
 {
  int ra=0,rb=0,tt,trv,na,nb,k;
  cin>>tt;
  cin>>na>>nb;
  
  vector < pair <int,int> > tta1;
  vector < pair <int,int> > ttb1;
  vector < pair <int,int> > tta2;
  vector < pair <int,int> > ttb2;
  pair <int, int> tmp1;
  pair <int, int> tmp2;
  for(j=0;j<na;j++)
  {
   string a,d;
   cin>>d>>a;
   tmp1.first=si(d);tmp2.first=si(a);
   tmp1.second=si(a);tmp2.second=si(d);
   if(tmp1.second<=tmp1.first) 
   {
    tmp1.second=10000;
    tmp2.first=10000;
   } 
   tta1.push_back(tmp1);
   tta2.push_back(tmp2);             
  }
  for(j=0;j<nb;j++)
  {
   string a,d;
   cin>>d>>a;
   tmp1.first=si(d);tmp2.first=si(a);
   tmp1.second=si(a);tmp2.second=si(d);
   if(tmp1.second<=tmp1.first) 
   {
    tmp1.second=10000;
    tmp2.first=10000;
   } 
   ttb1.push_back(tmp1);
   ttb2.push_back(tmp2);              
  }
  if((na==0)||(nb==0))
  {
   cout<<"Case #"<<i+1<<": "<<na<<" "<<nb<<"\n";
   continue;
  }
  sort(tta1.begin(),tta1.end());
  sort(ttb1.begin(),ttb1.end());
  sort(tta2.begin(),tta2.end());
  sort(ttb2.begin(),ttb2.end());
  trv=0;
  for(j=0;j<na;j++)
  {
   ra=ra+1;
   for(k=trv;k<nb;k++)
   {
    if(tta2[j].first+tt<=ttb1[k].first)
    {
     trv=k+1;
     rb=rb-1;
     break;                              
    }                 
   }                
  }
  trv=0;
  for(j=0;j<nb;j++)
  {
   rb=rb+1;
   for(k=trv;k<na;k++)
   {
    if(ttb2[j].first+tt<=tta1[k].first)
    {
     trv=k+1;
     ra=ra-1;
     break;                              
    }                 
   }                
  }
  cout<<"Case #"<<i+1<<": "<<ra<<" "<<rb<<"\n";
 }
 return(0);
}

int si(string a)
{
 int ret=0,k=0,j=0;
 k=k+(a[0]-'0')*10;
 k=k+(a[1]-'0');
 j=j+(a[3]-'0')*10;
 j=j+(a[4]-'0');
 ret=k*60+j;
 return(ret);  
}
