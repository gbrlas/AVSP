#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int convert_to_dec(string anum,string slan);
string convert_from_dec(int dnum,string tlan);

void main()
{
int number;
string anum;
string slan;
string tlan;
ifstream in("A-large.in");
ofstream out("A-large.out");
in>>number;
for (int i=1;i<=number;i++)
{
in>>anum>>slan>>tlan;
int dnum=convert_to_dec(anum,slan);
string realnum=convert_from_dec(dnum,tlan);
out<<"Case #"<<i<<": "<<realnum<<endl;
}
/*
cin>>anum>>slan>>tlan;
int dnum=convert_to_dec(anum,slan);
string realnum=convert_from_dec(dnum,tlan);
cout<<"Case #"<<1<<": "<<realnum<<endl;
*/
}

int convert_to_dec(string anum,string slan)
{
int anum_size=(int)anum.size();
int slan_size=(int)slan.size();
int dec_int=0;
string dec_string;
for (int i=0;i<anum_size;i++)
{
	dec_int=int(dec_int)+int(slan.find(anum[i])*pow(double(slan_size),double(anum_size-1-i)));
}
return dec_int;
}

string convert_from_dec(int dnum,string tlan)
{
int tlan_size=(int)tlan.size();
vector <char> newnum;
int result=dnum,remain=0,i=0;
do
{
	remain=result-(result/tlan_size)*tlan_size;
    result=result/tlan_size;
	newnum.push_back(tlan[remain]);
	i++;
}
while (result!=0);
string num(newnum.begin(), newnum.end());
vector <char> realnum;
for (int j=0;j<i;j++)
{
realnum.push_back(newnum[i-1-j]);
}
string real(realnum.begin(),realnum.end());
return real;
}