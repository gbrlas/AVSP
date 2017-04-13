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
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test_count;
	cin>>test_count;
	for(int test = 0; test<test_count; test++){
		int n, m;
		cin>>n>>m;
		vector<int> arr(n);
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		int res = 0;
		sort(arr.rbegin(), arr.rend());
		vector<char> used(n, false);
		for(int i=0; i<arr.size(); i++){
			if(!used[i]){
				int k = -1;
				for(int j=i+1; j<arr.size(); j++){
					if(arr[i] + arr[j] > m || used[j])
						continue;
					else{
						k = j;
						break;
					}
				}
				used[i] = true;
				res++;
				if(k != -1){
					used[k] = true;	
				}
			}
		}

		cout<<"Case #"<<test+1<<": ";
		cout<<res;
		cout<<"\n";
	}
    return 0;
}