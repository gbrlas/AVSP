#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int p=0; p<t; p++){
		long long a,b, res=0;
		cin>>a>>b;
		double buf=b;
		long long k = a+1;
		long long razn = k*k - a*a;
		for(int i=0; i<100000; i++, k+=2){
			b-=razn;
			razn+=4;
			if(b < 0)
				break;
			res++;
		}
		cout<<"Case #"<<p+1<<": "<<res<<"\n";
	}
	return 0;
}