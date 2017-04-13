#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int n,d,l;
int ans;
int memo[5001][11];
string lag[26];
string target[26];

void perse(int i,vector<string> p[10]){
	int r=0;
	for(int j=0;j<l;j++){
		if(target[i][r]!='('){
			string ttt;
			ttt+=target[i][r];
			p[j].push_back(ttt);
			r++;
			continue;
		}
		else{
			r++;
			while(target[i][r]!=')'){
				string ttt;
				ttt+=target[i][r];
				p[j].push_back(ttt);
				r++;
			}
			r++;
		}
	}
	/*ddcout<<"deb!!!"<<endl;
	for(int k=0;k<l;k++){
		for(int j=0;j<p[k].size();j++)cout<<p[k][j]<<" ";cout<<endl;
	}
	cout<<"end deb!!!"<<endl;*/
}

int main(){
	cin>>l>>d>>n;
	for(int i=0;i<d;i++)cin>>lag[i];
	for(int i=0;i<n;i++)cin>>target[i];
	sort(lag,lag+d);
	//for(int i=0;i<d;i++)cout<<lag[i]<<endl;;
	for(int i=0;i<n;i++){
		vector< string > p[10];
		perse(i,p);
		memset(memo,0,sizeof(memo));
		for(int j=0;j<10;j++)sort(p[j].begin(),p[j].end());
		/*for(int j=0;j<l;j++){
			for(int k=0;k<p[j].size();k++)cerr<<p[j][k]<<" ";cout<<endl;
		}*/
		for(int j=0;j<l;j++){
			for(int k=0;k<d;k++){
				for(int o=0;o<p[j].size();o++){
					string tt;tt+=lag[k][j];
					string ttt=p[j][o];
					//cerr<<"hoge"<<endl;
					//cerr<<tt<<" "<<ttt<<" "<<j<<" "<<k<<" "<<o<<endl;
					if(tt==ttt)memo[k][j]=1;
				}
			}
		}
		ans=0;
		for(int j=0;j<d;j++){
			int tmp=0;
			for(int k=0;k<l;k++)tmp+=memo[j][k];
			if(tmp==l)ans++;
		}
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl; 
	}
	return 0;
}
