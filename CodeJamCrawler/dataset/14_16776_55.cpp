#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int f[4], s[4];

int main()
{
	int dataset, n, t = 1;
	int i, j, a, b, c, d;

	scanf("%d", &dataset);
	while(dataset--){
		scanf("%d", &n);
		for(i = 1; i <= 4; i++){
			if(i == n)
				scanf("%d %d %d %d", &f[0], &f[1], &f[2], &f[3]);
			else
				//scanf("%*d %*d %*d %*d", &a, &b, &c, &d);
				scanf("%d %d %d %d ", &a, &b, &c, &d);
		}
		//printf("%d %d %d %d ", f[0], f[1], f[2], f[3]);
		scanf("%d", &n);
		for(i = 1; i <= 4; i++){
			if(i == n)
				scanf("%d %d %d %d", &s[0], &s[1], &s[2], &s[3]);
			else
				scanf("%d %d %d %d", &a, &b, &c, &d);
		}
		//printf("%d %d %d %d ", s[0], s[1], s[2], s[3]);
		
		sort(f, f+sizeof(f)/sizeof(int));
		//printf("%d %d %d %d ", f[0], f[1], f[2], f[3]);
		sort(s, s+sizeof(s)/sizeof(int));
		
		int ans = 0, num = 0;
		for(i = 0, j = 0; i < 4 && j < 4; ){
			if(f[i] == s[j]){
				num = f[i];
				ans++;
				i++; j++;
			}
			else if(f[i] < s[j])
				i++;
			else
				j++;
		}
		
		if(ans == 0) printf("Case #%d: Volunteer cheated!\n", t);
		else if(ans == 1) printf("Case #%d: %d\n", t, num);
		else printf("Case #%d: Bad magician!\n", t);
		t++;
	}
	return 0;
}
