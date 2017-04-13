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
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cases=0;
    while(t--){
		 cases++;
         int n;
         cin>>n;
         char x;
         int b;
         vector<pair<char,int> > input;
         vector<int>B;
         vector<int>O;
         int curA=1;
         int curB=1;
         for(int i=0;i<n;i++){
			cin>>x>>b;
			if(x=='O'){
				O.pb(b);
			}	
			else {
				B.pb(b);
			}
			input.pb(make_pair(x,b));
		 }
		vector<int>newO;
		vector<int>newB;
		if(O.size()>0)
			newO.pb(O[0]);
    	for(int i=1;i<O.size();i++){
			int diff=abs(O[i-1]-O[i]);
			newO.pb(newO[i-1]+diff);
        }
        if(B.size()>0)
			newB.pb(B[0]);
    	for(int i=1;i<B.size();i++){
			int diff=abs(B[i-1]-B[i]);
			newB.pb(newB[i-1]+diff);
        }
       /* for(int i=0;i<O.size();i++)
        	cout<<O[i]<<" ";
        cout<<endl;
        for(int i=0;i<B.size();i++)
        	cout<<B[i]<<" ";
        cout<<"\n\n\n\n";*/
        int sz=input.size();
        curA=1;curB=1;
        int time=0;
        int index=0;
        int ocount=0;
        int bcount=0;
        while(1){
			int flag=0;
//			cout<<curA<<"\t"<<curB<<"\ttime  "<<time<<endl;
			if(index>=input.size())
				break;
			if(index<input.size() && input[index].first=='O' && curA>=newO[ocount]){
				ocount++;
				index++;
				time++;
				curB++;
				curA=newO[ocount-1];
				//cout<<curA<<"\t"<<curB<<"\ttime  "<<time<<endl;
				flag=1;
			}
	
			if(index>=input.size())
				break;
			if(index<input.size() && input[index].first=='B' && curB>=newB[bcount]){
				bcount++;
				index++;
				time++;
				curA++;
				curB=newB[bcount-1];
			//	cout<<curA<<"\t "<<curB<<"\ttime  "<<time<<endl;
				flag=1;
			}
			if(index>=input.size())
				break;
			if(flag==0){
				time++;
				curA++;
				curB++;
			}
		}
		 
		 printf("Case #%d: ",cases);
		 printf("%d\n",time);
		 
    }
    GI; 
    return 0;
}
