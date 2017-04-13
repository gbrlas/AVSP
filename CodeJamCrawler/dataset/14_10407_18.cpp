#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;

int main(){	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		int a, b, k;
		cin>>a>>b>>k;
		int res = 0;
		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++){
				if((i & j) < k)
					res++;
			}
		}


		cout<<"Case #"<<t+1<<": ";
		cout<<res;
		cout<<"\n";
	}

	return 0;
}