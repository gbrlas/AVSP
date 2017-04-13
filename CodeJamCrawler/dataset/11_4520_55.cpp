#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define MXN 200

using namespace std;

typedef long long LL;

int t,n;
char order_robot[MXN];
int order_button[MXN];

int getnextposition(int now,char robot){
	for (int i=now+1;i<=n;i++) if (order_robot[i]==robot) return order_button[i];
	return 0;
}

int main(){
	scanf("%d",&t);
	for (int ti=1;ti<=t;ti++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf(" %c %d",&order_robot[i],&order_button[i]);
		string tmp;
		getline(cin,tmp);
		int x(1),y(1),ans(0),order(0);
		while (order!=n){
			ans++;
			if (order_robot[order+1]=='O'){
				int where(getnextposition(order+1,'B'));
				if (order_button[order+1]==x) order++;
				else{
					if (x>order_button[order+1]) x--;else x++;
				}
				/*if (order<n&&order_robot[order+1]=='B'&&y==where){
					order++;
					continue;
				}*/
				if (y>where) y--;else if (y<where) y++;
			}else{
				int where(getnextposition(order+1,'O'));
				if (order_button[order+1]==y) order++;
				else{
					if (y>order_button[order+1]) y--;else y++;
				}
				/*if (order<n&&order_robot[order+1]=='O'&&x==where){
					order++;
					continue;
				}*/
				if (x>where) x--;else if (x<where) x++;
			}
			//cout << x << " " << y <<  " " << order << endl;
		}
		printf("Case #%d: %d\n",ti,ans);
	}
	return 0;
}
