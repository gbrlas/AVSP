#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

struct str{
	long long x1, y1, x2, y2;
	int num;
	bool operator<(const str& o)const{
		return num<o.num;
	}
};

pair<long long,int> r[1110];
str rez[1110];
int nrez;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		long long W, L;
		cin>>n;
		cin>>W>>L;
		for(int i=0; i<n; i++){ cin>>r[i].first; r[i].second = i; }
		sort(&r[0],&r[n]);
		nrez = 0;
		long long curx=-r[n-1].first;
		bool left = true;
		for(int tt=n-1; tt>=0; tt--){
			if(left){
				if(curx+r[tt].first>W){ curx = W+r[tt].first; left = false; }
			}else{
				if(curx-r[tt].first<0){ curx = -r[tt].first; left = true; }
			}
			long long x1, x2;
			if(left){
				x1 = curx; x2 = curx+2*r[tt].first;
			}else{
				x2 = curx; x1 = curx-2*r[tt].first;
			}
			long long maxH = -r[tt].first;
			for(int i=0; i<nrez; i++){
				if(rez[i].x1<x2 && x2<rez[i].x2 || rez[i].x1<x1 && x1<rez[i].x2){
					maxH = max(maxH,rez[i].y2);
				}
			}
			rez[nrez].x1 = x1;
			rez[nrez].x2 = x2;
			rez[nrez].y1 = maxH;
			rez[nrez].y2 = maxH+2*r[tt].first;
			rez[nrez].num = r[tt].second;
			if(left) curx = x2;
			else curx = x1;
			nrez++;
		}
		sort(&rez[0],&rez[nrez]);
		cout<<"Case #"<<testnum+1<<":";
		for(int i=0; i<nrez; i++){
			cout<<' '<<setprecision(6)<<setiosflags(ios::showpoint|ios::fixed)<<(rez[i].x1+rez[i].x2)/2.0;
			cout<<' '<<setprecision(6)<<setiosflags(ios::showpoint|ios::fixed)<<(rez[i].y1+rez[i].y2)/2.0;
		}
		cout<<endl;
	}
	return 0;
}
