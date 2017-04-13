#include<iostream>
#include<sstream>
using namespace std;

bool esReciclado(int A,int B)
{
 stringstream str;
 str<<A;
 string ca,cb;
 str>>ca;
 str.clear();
 str<<B;
 str>>cb;

 if(ca.size()<cb.size())
 {
  while(ca.size()!=cb.size())
   ca='0'+ca;
 }
 else if(ca.size()>cb.size())
 {
  while(ca.size()!=cb.size())
   cb='0'+cb;
 }

 for(int I=0;I<ca.size();I++)
 {
  if(ca.compare(cb)==0)
   return 1;
  else
  {
   char t=ca[0];
   string cc=ca.substr(1,ca.size()-1);
   cc.push_back(t);
   ca=cc;
   //cout<<ca<<"-"<<cb<<endl;
  }
 }
 return 0;
}

int main()
{
 int N;
 cin>>N;

 for(int I=0;I<N;I++)
 {
  int C=0;
  int A,B;
  cin>>A>>B;
  for(int J=A;J<=B;J++)
   for(int K=J+1;K<=B;K++)
    if(esReciclado(J,K))
     C++;
  cout<<"Case #"<<I+1<<": "<<C<<endl;
 }
 return 0;
}
