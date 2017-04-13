#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int T,ti,n;
int nx,ny;
vector<pair<int,int> >a;
vector<int> x,y;

int main(){
	ti=0;
	for (scanf("%d",&T);T--;){
		scanf("%d",&n);
		a.clear();
		x.clear();
		y.clear();
		for (int i=0;i<n;i++){
			char c;
			int pos;
			scanf(" %c%d",&c,&pos);
			pos--;
			if (c=='O') a.PB(MP(0,pos)),x.PB(pos);
			else a.PB(MP(1,pos)),y.PB(pos);
		}
		int ans;
		nx=ny=ans=0;
		for (int i=0,j=0,k=0;;){
			bool mx=false,my=false;
			if (a[k].first==0&&a[k].second==nx) k++,mx=true,i++;
			else if (a[k].first==1&&a[k].second==ny) k++,my=true,j++;
			if (!mx&&i<x.size()){
				if (x[i]>nx) nx++;
				if (x[i]<nx) nx--;
			}
			if (!my&&j<y.size()){
				if (y[j]>ny) ny++;
				if (y[j]<ny) ny--;
			}
			ans++;
			if (k==a.size()) break;
		}
		ti++;
		printf("Case #%d: %d\n",ti,ans);
	}
    return 0;
}
