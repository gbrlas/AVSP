#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1<<10];
pair<int,int> narr[1<<10];
int pos[1<<10];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			narr[i] = pair<int,int>(arr[i],i);
		sort(narr,narr+n);
		for (int i = 0; i < n; i++){
			arr[narr[i].second] = i;
			pos[i] = narr[i].second;
		}
		/*
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		
		for (int i = 0; i < n; i++)
			cout << pos[i] << " ";
		cout << endl;
		*/
		int ans = 0;
		for (int num = 0; num < n; num++){
			int cnt1 = 0, cnt2 = 0;
			int cmp = pos[num];
			for (int i = 0; i < num; i++)
				if (pos[i] < cmp)
					cnt1++;
				else cnt2++;
				
			cnt1 = pos[num] - cnt1;
			cnt2 = n-1-pos[num]-cnt2;
			//cout << cnt1 << " " << cnt2 << endl;
			ans += min(cnt1,cnt2);
		}
		cout << "Case #" << zz << ": " << ans << endl;
	}
	
	return 0;
}
