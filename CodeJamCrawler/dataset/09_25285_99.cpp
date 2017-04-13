#include <fstream>
//#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#include <set>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");
int a[105][105];
char b[105][105];
int t,h,w;
int dx[]={-1, 0,0,1};
int dy[]={ 0,-1,1,0};

pair <int, int> minel(pair <int, int> x){
	pair <int, int> minind(-1,-1);
	if(x.first<0) return minind;
	if(x.first>=h) return minind;
	if(x.second<0) return minind;
	if(x.second>=w) return minind;
	for(int i=0; i<4; i++){
		if((x.first+dx[i]>-1)&&(x.first+dx[i]<h)&&(x.second+dy[i]>-1)&&(x.second+dy[i]<w)){
			if(a[x.first][x.second]>a[x.first+dx[i]][x.second+dy[i]]){
				if(minind.first<0){
					minind.first=x.first+dx[i];
					minind.second=x.second+dy[i];
				}else{
					if(a[minind.first][minind.second]>a[x.first+dx[i]][x.second+dy[i]]){
						minind.first=x.first+dx[i];
						minind.second=x.second+dy[i];
					}
				}
			}
		}
	}
	return minind;
}


int main(){
	
	cin>>t;
	pair <int, int> tmp,tmp1;
	for(int l=0; l<t; l++){
		cin>>h>>w;
		queue < pair <int, int> > q;
		pair <int, int> tmp, tmp1;
		char ch='a';
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin>>a[i][j];
			}
		}
		memset(b,0, sizeof(b));
		for(int fr=0; fr<h; fr++){
			for(int sc=0; sc<w; sc++){
				if(b[fr][sc]==0){
					tmp.first=fr;
					tmp.second=sc;
					q.push(tmp);
				}else{
					continue;
				}
				while(!q.empty()){
					tmp1=q.front();
					b[tmp1.first][tmp1.second]=ch;
					q.pop();
					tmp=minel(tmp1);
					if(tmp.first>=0){
						q.push(tmp);
						b[tmp.first][tmp.second]=ch;
					}
					for(int i=0; i<4; i++){
						tmp.first=tmp1.first+dx[i];
						tmp.second=tmp1.second+dy[i];
						
						if(minel(tmp)==tmp1){
							if(b[tmp.first][tmp.second]==0){
								q.push(tmp);
								b[tmp.first][tmp.second]=ch;
							}
						}
					}
				}
				ch++;
			}
		}
		cout<<"Case #"<<l+1<<":\n";
		for(int i=0; i<h; i++){
			for(int j=0; j<w-1; j++){
				cout<<b[i][j]<<' ';
			}
			cout<<b[i][w-1]<<endl;
		}
		
	}
	return 0;
}	