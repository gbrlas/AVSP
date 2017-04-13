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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
string fa="Case #";
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int main(){
	vector <string> out;int i,j,n;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
/*		lint a;cin>>a;string s;lint ret=0;
		for(j=0;j<22;j++){
			s+=((a%10)+'0');a/=10;
		}
		reverse(s.begin(),s.end());
*/
		string s,s1;cin>>s;s="0"+s;
		next_permutation(s.begin(),s.end());
//		printf("%s\n",s);
//		cout<<s<<'\n';
//		for(j=0;j<s.size();j++){ret*=10;ret+=(s[j]-'0');cout<<ret<<'\n';}
//		out.pb(ret);
		if(s[0]=='0'){
			for(j=1;j<s.size();j++) s1+=s[j];
		}
		else s1=s;
//		cout<<s1<<'\n';
		out.pb(s1);
//		cout<<fa<<i+1<<": "<<s<<'\n';
	}
	for(i=0;i<n;i++) cout<<"Case #"<<i+1<<": "<<out[i]<<'\n';
//	for(i=0;i<n;i++) cout<<out[i]<<'\n';
	return 0;
}
