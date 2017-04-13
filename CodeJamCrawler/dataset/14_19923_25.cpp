#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;
ifstream fin;

ofstream fout;


double Rst(double C,double &pay,double F,double &time,double X)
{
	double time1=X/pay;
	
	do
	{
		time=time1;
		time1-=X/pay;
		time1+=C/pay;
		pay+=F;
		time1+=X/pay;
	}while(time>time1);

	return time;
}



int main()
{
	int T;
	 FILE *fp = fopen("resultB.txt", "w");
	fin.open("B-small-attempt0.in");
	//fout.open("resultB.txt");
	fin>>T;
	double C,F,X;
	double time;
	double pay;
	for(int i=1; i<=T ; i++)
	{
		fin>>C>>F>>X;
		pay=2.0;
		time=X/pay;

		//fout<<"Case #"<<i<<": "<<Rst(C,pay,F,time,X)<<"\n";
		fprintf(fp, "Case #%d: %0.7f\n",i,Rst(C,pay,F,time,X));
	}

	fin.close();
	fout.close();
	return 0;
}

