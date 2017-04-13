#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
 int te,s,q,i,j,l,k;
 cin>>te;
 char ch[2];
 gets(ch);
 for(j=0;j<te;j++)
 {
  string srch,qry;
  int mx=0,fn=0,ret=0;
  cin>>s;
  map <string, vector <int> > tbl;
  vector <string> nm;
  char inpu[100];
  gets(inpu);
  for(i=0;i<s;i++)
  {
   vector <int> val;
   gets(inpu);
   srch=inpu;   
   val.push_back(0);
   nm.push_back(srch);
   tbl[srch]=val;
   val.clear();
  }
  cin>>q;
  gets(inpu);
  vector <int> tmp;
  for(i=0;i<q;i++)
  {
   gets(inpu);
   qry=inpu;
   tmp=tbl[qry];
   tmp.push_back(i+1);
   if(tmp.size()>mx)
   mx=tmp.size();
   tbl[qry]=tmp;
   tmp.clear();
  }
  if((s==0)||(q==0))
  {
   cout<<"Case #"<<j+1<<": "<<ret<<"\n";
   continue;                
  }
  int lin=1999,bs=0,max=0,is=0,in;
  vector <int> diff(s);
  ret=0;
  while(1)
  {
   is=0;
   for(k=0;k<s;k++)
   {
    tmp=tbl[nm[k]];
    if(tmp.size()==1)
    {
     is=0;
     break;
    }
    for(i=1;i<tmp.size();i++)
    {
     if(tmp[i]>bs)
     {
      if(k!=lin)
      {
       diff[k]=tmp[i]-bs;
       is=1;
       break;
      }
      else
      {
       if(tmp[i]<bs)
       {
        is=0;
        break;
       }
       else
       {
        diff[k]=0;
        is=1;
        break;
       }
      }
     }
     else
     {      
      if((i==(tmp.size()-1))&&(tmp[i]<bs))
      {
       is=0;
       break;                     
      }
      else
      {
       is=1;
       diff[k]=0;
      }
     }        
    }
    if(is==0)
    break;                
   }
   max=0;
   if(is==1)
   {
    for(k=0;k<s;k++)
    {
     if(diff[k]>max)
     {
      max=diff[k];
      in=k;              
     }
    }
    tmp=tbl[nm[in]];
    lin=in;
    for(k=1;k<tmp.size();k++)
    {
     if(tmp[k]>bs)
     {
      bs=tmp[k];
      //ret=ret+1;
      break;            
     }                         
    }
    ret=ret+1; 
   }
   else
   break;
  }
  cout<<"Case #"<<j+1<<": "<<ret<<"\n";
 }
 return(0);
}
