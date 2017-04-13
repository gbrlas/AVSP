#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int task;
int a[17];
vector<int> ret;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		memset( a, 0, sizeof(a) );
		int c, n;
		scanf("%d", &c);
		for (int i=1; i<=4; i++)
		for (int j=1; j<=4; j++){
			scanf("%d", &n);
			if ( i==c ) a[n]++;
		}
		scanf("%d", &c);
		for (int i=1; i<=4; i++)
		for (int j=1; j<=4; j++){
			scanf("%d", &n);
			if ( i==c ) a[n++]++;
		}

		ret.clear();
		for (int i=1; i<=16; i++)
		if ( a[i]==2 ){
			ret.push_back(i);
		}

		if ( ret.size()==0 )
			printf("Case #%d: Volunteer cheated!\n", CASE);
		else if ( ret.size()>1 )
			printf("Case #%d: Bad magician!\n", CASE);
		else printf("Case #%d: %d\n", CASE, ret[0]);
	}
	return 0;
}
