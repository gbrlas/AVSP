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

int a[10010];
int n;

inline bool f(int x){
	for(int i=0; i<n; i++){
		if(!(x%a[i]==0 || a[i]%x==0)) return false;
	}
	return true;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int l, h;
		cin>>n>>l>>h;
		for(int i=0; i<n; i++) cin>>a[i];
		cout<<"Case #"<<testnum+1<<": ";
		bool ok = false;
		for(int i=l; i<=h; i++){
			if(f(i)){
				ok = true;
				cout<<i<<endl;
				break;
			}
		}
		if(!ok){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}