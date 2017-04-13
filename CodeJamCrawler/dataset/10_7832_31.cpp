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

int main(){
	int t,u,p,team,x,sum,y;
	cin >>t;
	int kai[20];
	short m[2000];
	int pr[20][2000];
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
		for(x=0;x<p;x++){
			for(y=0;y<kai[p-1-x];y++){
				cin >> pr[x][y];
				sum+=pr[x][y];
			}
		}

		int cur=0;
		int count=0;
		for(x=0;x<p;x++){
			int adv=kai[x+1];
			for(cur=0;cur<kai[p];cur+=adv){
				bool flag=true;
				for(y=cur;y<cur+adv && flag;y++){
					if(m[y]<=0) flag=false;
				}
				if(flag){
					count++;
					for(y=cur;y<cur+adv && flag;y++){
						m[y]--;
					}
				}
			}
		}


		cout << "Case #" << u+1 << ": " << sum-count;
		cout << endl;
	}
	getch();
	return 0;
}