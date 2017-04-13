#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		double c,f,x;
		cin>>c>>f>>x;
		double ans = x/2;
		double temp = 0;
		for(int i=1;i<x;i++) {
			temp+=c/(2+(i-1)*f);
			double time = x/(2+i*f) + temp;
			if (ans > time)
				ans = time;
			else
				break;
		}
		cout << fixed<<setprecision(7)<<"Case #"<<tn+1<<": "<<ans<<endl;
	}
}
