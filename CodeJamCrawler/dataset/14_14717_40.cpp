#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++)
	{
		printf("Case #%d: ",cas);
		int n,lim;
		int num[10005];
		cin >> n >> lim;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		bool used[10005]={};
		int cur = n-1,res = 0;
		for(int i=0;i<n;i++)
		{
			if(used[i]) continue; used[i]=true;
			res++;
			while(cur>=0 && (num[cur]+num[i] > lim || used[cur])) cur--;
			if(cur>=0)
			{
				used[cur] = true;
			}
		}
		cout << res << endl;
	}
}