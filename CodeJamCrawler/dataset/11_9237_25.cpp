#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <fstream>
#include <iostream>
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
const int maxn=1000;
vector<int> Q;
int trans[26][26];
bool isclear[26][26];
int C,D,N;
int main()
{
	int t,caseid,i,j;
//	ifstream fin("B.in");
//	ifstream fin("B-small-attempt0.in");
//	ifstream fin("B-small-attempt1.in");
	ifstream fin("B-large.in");
//	ifstream fin("B-large-practice.in");
	FILE* pout=fopen("B.out","w");	
	fin>>t;
    for (caseid=1;caseid<=t;caseid++)
    {
		Q.clear();
		memset(isclear,0,sizeof(isclear));
		memset(trans,255,sizeof(trans));
		fin>>C;
		string tmp;
		for (i=0;i<C;i++)
		{
			fin>>tmp;
			trans[tmp[0]-'A'][tmp[1]-'A']=tmp[2]-'A';
			trans[tmp[1]-'A'][tmp[0]-'A']=tmp[2]-'A';
		}
		fin>>D;
		for(i=0;i<D;i++)
		{
            fin>>tmp;
            isclear[tmp[0]-'A'][tmp[1]-'A']=true;
            isclear[tmp[1]-'A'][tmp[0]-'A']=true;
        }
        fin>>N;
        fin>>tmp;
        int tt;
        for(i=0;i<N;i++)
        {
            int sz=SZ(Q);
            if(sz>=1)
            {
               if((tt=trans[Q[sz-1]][tmp[i]-'A'])>=0)
               {
                  Q.pop_back();Q.push_back(tt);
               }
               else
               {
                   bool isopp=false;
                   for(int j=0;j<sz;j++) if(isclear[Q[j]][tmp[i]-'A']) 
                   {isopp=true; break;}
                   if(isopp) Q.clear();
                   else Q.push_back(tmp[i]-'A');
               }
            }
            else
            {
                Q.push_back(tmp[i]-'A');
            }
        }
        
		fprintf(pout,"Case #%d: ",caseid);
		fprintf(pout,"[");
		bool first=true;
		for(i=0;i<SZ(Q);i++)
		{
            if(first) {fprintf(pout,"%c",Q[i]+'A');first=false;}
            else {fprintf(pout,", %c",Q[i]+'A');}
            
        }
		fprintf(pout,"]\n");
	}
	fin.close();
	fclose(pout);
	system("pause");
	return 0;
}

