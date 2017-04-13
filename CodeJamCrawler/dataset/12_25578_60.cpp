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


string s1[]={"ejp","mysljylc","kd","kxveddknmc","re","jsicpdrysi","rbcpc","ypc","rtcsra","dkh","wyfrepkym","veddknkmkrkcd","de","kr","kd","eoya","kw","aej","tysr","re","ujdr","lkgc","jv"};
string s2[]={"our","language","is","impossible","to","understand","there","are","twenty","six","factorial","possibilities","so","it","is","okay","if","you","want","to","just","give","up"};

map<char,char> memo;

void oku(){

 go(i,23)
  go(j,sz(s1[i]))
    memo[s1[i][j]]=s2[i][j];

 memo['e']='o';
 memo['q']='z';
 memo['z']='q';

 int n;
 cin>>n;
 string s;
 getline(cin,s);

 //set<char> mset;

 //tr(memo,it)
 //cout<<it->first<<" "<<it->second<<endl;

 


 go(i,n){

 printf("Case #%d: ",i+1);
 getline(cin,s);
   go(j,sz(s))
    if(s[j]==' ')  cout<<s[j]; else
    cout<<memo[s[j]];


 cout<<endl;
 }


}

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

oku();

return 0;

}