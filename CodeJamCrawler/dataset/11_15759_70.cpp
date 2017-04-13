#include<iostream>
#include<cmath>
using namespace std;
int abso(int a)
{
	if(a< 0) return -a;
	return a;
}
int main()
{
int timeB,timeO,posB,posO,totaltime;

int T,N,pos; char ch;
cin>>T;
for(int i=1; i <= T; i++){
	cin>>N;
	timeB=timeO=totaltime=0; posB=posO=1;
	for(int j=0; j < N; j++)
	{
		cin>>ch>>pos;
		if(ch=='O'){
			if((totaltime-timeO)>=abso(pos-posO))
			{
				totaltime++;
				timeO=totaltime;
				posO=pos;
			}
			else{
				totaltime+=(abso(pos-posO)-(totaltime-timeO));
				totaltime++;
				timeO=totaltime;
				posO=pos;
			}
		}
		else{
			if((totaltime-timeB)>=abso(pos-posB))
			{
				totaltime++;
				timeB=totaltime;
				posB=pos;
			}
			else{
				totaltime+=(abso(pos-posB)-(totaltime-timeB));
				totaltime++;
				timeB=totaltime;
				posB=pos;
			}
		}
	}
	cout<<"Case #"<<i<<": "<<totaltime<<"\n";
}
return 0;
}
