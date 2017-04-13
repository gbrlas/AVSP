#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

const int SZ = 10100;
int d[SZ], l[SZ];
int f[SZ];
int n, D;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		cin>>n;
		for(int i=0; i<n; i++) cin>>d[i]>>l[i];
		cin>>D;
		n++;
		d[n-1] = D;
		l[n-1] = 0;
		for(int i=0; i<n; i++) f[i] = -1;
		f[0] = d[0];
		for(int i=0; i<n-1; i++){
			if(f[i]==-1) continue;
			int j=i+1;
			while(j<n){
				if(d[j]>d[i]+f[i]) break;
				int z = min(l[j],d[j]-d[i]);
				f[j] = max(f[j],z);
				j++;
			}
		}

		cout<<"Case #"<<testnum+1<<": "<<(f[n-1]==-1?"NO":"YES")<<endl;
	}
	return 0;
}
