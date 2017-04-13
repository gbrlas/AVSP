#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <map>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)	
//#define fore(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define ll long long
#define MP make_pair 
#define PB push_back
#define X first
#define Y second
#define ALL(a) (a).begin(),(a).end()
#define sz(a) (a).size()
#define len(s) (s).length() 

#pragma comment(linker,"/STACK:100000000")

using namespace std;			

template <class T>
void out(vector<T> & a,string s="%3d "){
	int i,n=a.size();
	rep(i,n) printf(s.c_str(),a[i]);
	printf("\n");
}

template <class T> 
void out(T * a,int n,string s="%3d "){
	int i;
	rep(i,n) printf(s.c_str(),a[i]);
	printf("\n");
} 



set<char> vow;
void init(){
        vow.insert('a');
        vow.insert('e');
        vow.insert('i');
        vow.insert('o');
        vow.insert('u');
}

bool check(string s,ll st,ll end, ll p){
    int i;
    int con=0;
    
    rp(i,st,end+1){
        if (vow.find(s[i])!=vow.end()) con=0;
        else con++;
        if (con>=p) return true;
    }
    return false;
}

ll i,j,N,M,n,m,k,p;
string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
#endif
//C:\\Olimp2013\\GoogleJamR1_C_2013\\COnson\\

    init();
    ll T,ii;
    
    cin>>T;
    //cout<<T;
   // if(0)
    rep(ii,T){
    
    cin>>s>>p;
	check(s,0,len(s)-1,p);
    ll k=0;
    rep(i,len(s))
        rep(j,len(s))
        if (check(s,i,j,p)) 
			k++;
    printf("Case #%I64i: %I64d\n",ii+1,k);
    }
	
return 0;
}