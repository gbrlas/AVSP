#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
char ch;

int ta=0;
int na,nb;
char c[20];
void main(){
// Read input from this file 
 ifstream inp("B-small.in",ios::in);
// write output to this file 
 ofstream out("Ans-small.in",ios::out);
 int count=0;
 vector<string> tt;
 vector<int> aa;
 vector<int> ad;
 vector<int> ba;
 vector<int> bd;
 int tempa=0,tempd=0,f=0;
 
 inp>>count;
for(int i=0;i<count;i++)
{
aa.clear();
ad.clear();
ba.clear();
bd.clear();
inp>>ta;
inp>>na;
inp>>nb;
inp.getline(c,20);
tt.clear();
int ttt=0;
for(int j=0;j<na;j++){
inp.getline(c,20);
tt.push_back(c);
}
	////// convert a time
	 for(int j=0;j<na;j++){
	 tempa=0;tempd=0;f=0;
	 for(int k=0;k<tt[j].size();k++){
      if(tt[j][k]==' ') {f=1;continue;}
	  if(tt[j][k]!=':'&&f==1){tempd=tempd*10+tt[j][k]-'0';}
	  if(tt[j][k]!=':'&&f==0){tempa=tempa*10+tt[j][k]-'0';}
	}
	 ttt=tempa/100;
	 tempa=(ttt)*60+tempa%100;
	 ad.push_back(tempa);
	 ttt=tempd/100;
	 tempd=(ttt)*60+tempd%100;
	 aa.push_back(tempd); 
	// cout<<ad[j]<<" "<<aa[j]<<"\n";
	 }
tt.clear();
for(int j=0;j<nb;j++){
inp.getline(c,20);
tt.push_back(c);
}
	 ////// convert b time
	 for(int j=0;j<nb;j++){
	 tempa=0;tempd=0;f=0;
	 for(int k=0;k<tt[j].size();k++){
      if(tt[j][k]==' ') {f=1;continue;}
	  if(tt[j][k]!=':'&&f==1){tempd=tempd*10+tt[j][k]-'0';}
	  if(tt[j][k]!=':'&&f==0){tempa=tempa*10+tt[j][k]-'0';}
	}
	 ttt=tempa/100;
	 tempa=(ttt)*60+tempa%100;
	 bd.push_back(tempa);
	 ttt=tempd/100;
	 tempd=(ttt)*60+tempd%100;
	 ba.push_back(tempd); 
	//cout<<bd[j]<<" "<<ba[j]<<"\n";
	 }
//////////////////////////////  main part
sort(aa.begin(),aa.end());
sort(ad.begin(),ad.end());
sort(ba.begin(),ba.end());
sort(bd.begin(),bd.end());
cout<<"------------------------------- \n";

for(int j=0;j<na;j++)
 cout<<ad[j]<<" "<<aa[j]<<"\n";
cout<<"\n";
for(int j=0;j<nb;j++)
 cout<<bd[j]<<" "<<ba[j]<<"\n";
cout<<"\n";
cout<<"\n";

int fa=na,fb=nb;
//cout<<"["<<na<<";"<<nb<<"]"; 
	 for(int k=0;k<na;k++){
		for(int l=0;l<nb;l++){
		if( bd[l]!=-1&&(aa[k]+ta)<=bd[l])
		{bd[l]=-1;fb--;break;}
		}
	 }
	for(int k=0;k<nb;k++){
		for(int l=0;l<na;l++){
		if( ad[l]!=-1&&(ba[k]+ta)<=ad[l])
		{ad[l]=-1;fa--;break;}
		}
	 }
	 
for(int j=0;j<na;j++)
 cout<<ad[j]<<" "<<aa[j]<<"\n";
cout<<"\n";
for(int j=0;j<nb;j++)
 cout<<bd[j]<<" "<<ba[j]<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"------------------------------- \n";
out<<"Case #"<<i+1<<": "<<fa<<" "<<fb<<"\n";	 
}
}