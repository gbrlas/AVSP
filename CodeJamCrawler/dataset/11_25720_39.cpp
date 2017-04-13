#include <cstdio>
using namespace std;
bool t[1000005];
long long ilepierw = 0, ilepot = 0;
void sito(long long n)
{
	ilepierw = 0;
	ilepot = 0;
	for(int i = 0; i <= n; i++) t[i] = 0;
	for(long long i = 2; i < n; i++)
	{
		if(!t[i])
		{
			ilepierw++;
			long long pot = i*i;
			while(pot <= n)
			{
				ilepot++;
				pot *= i;
			}
			pot = i;
			while(pot <= n)
			{
				t[pot] = 1;
				pot += i;
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		long long W;
		scanf("%lld", &W);
		sito(W);
		printf("Case #%d: %lld\n", t, W>1? ilepot+1 : 0);
	}
	return 0;
}
