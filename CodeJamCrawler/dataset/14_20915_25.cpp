#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
double  c1=2.0;
inline double process(double y,double c2,double x){
	double t[2];
	double k=x/c1;
	t[0]=(y/c1)+(x/(c1+c2));
	int i=0;
	if(k<t[0])return k;
	while(true){
		i++;
		t[1]=(t[0])+(y-x)/(c1+(i*c2))+x/(c1+(i+1)*c2);
		if(t[1]>t[0])return t[0];
		t[0]=t[1];
	}
}
int main(){
	
	setprecision(7);
	cout<<fixed;cout<<setprecision(7);
	unsigned long T;
	cin>>T;
	for(unsigned long i=1;i<=T;i++){
		double d[3];
		cin>>d[0]>>d[1]>>d[2];
		cout<<"Case #"<<i<<": "<<process(d[0],d[1],d[2])<<endl;

}
















return 0;
}
