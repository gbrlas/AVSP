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

long long get_first(long long n, long long nteams, long long p){
	if(p==nteams-1) return nteams-2;
	if(p==nteams) return nteams-1;
	for(int i=0; i<100; i++){
		if(p<=nteams/2){
			return (1LL<<(i+1))-2LL;
		}
		p-=nteams/2;
		nteams/=2;
	}
	return 0;
}

long long get_second(long long n, long long nteams, long long p){
	if(p==1) return 0;
	if(p==nteams) return nteams-1;
	vector< pair<long long, long long> > num;
	num.push_back(make_pair(2,2));
	for(int i=3; i<=n; i++){
		int len = num.size();
		for(int z=0; z<len; z++){
			num[z].second*=2LL;
		}
		num.push_back(make_pair(num[len-1].first*2LL,num[len-1].second+2));
	}
	long long sum = 1;
	for(int i=0; i<num.size(); i++){
		sum+=num[i].first;
		if(p<=sum) return num[i].second;
	}
	assert(false);
	return -1;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
//	long long nnn = 7;
//	long long ppp = 1;
//	ntests = (1<<nnn);
	for(int testnum=0; testnum<ntests; testnum++){
		long long n, p;
		cin>>n>>p;
//		n = nnn;
//		p = ppp++;
		long long nteams = (1LL<<n);
		long long first = get_first(n,nteams,p);
		long long second = get_second(n,nteams,p);
		cout<<"Case #"<<testnum+1<<": "<<first<<' '<<second<<endl;
	}
	return 0;
}
