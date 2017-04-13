#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;

int n;
int a[1<<11];
int b[1<<11];
int arr[1<<11];
int le[1<<11];
int ri[1<<11];

int main(){
	int zz; cin >> zz;
	for (int tt = 1; tt <= zz; tt++){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
			
		/*for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;*/
		memset(le,0,sizeof(le));
		memset(ri,0,sizeof(ri));
		memset(arr,0,sizeof(arr));
		vector<int> is;
		for (int num = 1; num <= n; num++){
			is.clear();
			for (int i = 0; i < n; i++)
				if (arr[i] == 0 && le[i] == a[i] -1 && ri[i] == b[i] - 1){
					is.push_back(i);
					/*if (besti = -1){
						besti = i;
						continue;
					}
					int lem = le[i]+1; int rim = ri[i]+1;
					int curr = i+1;
					while (curr < n && arr[curr] > 0) curr++;
					int curl = i-1;
					while (curl >= 0 && arr[curl] > 0) curl--;
					if (ri[curl] == rim && le[curr] == lem)
						besti = i;*/
					//cout << "i = " << i << endl;
					//break;	
				}
			int bestk = 0;
			for (int k = 0; k < is.size(); k++){
				int i = is[k];
				int lem = le[i] + 1; int rim = ri[i] + 1;
				bool okay = true;
				if (k > 0){
					if (ri[is[k-1]] < rim)
					okay = false;
				}
				if (k < is.size() - 1){
					if (le[is[k+1]] < lem)
					okay = false;
				}
				if (okay){
					bestk = k;
					break;
				}
			}
			int besti = is[bestk];
			arr[besti] = num;
			int lem = le[besti]+1; int rim = ri[besti]+1;
			for (int j = 0; j <= besti; j++)
				ri[j] = max(ri[j],rim);
			for (int j = besti; j < n; j++)
				le[j] = max(le[j],lem);
			//cout << "num = " << num << endl;
		}
		cout << "Case #" << tt << ":";
		for (int i = 0; i < n; i++)
			cout << " " << arr[i];
		cout << endl;
	}	
	
	return 0;
}
