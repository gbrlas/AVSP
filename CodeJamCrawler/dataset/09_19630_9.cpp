#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<streambuf>
#include<sstream>
#include<list>
#include<stack>
#include<ostream>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX=570001;
int m[11][MAX];
int maskarr[MAX];
int ishappy(int N,int b){
	int k=N,sum=0;
	if(N==1) return m[b][N]=1;
	if(m[b][N]!=-1) return m[b][N];
	do {
		int x=k%b;
		k/=b;
		sum+=x*x;
	}while(k);
	
	m[b][N]=0;
	return m[b][N]=ishappy(sum,b);
}

int main(){
	int i,j;
	for(i=2;i<=10;i++) m[i][1]=1;
	memset(m,-1,sizeof(m));
	for(i=2;i<MAX;i++){
		for(j=2;j<=10;j++){
			 m[j][i]=ishappy(i,j);
			if(m[j][i]==1) maskarr[i]|=(1<<j);
		}
	}
	int no;
	string s;
	getline(cin,s);
	sscanf(s.c_str()," %d",&no);
	vector<int> v;
	for(i=1;i<=no;i++){
		getline(cin,s);
		stringstream str(s);
		int mask=0,x;
		while(str>>x) mask|=(1<<x);
		int ans=-1;
		for(j=2;j<MAX;j++) 
			if(maskarr[j] && ((maskarr[j]&mask)==mask)) { ans=j; break; };
		v.push_back(ans);
		
	}
	
	for(i=0;i<v.size();i++)
		printf("Case #%d: %d\n",i+1,v[i]);

	return 0;
}

