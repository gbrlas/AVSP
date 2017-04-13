#include<iostream>
#include<stdio.h>
using namespace std;

int calc(int T)
{
	double C,F,X,n;
	cin>>C>>F>>X;
	double speed = 2;
	double t = 0;
	double min1 = X / 2;
	int i = 1;

	while(1){
		
		speed = 2;
		t = 0;
		
		for(int j=1; j<=i ;j++){
		t = t + C / speed;
		speed += F;
		}
		
		 t = t + X / speed;
		//cout<<t<<endl;
		if(t <min1)
		min1 = t;
		else
		break;
		i++;
	}
	printf("Case #%d: %.7f\n",T,min1);
	//cout<<(double)min1<<endl;
	}	

int main()
{
	int T=0;
	cin>>T;
	for(int i=1; i<=T; i++){
		calc(i);
	}
}
