#include<iostream>
#include<stdio.h>

using namespace std;

double F,C,X,rate;
int T;
double time;

int main() {
	cin>>T;
	for(int ti=1;ti<=T;ti++) {
		cin>>C>>F>>X;
		rate = 2.0;
		time = 0.0;
		
		while(true) {
			double t1 = X/rate;
			double t2 = C/rate + X/(rate + F);
			if(t1 > t2) {
				time += C/rate;
				rate += F;
			} else {
				time += X/rate;
				break;
			}	
		}
		cout<<"Case #"<<ti<<": ";
		printf("%.7f\n",time);
	}
	return 0;
}
