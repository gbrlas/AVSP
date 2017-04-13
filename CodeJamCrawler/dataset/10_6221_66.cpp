#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<int,int> pii;
typedef __int64 ll;
#define MP(X,Y) make_pair(X,Y)
#define two(X) (1<<(X))//NOTES:two(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int)(x).size())
template<class T> inline T sqr(T x){return x*x;}
const double eps=1e-6;
const int maxn=1000000+5;

void main()
{
	int t,caseid,i,j;
//	ifstream fin("A.in");
	ifstream fin("A-small-attempt0.in");
//	ifstream fin("A-large.in");
	FILE* pout=fopen("A.out","w");	
	fin>>t;
	int n,k;
    for (caseid=1;caseid<=t;caseid++)
    {
		fin>>n>>k;
		int mo=1<<n;
		if ((k%mo)==mo-1)
		{
			fprintf(pout,"Case #%d: ON\n",caseid);
		}
		else
		{
			fprintf(pout,"Case #%d: OFF\n",caseid);
		}
    }
	fin.close();
	fclose(pout);
}

