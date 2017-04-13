#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

map<pair<int,int>,bool> M;
int d[10010],l[10010],N,D;

bool solve(int idx,int dis)
{
	pair<int,int> P=make_pair(idx,dis);
	if (M.find(P)!=M.end())
		return M[P];
	//printf("%d\n",idx);
	if (d[idx]+dis>=D) return M[P]=1;
	for (int i=idx+1;dis+d[idx]>=d[i] && i<N;i++)
		if (solve(i,min(d[i]-d[idx],l[i])))	return M[P]=1;
	return M[P]=0;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
		M.clear();
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d%d",&d[i],&l[i]);
		//l[0]=d[0];
		scanf("%d",&D);
		printf("Case #%d: ",t);
		if (solve(0,d[0]))	printf("YES\n");
		else printf("NO\n");
    }
    return 0;
}