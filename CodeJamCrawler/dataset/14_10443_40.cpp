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

vector<int> buf;
int kol = 0;

void sw(int i, int j){
	while(i != j){
		if(i < j){
			swap(buf[i], buf[i+1]);
			i++;
		}
		else{
			swap(buf[i], buf[i-1]);
			i--;
		}
		kol++;
	}
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test_count;
	cin>>test_count;
	for(int test = 0; test<test_count; test++){
		int n, res = INT_MAX;
		cin>>n;
		int mx = -1, ind = -1;
		vector<int> arr(n);
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
			if(arr[i] > mx){
				mx = arr[i];
				ind = i;
			}
		}
		buf = arr;
		kol = 0;
		int l = 0, r = n-1;
		for(int t=0; t<n; t++){
			int mn = INT_MAX, k = -1;
			for(int i=l; i<=r; i++){
				if(buf[i] < mn){
					mn = buf[i];
					k = i;
				}
			}
			int a = abs(l - k), b = abs(r - k);
			if(a < b){
				sw(k, l);
				l++;
			}
			else{
				sw(k, r);
				r--;
			}
		}
		res = kol;
		cerr<<test<<"\n";
		cout<<"Case #"<<test+1<<": ";
		cout<<res;
		cout<<"\n";
	}
    return 0;
}