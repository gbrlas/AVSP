#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int l,j,T;
	double long i,k,c,s,f,x,t,ti;
	cin>>T;
	for(l=1;l<=T;l++)
	{
		cin>>c>>f>>x;
	
		i=1.00;s=0.00;
		ti=x/2.0;
		j=2;
		if (x<=c)
		{
			t=x/2.000;
		}
		else{
		while(j!=1)
			{
				s+=c/(2.000+((i-1.00)*f));
				t=s+(x/(2.0+i*f));
				if(ti<=t)
				{
					t=ti;
					j=1;
				}
				ti=t;
				i++;
			}
		}	
		cout<<"Case #"<<fixed<<setprecision(7)<<l<<": "<<t<<endl;
	
	}
	return 0;
}