#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


int a,b;
int f1[5][5],f2[5][5];

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++)
	{
		scanf("%d",&a);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				scanf("%d",&f1[i][j]);
		scanf("%d",&b);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				scanf("%d",&f2[i][j]);
		vi v1,v2;
		a--,b--;
		for (int i=0; i<4; i++)
			v1.pb(f1[a][i]),v2.pb(f2[b][i]);
		int m=0,n;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (v1[i]==v2[j])
					m++,n=v1[i];
		printf("Case #%d: ",t);
		if (m==1)
			printf("%d\n",n);
		else if (m>1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}
