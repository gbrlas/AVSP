#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <conio.h>
using namespace std;
static const double EPS = 1e-5;
#define MAXM 2000

int kai[20];
short m[MAXM];
int pr[20][2000];
short prc[20][2000];
int p;

bool canDec(int k,int dan){
	bool flag=true;
	for(int x=kai[k+1]*dan ; x<kai[k+1]*(dan+1) && flag ; x++){
		if(m[x]<=0)flag=false;
	}
	return flag;
}

void decThis(int k,int dan){
	for(int x=kai[k+1]*dan;x<kai[k+1]*(dan+1);x++){
		m[x]--;
	}
}

void incThis(int k,int dan){
	for(int x=kai[k+1]*dan;x<kai[k+1]*(dan+1);x++){
		m[x]++;
	}
}

long saiki(int k,int dan){
	if(k==0){
		if(canDec(k,dan)){
			return pr[k][dan];
		}
		else return 0;
	}
	else{
		long rtn1=saiki(k-1,dan*2) + saiki(k-1,dan*2+1);
		long rtn2=0;
		if(canDec(k,dan)){
			decThis(k,dan);
			rtn2=saiki(k-1,dan*2) + saiki(k-1,dan*2+1) + pr[k][dan];
			incThis(k,dan);
		}
		if(rtn1>rtn2)return rtn1;
		else return rtn2;
	}
}

int main(){
	int t,u,team,x,sum,y;
	cin >>t;
	for(x=0;x<11;x++){
		kai[x]=pow(2,x);
	}
	for(u=0;u<t;u++){
		cin >> p;
		team=pow(2,p);
		for(x=0;x<team;x++){
			cin >> m[x];
		}
		sum=0;
		memset(prc,0,sizeof(prc));
		memset(pr,0,sizeof(pr));
		for(x=0;x<p;x++){
			for(y=0;y<kai[p-1-x];y++){
				cin >> pr[x][y];
				sum+=pr[x][y];
				prc[x][y]=1;
			}
		}

		int cur=0;
		int count=0;

		long rtn1 = saiki(p-2,0)+saiki(p-2,1);
		long rtn2=0;
		if(canDec(p-1,0)){
			decThis(p-1,0);
			rtn2 = saiki(p-2,0)+saiki(p-2,1)+pr[p-1][0];
			incThis(p-1,0);
		}

		if(rtn1<rtn2)rtn1=rtn2;

		cout << "Case #" << u+1 << ": " << sum-rtn1;
		cout << endl;
	}
	return 0;
}