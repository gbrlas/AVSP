#include <cstdio>
#include <map>
#define MOD 1000002013

using namespace std;
typedef long long ll;

ll calc(ll N, ll dist, ll p)
{
	return ((2 * N - dist + 1) * dist / 2) % MOD * p % MOD;
}

ll solve()
{
    ll ans = 0, N;
	int M;
	map<pair<int, bool>, int> flow;
	scanf("%lld%d", &N, &M);
	ll price = 0;
	for (int i = 0; i < M; ++i)
	{
		int o, e, p;
		scanf("%d%d%d", &o, &e, &p);
		flow[make_pair(o, false)] += p;
		flow[make_pair(e, true)] += p;
		price = (price + calc(N, e - o, p)) % MOD;
	}
	map<int, int> passengers;
	for (map<pair<int, bool>, int>::iterator it = flow.begin(); it != flow.end(); ++it)
	{
		if (it->first.second) // leave
		{
			while (it->second)
			{
				if (passengers.rbegin()->second > it->second)
				{
					passengers.rbegin()->second -= it->second;
					price = (price - calc(N, it->first.first - passengers.rbegin()->first, it->second) + MOD) % MOD;
					break;
				}
				else
				{
					ll p = passengers.rbegin()->second;
					price = (price - calc(N, it->first.first - passengers.rbegin()->first, p) + MOD) % MOD;
					it->second -= p;
					passengers.erase(--passengers.end());
				}
			}
		}
		else
		{ // come
			passengers[it->first.first] += it->second;
		}
	}
    return price;
}

int main()
{
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: %lld\n", t, solve() % MOD);
    }
}
