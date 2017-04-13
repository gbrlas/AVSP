#include <stdio.h>
#include <algorithm>
using namespace std;

int data[1000003];
int dist[1000003];
int tmp[1003];
int main()
{
	int T, ca;
	int l, t, n, c, i, j, time, ret, ans, m, s;
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++) {
		scanf("%d%d%d%d", &l, &t, &n, &c);
		for (i = 0; i < c; i++)
			scanf("%d", &tmp[i]);
		data[0] = 0;
		for (i = 1, j = 0; i <= n; i++) {
			data[i] = tmp[j];
			j = (j + 1) % c;
		}
		
		time = 0;
		for (i = 0; i <= n; i++) {
			if (i < n && time <= t && time + 2 * data[i + 1] > t)
				break;
			time += 2 * data[i + 1];		
			}
	//	printf("time %d\n", time);
		if (i > n) {
			ret = time;
			goto exit;
		}
			
		ans = t;
		dist[0] = data[i + 1] - (t - time) / 2;
	//	printf("dist %d\n", dist[0]);
		i+=2;
		for (j = 1; i <=n ; i++, j++) 
			dist[j] = data[i];
		m = j;
		sort(dist, dist + m);

		for (j = m - 1, s = 0; j >= 0; j--, s++) {
			if (s < l) {
				ans += dist[j];
			} else {
				ans += 2 * dist[j];
			}			
		}
		ret = ans;
exit:
	printf("Case #%d: %d\n", ca, ret);
	}		
	return 0;		
}