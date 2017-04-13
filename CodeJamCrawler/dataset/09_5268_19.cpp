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
#include<iostream>

using namespace std;

int main(){
	int tn;cin>>tn;
	for(int ttt=0;ttt<tn;ttt++){
		int n;cin>>n;
		int d[30]={0};int tmpp=0;
		while(n!=0){d[tmpp++]=n%10;n/=10;}
		int tmp[30]={0};
		for(int i=0;i<tmpp;i++){tmp[tmpp-i-1]=d[i];}
		for(int i=0;i<tmpp;i++){d[i]=tmp[i];}
		//for(int i=0;i<tmpp;i++)cout<<tmp[i];cout<<endl;
		bool t=next_permutation(d,d+tmpp);
		cout<<"Case #"<<(ttt+1)<<": ";
		if(t){
			for(int i=0;i<tmpp;i++)cout<<d[i];cout<<endl;
		}
		else {
			int tttt=0;
			while(d[tttt]==0)tttt++;
			cout<<d[tttt];
			for(int i=0;i<=tttt;i++)cout<<"0";
			for(int i=tttt+1;i<tmpp;i++)cout<<d[i];cout<<endl;
		}
	}
}
