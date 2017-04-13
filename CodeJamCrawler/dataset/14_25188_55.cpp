#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
using std::fstream;
long double time_taken(long double C,long double F,long double X);
main()
{
	fstream fin1,fin2;
	fin1.open("B-small-attempt0.in",ios::in);
	fin2.open("out.txt",ios::out);
long double C,F,X;
long double time;
int testc;
int k;
string input1,input2,input3;
	fin1>>testc;
	for(k=1;k<=testc;k++)
	{
		fin1>>input1>>input2>>input3;
		C=atof(input1.c_str());
		F=atof(input2.c_str());
		X=atof(input3.c_str());
		time=time_taken(C,F,X);
		fin2<<"Case #"<<k<<": ";
		fin2<<fixed<<setprecision(7)<<showpoint<<time<<"\n";
	}
return 0;
}

long double time_taken(long double C,long double F,long double X)
{
long double N=0;		//no of cookie farms
long double time1,time2;
long double time_cookie_farm,rate,actual_time=0;
int flag=0;
	while(flag!=1)
	{
		rate=2.0+(F*N);
		time_cookie_farm=C/rate;
		time1=X/rate;
		rate=2.0+((F)*(N+1));
		time2=(time_cookie_farm)+(X/rate);
		if(time1>time2)
			{
			N=N+1;
			actual_time=actual_time+time_cookie_farm;
			}
		else
			{
			actual_time=actual_time+time1;
			flag=1;
			}
	}
return actual_time;
}
