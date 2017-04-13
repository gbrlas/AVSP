#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <cctype>
#include <algorithm>
#define f(a,b,c) for(int a=(b);a<(c);a++)
using namespace std;
void main(){
	// Read input from this file 
	ifstream inp("A-small.in",ios::in);
	// write output to this file 
	ofstream out("A-Ans-small.in",ios::out);

	int count=0;
	inp>>count;

	for(int i=0;i<count;i++)
	{
	long long result=0;
	long long X,Y,x0,y0,A,B,C,D,M,n;
	vector<long long> x,y;
	inp>>n;
	inp>>A;
	inp>>B;
	inp>>C;
	inp>>D;
	inp>>x0;
	inp>>y0;
	inp>>M;
	X = x0, Y = y0;
	 x.push_back(X);
	 y.push_back(Y);
	// cout<<"("<<X<<","<<Y<<")\n";
	f( j,1,n){
     X = (A * X + B)%M;
     Y = (C * Y + D)%M;
	 x.push_back(X);
	 y.push_back(Y);
	// cout<<"("<<X<<","<<Y<<")\n";
	 }
	f(k,0,n-2){
		f(m,(k+1),(n-1)){
			f(p,(m+1),n){
			if(  ((x[k]+x[m]+x[p])%3==0) && ((y[k]+y[m]+y[p])%3==0))
			{
			/*		int tempx=(x[k]+x[m]+x[p])/3;
					int tempy=(y[k]+y[m]+y[p])/3;
				int fx=0,fy=0;
				f(tt,0,n){
				  if(tempx==x[tt]) fx=1;
				  if(tempy==y[tt]) fy=1;				  
				}
				if(fx==1&&fy==1)
			*/
				result++;
			}
	}}}
		cout<<"("<<result<<")\n";
		out<<"Case #"<<i+1<<":"<<" "<<result<<"\n";
	}
}
