#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define go(i,n) for(int i=0;i<n;i++)
#define go3(i,j,n) for(int i=j;i<n;i++)


struct node{

  int mean;
  int rem;
  node(){}
  node(int x,int y){
   mean=x;
   rem=y;
  }
 
};





bool operator < (node x,node y){
   if(x.mean<y.mean) return true;
   if(x.mean>y.mean) return false;
   return x.rem<y.rem;
}
 

int solve(vi v,int s,int p){
 priority_queue<node> pq;
 int n=sz(v);
 int r;
 node t;

 go(i,n)
 {
  r=v[i];
  t.mean=r/3;
  t.rem=r%3;
  pq.push(t);
 }

 int ans=0;

 while(pq.size())
  {
   t=pq.top(); pq.pop();

   //cout<<t.mean<<" "<<t.rem<<endl;

   if(t.mean>=p)  {ans++;  continue; }
   if(t.rem>0 && t.mean+1 >=p )  {ans++; continue; }

   if(s>0)
    {
     if(t.rem==2 && t.mean+2 >=p ) {ans++; s--; continue; }
     if(t.rem==0 && t.mean>0 && t.mean+1 >=p ) {ans++; s--; continue; }
    }
  }

 

 return ans;

}




void oku(){
  
 

 int T;
 cin>>T;
 int n,s,p;
 vi v;

 go(ii,T){
  cin>>n>>s>>p;
  v.clear();

  go(i,n)   v.pb(0), cin>>v[i];
   printf("Case #%d: %d",ii+1,solve(v,s,p));
  cout<<endl;
  
 
 }


}

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

oku();

return 0;

}