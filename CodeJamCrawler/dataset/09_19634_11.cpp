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

inline int mycount(vector<int> &v){
	int i,j;
	int c=0;
	for(i=0;i<v.size();i++){
		for(j=i+1;j<v.size();j++){
			if(v[i]>v[j]) c++;
		}
	}
	return c;
}

int main(){
	int no;
	int tc=1;
	cin >> no;
	while(no--){
		int ans=(1<<25);
		int n;
		cin >> n;
		string s;
		vector<string> v;
		vector<int> r;
		int i,j;
		for(i=0;i<n;i++)
		{	
			r.push_back(i);
			cin >> s;
			v.push_back(s);
		}
		do{
			vector<string> tmp;
			for(i=0;i<r.size();i++){
				tmp.push_back(v[r[i]]);
			}
			bool bad=false;
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if(tmp[i][j]=='1') bad=true;
				}
			}
			if(bad) continue;
			int k=mycount(r);
	//		printf("%d\n",k);
			for(i=0;i<n;i++)
	//		printf("tmp[i]=%s,%d,bad=%d\n",tmp[i].c_str(),r[i],bad);
			ans=min(ans,k);
			
		}while(next_permutation(r.begin(),r.end()));
		printf("Case #%d: %d\n",tc++,ans);
	}
	return 0;
}

