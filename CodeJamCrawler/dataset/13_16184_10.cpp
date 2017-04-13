#include<cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T, a, n;
	vector<int> mts;
	scanf("%d", &T);
	for(int t=1; t<= T; t++)
	{
		scanf("%d%d", &a, &n);
		mts.resize(n);

		for(int i=0; i<n; i++)
			scanf("%d", &mts[i]);

		sort(mts.begin(), mts.end());

		int it = 0;
		int ans = 0;
		if(a != 1)
		{
			while(it < mts.size())
			{
				while(mts[it] < a)
				{
					a += mts[it++];
					if(it == mts.size())
						break;
				}

				if(it == mts.size())
					break;
				else if(it == mts.size() - 1)
				{
					ans++;
					break;
				}

				int ops = 0;
				int mod = a;
				while(mod <= mts[it])
				{
					mod += mod-1;
					ops++;
				}

				if(ops >= mts.size() - it)
				{
					ans += mts.size() - it;
					break;
				}
				else
				{
					ans += ops;
					a = mod;
				}
			}
		}
		else
		{
			ans = mts.size();
		}

		printf("Case #%d: %d\n", t, ans);
		mts.clear();
	}

	return 0;
}