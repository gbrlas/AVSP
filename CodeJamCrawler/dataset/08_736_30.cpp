#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

typedef long long ll;

const double PI = atan(1.0) * 4.0;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)

using namespace std;

char str[50], tmp[50];
int N;

ll getNum(char* str, int s, int e) {
    char tmp[50];
    copy(str+s, str+e+1, tmp);
    tmp[e-s+1] = '\0';

    ll num = 0;
    for (int i = 0, N = strlen(tmp); i < N; ++i)
	num = num * 10 + (tmp[i] - '0');
    return num;
}

void add(map<ll,ll>& have, ll num) {
    map<ll,ll>::iterator p = have.find(num);
    if (p == have.end()){
	have[num] = 1;	
    } else {
	p->second++; 
    }
}

void update(map<ll,ll>& have, ll num, ll times) {
    map<ll,ll>::iterator p = have.find(num);
    if (p == have.end()){
	have[num] = times;
    } else {
	p->second += times; 
    }
}

int main() {
    int caseN;
    scanf("%d", &caseN);

//    printf("%lld\n", getNum("1234567", 1, 1));
//    printf("%lld\n", getNum("1234567", 1, 5));
//    printf("%lld\n", getNum("1234567", 2, 6));
    
    for (int cas = 1; cas <= caseN; ++cas) {
	multiset<ll> have[50];
	map<ll, ll> have2[50];
	
	scanf("%s", str);
	N = strlen(str);
//	printf("%d %s\n", N, str);

//	have[0].insert(getNum(str,0,0)); 
     	add(have2[0], getNum(str,0,0));
	//printf("insert: %d\n", getNum(str,0,0));
	for (int i = 1; i < N; ++i) {
//	    have[i].insert(getNum(str,0,i));
	    add(have2[i], getNum(str,0,i));
	    //printf("insert: %d\n", getNum(str,0,i));
	    for (int j = 1; j <= i; ++j){ // split point.
		ll nn = getNum(str, j, i);
		//printf("%d\n", nn);

//		for (multiset<ll>::iterator p  = have[j-1].begin(); p != have[j-1].end(); ++p){
//		    have[i].insert((*p) + nn);
//		    have[i].insert((*p) - nn);
//		}
		
		for (map<ll,ll>::iterator p = have2[j-1].begin(); p != have2[j-1].end(); ++p){
		    ll k = p->first;
		    ll f = p->second;
		    update(have2[i], k+nn, f);
		    update(have2[i], k-nn, f);
		}
	    }	
	}
/*
	ll cnt = 0;
	for (map<ll,ll>::iterator p = have2[N-1].begin(); p != have2[N-1].end(); ++p)
	    cnt += p->second;
	printf("total: %lld\n", cnt);
	   */ 
	ll cnt = 0;
	for (map<ll,ll>::iterator p = have2[N-1].begin(); p != have2[N-1].end(); ++p) {
	    ll k = p->first;
	    if (k == 0 || k%2==0 || k%3==0 || k%5==0 || k%7==0) cnt += p->second;
	}
	
/*	
	for (multiset<ll>::iterator p  = have[N-1].begin(); p != have[N-1].end(); ++p){
	    int k = *p;
	    if (k == 0) cnt++;
	    else if (k%2 == 0) cnt++;
	    else if (k%3 == 0) cnt++;
	    else if (k%5 == 0) cnt++;
	    else if (k%7 == 0) cnt++;
	    else {
		continue;
	    }
//	    printf(" %d\n", k);
	}*/

	printf("Case #%d: %lld\n", cas, cnt);
    }

    return 0;
}
