#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

long long gg(int t,int g){
	long long ret=1;
	for(int i=0;i<g;i++){
		ret*=(long long)t;
	}
	return ret;
}

int main(){
	int tn;cin>>tn;
	for(int i=0;i<tn;i++){
		string s;cin>>s;
		long long ans=0;
		int num[65];
		string tmp;int t=1;
		for(int j=0;j<s.size();j++){
			int tt=t;int f=1;
			for(int k=0;k<tmp.size();k++)if(tmp[k]==s[j]){
				tt=k+1;f=0;break;
			}
			num[j]=tt;
			if(f){
				tmp+=s[j];t++;
			}
		}
		for(int j=0;j<s.size();j++){
			if(num[j]==2)num[j]=0;
			else{
				if(num[j]!=1)num[j]--;
			}
		}
		//for(int j=0;j<s.size();j++)cout<<num[j]<<" ";cout<<endl;
		int g=0;
		for(int j=s.size()-1;j>=0;j--){
			ans+=num[j]*gg(max(t-1,2),g);g++;
		}
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
}
