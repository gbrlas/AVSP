#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;

const int INF=1<<30;
char buf[100];

map<string,int>M;
int akt;
int wrzuc()
{
    string t(buf);
    if(M.find(t)==M.end()) return M[t]=akt++;
    else return M[t];
}

vector<pair<int,int> >oferty[303];

void dodaj(vector<pair<int,int> >&v, vector<pair<int,int> >a)
{
    for(int i=0; i<a.size(); i++) v.push_back(a[i]);
}
const int d=10000;
int go(int a, int b, int c)
{
    vector<pair<int,int> >v;
    dodaj(v,oferty[a]);
    dodaj(v,oferty[b]);
    dodaj(v,oferty[c]);
//    if(a!=0 || b!=1 || c!=2) return INF;
    sort(v.begin(),v.end());
    v.push_back(make_pair(10001,10001));
    if(v.empty()) return INF;
    if(v[0].first>1) return INF;
    int ost=0,mx=0,res=0;
//    for(int i=0; i<v.size(); i++) printf("%d %d\n",v[i].first,v[i].second);
    for(int i=0; i<=v.size(); i++)
    {
//	mx=max(mx,v[i].second);
	int k=i;
	bool kk=true;
	
	if(i<v.size() && v[i].first>ost+1)
	{
	    if(v[i].first>mx+1) {return INF;}
	    res++; ost=mx;
	}

	if(i<v.size() && v[i].first<=ost+1)
	{
	    kk=false;
	    while(i<v.size() && v[i].first==v[k].first)
	    {
		if(v[i].first<=ost+1)
		mx=max(mx,v[i].second);
		i++;
	    }
	    i--;
	}
//	printf("ost=%d, mx=%d, res=%d\n",ost,mx,res);
//	printf("f=%d, s=%d\n",v[i].first,v[i].second);
	if(i<v.size() && v[i].first>ost)
	{
	    if(v[i].first>mx+1) {return INF;}
	    res++; ost=mx;
	}

	if(kk && i<v.size() && v[i].first<=ost+1)
	{
	    kk=false;
	    while(i<v.size() && v[i].first==v[k].first)
	    {
		if(v[i].first<=ost+1)
		mx=max(mx,v[i].second);
		i++;
	    }
	    i--;
	}
	
	if(i==v.size()) break;
//	printf("ost=%d, res=%d, mx=%d\n",ost,res,mx);
//	printf("v[i].first=%d\n",v[i].first);

    }
    
//    printf("ost=%d, mx=%d, res=%d\n",ost,mx,res);
//    if(ost<d && mx>ost) {ost=mx; res++;}
    if(ost<d) return INF;
//    printf("ost=%d\n",ost);
//    printf("zwracam %d\n",res);
    if(ost==d+1) return res-1;
    return res;
}

main()
{
    int cases;
    scanf("%d",&cases);
    for(int testcase=1; testcase<=cases; testcase++)
    {
	M.clear(); akt=0;
	int n,res=INF,a,b;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
	    scanf("%s %d %d",&buf,&a,&b);
//	    printf("%s %d %d\n",buf,a,b);
	    int v=wrzuc();
//	    printf("v=%d\n",v);
	    oferty[v].push_back(make_pair(a,b));
	}
	akt+=2;
	int m=7;
	for(int a=0; a<akt; a++)
	for(int b=a+1; b<akt; b++)
	for(int c=b+1; c<akt; c++)
	{
	    res=min(res,go(a,b,c));
	}
	scanf("%d",&n);
	printf("Case #%d: ",testcase);
	if(res==INF) printf("IMPOSSIBLE\n"); else printf("%d\n",res);
	for(int i=0; i<akt; i++) oferty[i].clear();
//	return 0;
    }
}
