#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

#define For(i,n) for(l i=0;i<(n);i++)
#define IFor(i,n) for(l i=(n)-1;i>=0;i--)
#define For1(i,n) for(l i=1;i<=n;i++)
#define IFor1(i,n) for(l i=n;i>0;i--)

#define INF 0x3F3F3F3F
#define PI 3.14159265358979323846264338327950288

//Compilar com -DDEBUG
#ifdef DEBUG
#define debug(x) (cout<< "--> " << #x << " = " << x << endl)
#else
#define debug(x) ;
#endif

#include<algorithm>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;//(peso,orig,dest)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii>vvii;

typedef long long l;
typedef pair<l,l>ll;
typedef pair<l,ll>lll;
typedef vector<l>vl;
typedef vector<vl>vvl;
typedef vector<ll>vll;
typedef vector<vll>vvll;

typedef unsigned long long ul;
typedef pair<ul,ul>ull;
typedef pair<ul,ull>ulll;
typedef vector<ul>vul;
typedef vector<vul>vvul;
typedef vector<ull>vull;
typedef vector<vull>vvull;

int main()
{
    l ts;
    cin>>ts;
    For1(t,ts)
    {
	l n,a,b,c,d,x,y,m;
	//l m[3]={0,0,0};
	
	vll p;
	
	cin>>n>>a>>b>>c>>d>>x>>y>>m;
	
	//x%=3;y%=3;
	p.push_back(ll(x,y));
	for(l i=1;i<n;i++)
	{
	    //x=((a*x+b)%m)%3;
	    //y=((c*y+d)%m)%3;
	    x=(a*x+b)%m;
	    y=(c*y+d)%m;
	    p.push_back(ll(x,y));
	}
	debug(p.size());
	int resp=0;
	
	for(int i=0;i<p.size();i++)
	    for(int j=i+1;j<p.size();j++)
		for(int k=j+1;k<p.size();k++)
		    if(i!=j && j!=k && i!=k)
			if((p[i].first+p[j].first+p[k].first)%3==0 && (p[i].second+p[j].second+p[k].second)%3==0)
			{
			    debug(p[i].first);
			    debug(p[j].first);
			    debug(p[k].first);
			    debug(p[i].second);
			    debug(p[j].second);
			    debug(p[k].second);

			    //cout<<"------"<<endl;
			    resp++;
			}

/*
	tr(p,it1)
	    tr(p,it2)
	    tr(p,it3)

		{
		    if(*it1!=*it2 && *it1!=*it3 && *it2!=*it3)
			if((it1->first+it2->first+it3->first)%3==0 && (it1->second+it2->second+it3->second)%3==0)
			    resp++;
*/
	
	
	cout<<"Case #"<<t<<": ";
	cout<<resp<<endl;
    }
    return 0;
}
