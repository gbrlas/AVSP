#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define FILL(a,val) memset((a),(int)val,sizeof(a));
#define CLEAR(a) FILL(a,0)
#define REP(i,n) for (int i=0, _n=(n); i<_n; ++i)
#define FOR(i,a,b) for (int i=(a), _n=(b); i<_n; ++i)
#define REPD(i,n) for (int _n=(n), i=_n; i>=0; --i)
#define FORD(i,b,a) for (int _n=(b), _a=(a), i=_n; i>=_a; --i)
#define PB push_back
#define VI vector<int>
#define VVI vector< VI >
#define MII map<int,int>
#define SZ(x) (x.size())

template <class T> inline void checkmin(T& a, const T& b){if (b<a) a=b;}
template <class T> inline void checkmax(T& a, const T& b){if (b>a) a=b;}
template <class T> inline T sqr(const T&a){return a*a;}
//bool myfunc(int i,int j){return i<j;}
//////////////////////////////////////////
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
//////////////////////////////////////////

//double round(double d){
//	return d>=0? floor(d+0.5): -floor(-d+0.5);
//}

int main(){
	freopen("B-large.in", "rt", stdin);
    freopen("B-large.out", "wt", stdout);
	int T;
	scanf("%d",&T);
	REP(t,T){
		int C;
		scanf("%d",&C);
		vector<string> sC;
		if (C>0){			
			REP(c,C){
				string s;
				cin>>s;
				sC.PB(s);
			}
		}
		int D;
		scanf("%d",&D);
		vector<string> sD;
		if (D>0){
			REP(d,D){
				string s;
				cin>>s;
				sD.PB(s);
			}			
		}
		int n;
		scanf("%d",&n);
		string sN;
		cin>>sN;

		//solve		
		vector<char> answer;
		int N;
		map<char,int> met;
		REP(i,SZ(sN)){	
			answer.PB(sN[i]);			
			met[sN[i]]++;
			if ((N=SZ(answer))>1){
				bool check_merge=0;
				//check_merge
				if (C>0){
					REP(c,SZ(sC)){
						if (answer[N-1]==sC[c][0] && answer[N-2]==sC[c][1]||
							answer[N-1]==sC[c][1] && answer[N-2]==sC[c][0]){
								check_merge=1;
								met[answer[N-2]]--;
								met[answer[N-1]]--;
								answer.erase(answer.end()-2,answer.end());
								answer.PB(sC[c][2]);
								met[sC[c][2]]++;
								break;
							}					
					}
				}
				if (check_merge==0){
					//check_opposite
					if (D>0){
						REP(d,SZ(sD)){
							if (met[sD[d][0]]>0 && met[sD[d][1]]>0){
								answer.clear();
								met.clear();	
								break;
							}
						}
					}
				}
			}
		}

		//output	
		printf("Case #%d: [",t+1);
		REP(i,SZ(answer)-1){
			printf("%c, ",answer[i]);
		}
		if (SZ(answer)>0){
			printf("%c",answer[SZ(answer)-1]);
		}
		printf("]\n");
	}

	return 0;
}