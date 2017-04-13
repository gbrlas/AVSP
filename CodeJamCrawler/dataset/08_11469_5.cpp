#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <cctype>
#include <algorithm>
#define f(a,b,c) for(long a=(b);a<(c);a++)
using namespace std;
void main(){
	// Read input from this file 
	ifstream inp("A-small.in",ios::in);
	// write output to this file 
	ofstream out("A-Ans-small.in",ios::out);

	long count=0;
	inp>>count;

	for(long i=0;i<count;i++)
	{
	int p,k,l;
	long long result=0;
	vector<long> f;
	vector<long> key;
	f(j,0,k)
	 key.push_back(0);
	 
	inp>>p;
	inp>>k;
	inp>>l;
	
	f(j,0,l){
	long temp;
	inp>>temp;
	f.push_back(temp);
	}
	
	long chk=0;
	f(j,0,l){
	if(f[j]!=0)
	 chk++;
	}
	if(chk>(k*p)){
			cout<<"("<<"impossible"<<")\n";
		out<<"Case #"<<i+1<<":"<<" Impossible"<<"\n";
		break;
	}
	
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	f(j,0,l){
	cout<<"{"<<key.size()<<"}";
	result=result+(j/k+1)*f[j];	

	}
		cout<<"("<<result<<")\n";
		out<<"Case #"<<i+1<<":"<<" "<<result<<"\n";
	}
}
