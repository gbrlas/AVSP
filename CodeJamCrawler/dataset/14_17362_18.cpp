#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
	int t,a,b,k,c,y;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		c=0;
		scanf("%d",&a);scanf("%d",&b);scanf("%d",&k);
		for(int j=0;j<a;j++){
			for(int m=0;m<b;m++){
				y=j & m;
				if(y<k)
				c++;
			}
		}
		printf("Case #%d: %d\n",i+1,c);
	}
}
