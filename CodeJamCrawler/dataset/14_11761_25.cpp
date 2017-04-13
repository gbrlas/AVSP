#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define eps 1e-07
#define SGN(x) ((x)<-eps?-1:(x)>eps?1:0)

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
int main(){
    int cases;
    cin>>cases;
    f(t,1,cases+1){
        int res1,res2;        
        cin>>res1;
        map<int,bool> v;
        int val;
        f(i,0,4){
            f(j,0,4){
                cin>>val;
                if((i+1) == res1){
                    v[val]=true;
                }
            }
        }
        cin>>res2;
        int r=-1;
        int cont=0;
        f(i,0,4){
            f(j,0,4){
                cin>>val;
                if((i+1) == res2){
                    if(v[val]){
                        cont++;
                        r=val;
                    }
                        
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        if(cont == 1){
            cout<<r<<endl;
        }
        else if(cont==0){
            cout<<"Volunteer cheated!"<<endl;
        }
        else {
            cout<<"Bad magician!"<<endl;
        }
    }
    return 0;
}
