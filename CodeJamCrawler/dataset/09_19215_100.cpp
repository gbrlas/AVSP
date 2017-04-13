#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
int dec(char a){
	if(a>='0' && a<='9') return (a-'0');
	return (a-'a')+10;
}
int main()
{
	int i,j,n;vector <lint> out;scanf("%d\n",&n);
	int sumi[40];
	for(i=0;i<n;i++){
		string a;cin>>a;
//		if(a.size()==1){out.pb(0);continue;}
		int t=0,f=0;lint ret=0;
		for(j=0;j<36;j++) sumi[j]=-2;
		for(j=0;j<a.size();j++){
			sumi[dec(a[j])]=-1;
		}
		for(j=0;j<36;j++){
			if(sumi[j]==-1) t++;
		}
		for(j=0;j<a.size();j++){
			if(sumi[dec(a[j])]==-1){sumi[dec(a[j])]=f;f++;}
		}
		if(t==1){
			for(j=0;j<36;j++){
				if(sumi[j]==0) sumi[j]=1;
			}
		}
		if(t==1) t++;
		for(j=0;j<1296;j++){
			int k=j/36,l=j%36;
			if(sumi[k]==0 && sumi[l]==1){
				sumi[k]=1;sumi[l]=0;break;
			}
		}
		for(j=0;j<a.size();j++){
			ret*=t;ret+=sumi[dec(a[j])];
		}
		out.pb(ret);
	}
	for(i=0;i<n;i++) cout<<"Case #"<<i+1<<": "<<out[i]<<'\n';
	return 0;
}
