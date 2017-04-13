#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define INF 0x3F3F3F3F

//Compilar com -DDEBUG
#ifdef DEBUG
#define debug(x) (cout<< "--> " << #x << " = " << x << endl)
#else
#define debug(x) ;
#endif

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii,aresta;//(peso,orig,dest)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef unsigned long long ull;

int main()
{
    int testes;
    cin>>testes;
    for(int teste=1;teste<=testes;teste++)
    {
	int n;
	cin>>n;
	vi x(n),y(n);
	for(int i=0;i<n;i++)
	    cin>>x[i];
	for(int i=0;i<n;i++)
	    cin>>y[i];
	sort(all(x));
	sort(rall(y));
	int resp=0;
	for(int i=0;i<n;i++)
	{
	    resp+=x[i]*y[i];
	    debug(x[i]);
	    debug(y[i]);
	}
	cout<<"Case #"<<teste<<": "<<resp<<endl;
    }
    return 0;
}
