#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back

#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef  long long LL;
typedef  long long ll;
int coun[300];
int pos[300];
int dist=0;
int n;
int solve(double mid){
	double newpositions[n];
	for(int i=0;i<n;i++){
		if(i==0){
			double left_extreme=(double)pos[i]-mid;
			newpositions[i]=left_extreme+(coun[i]-1)*dist;
			double right_extreme=left_extreme+(coun[i]-1)*dist;
			if(right_extreme - pos[i]> mid ){
				return 0;
			}
		}
		else{
			double left_extreme=(double)pos[i]-mid;
			if(left_extreme<newpositions[i-1]+dist){
				left_extreme=newpositions[i-1]+dist;
			}
			double right_extreme=left_extreme+(coun[i]-1)*dist;
			if(right_extreme -pos[i]> mid ){
				return 0;
			}
			else{
				newpositions[i]=right_extreme;
			}
		}
	}
	return 1;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=GI;
	int kase=0;
	while(t--){
		kase++;
		cin>>n>>dist;
		for(int i=0;i<n;i++){
			cin>>pos[i]>>coun[i];
		}
		double low=0.0000000;
		double high=1000000000000.000000;
		double mid;
		while(abs(low-high)>0.0000001){
			mid=(low)+(high-low)/2;
		//	cout<<mid<<endl;
			if(solve(mid))
				high=mid;        
            else low=mid;         
		}
//		cout.precision(10);
		cout<<"Case #"<<kase<<": ";	
		cout<<low<<endl;
	}
    GI;
    return 0;
}
