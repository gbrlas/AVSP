#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b){
	return(a.first<b.first);
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n, p;
		cin>>n>>p;
		int nteams = (1<<n);
		vector< pair<string,int> > a(nteams);
		vector<bool> best(nteams,false);
		vector<bool> any(nteams,false);
		for(int team=0; team<nteams; team++){
			a[0].first = "";
			a[0].second = team;
			int cur = 1;
			for(int i=nteams-1; i>=0; i--){
				if(i==team) continue;
				a[cur].first = "";
				a[cur].second = i;
				cur++;
			}
			for(int round=0; round<n; round++){
				for(int i=0; i<nteams; i+=2){
					if(a[i].second<a[i+1].second){
						a[i].first+='0'; //win
						a[i+1].first+='1'; //loose
					}else if(a[i].second>a[i+1].second){
						a[i].first+='1'; //loose
						a[i+1].first+='0'; //win
					}
				}
				stable_sort(a.begin(),a.end(),cmp);
			}
			int idx = -1;
			for(int i=0; i<nteams; i++){
				if(a[i].second==team){ idx = i; break; }
			}
			assert(idx>=0 && idx<nteams);
			best[team] = (idx<p);
		}
		for(int team=0; team<nteams; team++){
			a[nteams-1].first = "";
			a[nteams-1].second = team;
			int cur = 0;
			for(int i=nteams-1; i>=0; i--){
				if(i==team) continue;
				a[cur].first = "";
				a[cur].second = i;
				cur++;
			}
//			for(int i=0; i<nteams; i++) cout<<a[i].second<<": "<<a[i].first<<endl;
//			cout<<"-----"<<endl;
			for(int round=0; round<n; round++){
				for(int i=0; i<nteams; i+=2){
					if(a[i].second<a[i+1].second){
						a[i].first+='0'; //win
						a[i+1].first+='1'; //loose
					}else if(a[i].second>a[i+1].second){
						a[i].first+='1'; //loose
						a[i+1].first+='0'; //win
					}
				}
				stable_sort(a.begin(),a.end(),cmp);
//				for(int i=0; i<nteams; i++) cout<<a[i].second<<": "<<a[i].first<<endl;
//				cout<<"-----"<<endl;
			}
			int idx = -1;
			for(int i=0; i<nteams; i++){
				if(a[i].second==team){ idx = i; break; }
			}
			assert(idx>=0 && idx<nteams);
			any[team] = (idx<p);
		}
//		for(int i=0; i<nteams; i++) cout<<any[i]<<' ';
//		cout<<endl;
//		for(int i=0; i<nteams; i++) cout<<best[i]<<' ';
//		cout<<endl;
		int guaranteed = -1;
		for(int i=nteams-1; i>=0; i--){
			if(any[i]){ guaranteed = i; break; }
		}
		assert(guaranteed>=0);

		int could = -1;
		for(int i=nteams-1; i>=0; i--){
			if(best[i]){ could = i; break; }
		}
		assert(could>=0);
		cout<<"Case #"<<testnum+1<<": "<<guaranteed<<' '<<could<<endl;
	}
	return 0;
}
