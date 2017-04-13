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
#define fore(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

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

int i,j,N,M,n,m,k,p;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
#endif
    int T, n, init, flag;
    cin>>T;
    rep(i,T){
        k=0;
        //cin>>init>>n;
        scanf("%d %d",&init,&n);
        vector<int> a(n);
        vector<int> res(n,0);
        vector<int> smres(n,0);
        vector<int> sm(n,0);
        rep(j,n){
            scanf("%d",&(a[j]));
        }
        sort(ALL(a));
        //ll sm=init;
       // cout<<n<<endl;
        sm[0] = init;
        rep(j,n){
            if (j) sm[j]=sm[j-1];
            
            if (sm[j] > a[j])
            sm[j] += a[j];
            else {
               k=1;
               sm[j] += sm[j]-1;
               while (sm[j] <= a[j] && k<=n) {k++; sm[j] += (sm[j]-1);}
               res[j]=k;
               sm[j] += a[j];
            }
        }
        if (n>0)
        smres[0]=res[0];
        
        rp(j,1,n){
            smres[j] += smres[j-1] + res[j];
        }
     /*  cout<<init<<endl;
        out(a);
        out(sm);
        out(res);
        out(smres);
       */ 
        int ans=smres[n-1];
        for(j=n-1;j>0;--j){
            ans =min(ans,smres[j-1] + (n-j));
        }
        ans = min(ans, n);
        
        printf("Case #%d: %d\n",i+1,ans);
    }
    

   	
	
return 0;
}