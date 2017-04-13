#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

long long a[1000100];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int L, n, c;
		long long t;
		cin>>L;
		cin>>t;
		cin>>n;
		cin>>c;
		for(int i=0; i<c; i++){ cin>>a[i]; a[i]*=2; }
		for(int i=c; i<n; i++) a[i] = a[i-c];
		long long sum = 0;
		int z = 0;
		while(z<n){
			if(sum+a[z]>t){
				a[z]=(sum+a[z]-t);
				sum = t;
				break;
			}else{
				sum+=a[z];
				z++;
			}
		}
		if(z<n){
			sort(&a[z],&a[n]);
			int v;
			for(v=n-1; v>=z; v--){
				if(L>0){
					sum+=a[v]/2;
					L--;
				}else{
					sum+=a[v];
				}
			}
		}
		cout<<"Case #"<<testnum+1<<": "<<sum<<endl;
	}
	return 0;
}