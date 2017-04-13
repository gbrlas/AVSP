#include<cstdio>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	ifstream input("B-large.in");
	ofstream output("out.txt");
	
	double c,f,x,a,b;
	double mf=2,time=0;
	int t,j=1;
	input>>t;
	while(t--){
		time = 0;
		mf = 2;
		input>>c>>f>>x;
		while(1){
			a=x/mf;
			b=c/mf;
		if(a <= (b)+(x/(f+mf))){
			time+= a;
			break;
		}else{
			time+=b;
			mf+=f;
		}
		}
		output<<"Case #"<<j++<<": ";
		output<<fixed;
		output<<setprecision(7)<<time<<endl;
		
		
	}
}
