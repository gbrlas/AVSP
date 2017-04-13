#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

int n,m;
int mp[101][101];
int vx[10001];
int vy[10001];
int memo2[100][100];
int memo3[100][100];
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};

int chh(int mx,int my){
	int ht[4]={10001,10001,10001,10001};
	for(int i=0;i<4;i++){
		int nx=mx+dx[i];int ny=my+dy[i];
		if(nx>=0)if(nx<m)if(ny>=0)if(ny<n)if(mp[my][mx]>mp[ny][nx]){
				//cout<<mp[ny][nx]<<endl;
			ht[i]=mp[ny][nx];
		}
	}
	//cout<<mx<<my<<" ";for(int i=0;i<4;i++)cout<<ht[i]<<" "<<endl;
	int minn=10001;int minnum=-1;
	for(int i=0;i<4;i++)if(ht[i]<minn){
		minn=ht[i];minnum=i;
	}
	return minnum+1;
}

int main(){
	int tn;cin>>tn;
	for(int ttt=0;ttt<tn;ttt++){
		cout<<"Case #"<<(ttt+1)<<":"<<endl;
		cin>>n>>m;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)cin>>mp[i][j];
		}
		int ch=1;
		memset(vx,0,sizeof(vx));
		memset(vy,0,sizeof(vy));
		memset(memo2,0,sizeof(memo2));
		memset(memo3,0,sizeof(memo3));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(memo2[i][j])continue;
				int f=0;int mx=j;int my=i;
				int chtmp=ch;
				int vp=0;int ifch=0;
				//cout<<"hoge "<<i<<" "<<j<<endl;
				while(f==0){
					//cout<<mx<<" "<<my<<endl;
					if(memo2[my][mx]){
						chtmp=memo3[my][mx];
						ifch=1;
						f=1;continue;
					}
					memo2[my][mx]=1;
					vx[vp]=mx;
					vy[vp++]=my;
					int tmpp=chh(mx,my);//cout<<" "<<tmpp<<endl;
					if(tmpp==0){
						f=1;continue;
					}
					my+=dy[tmpp-1];
					mx+=dx[tmpp-1];
				}
				//cout<<vp<<endl;
				for(int k=0;k<vp;k++)memo3[vy[k]][vx[k]]=chtmp;
				if(ifch==0)ch++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++)cout<<(char)('a'+memo3[i][j]-1)<<" ";
			cout<<(char)('a'+memo3[i][m-1]-1)<<endl;
		}
	}
	return 0;
}
