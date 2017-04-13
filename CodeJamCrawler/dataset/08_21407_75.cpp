#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int minutes(char a[])
{
    return ((a[0]-'0')*10+a[1]-'0')*60 + (a[3]-'0')*10+a[4]-'0';
}

int solve(vector<pair<int,int> >&v)
{
    int free=0,res=0;
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        v[i].second*=-1;
        free+=v[i].second;
        if(free<0) {free++; res++;}
    }
    return res;
}

main()
{
    int n;
    scanf("%d",&n);
    char buf1[6],buf2[6];
    vector<pair<int,int> >a,b;
    for(int test=1; test<=n; test++)
    {
	a.clear(); b.clear();
	int t,na,nb;
	scanf("%d %d %d", &t, &na, &nb);
	for(int i=0; i<na; i++)
	{
	    scanf("%s %s",buf1,buf2);
	    a.push_back(make_pair(minutes(buf1), 1) );
	    b.push_back(make_pair(minutes(buf2)+t,-1) );
	}
	for(int i=0; i<nb; i++)
	{
	    scanf("%s %s",buf1,buf2);
	    b.push_back(make_pair(minutes(buf1), 1) );
	    a.push_back(make_pair(minutes(buf2)+t,-1) );
	}
	printf("Case #%d: %d %d\n",test,solve(a),solve(b));
    }
    return 0;
}
