#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <sstream>
#include <set>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fors(n) for(size_t i = 0 ; i < (n) ;i++)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define scani(n) scanf("%d",&n)
#define scanii(n,m) scanf("%d%d",&n,&m)
#define printi(n) printf("%d\n",n)
#define rep(n) while(n--)
#define set0(n) memset(n,0,sizeof 0)

int convertString(string number){
	stringstream ss(number);
	int res = 0;
	ss >> res;
	return res;
}

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int main(){
	int t,n1,n2,cas=0;
	set<pii> s;
	freopen("in.txt","r",stdin);
	scani(t);
	rep(t){
		s.clear();
		int res =0;
		scanii(n1,n2);
		for (int i =n1 ; i <=n2 ; i++){
			string num2 = convertInt(n2);
			if(num2.length()<=1) break;
			forj(num2.length()){
				string n = convertInt(i);
				rotate(n.begin(),n.begin()+j,n.end());
				int curn=convertString(n);
				if(curn >= n1 && curn < n2 && curn < i)
					s.insert(mp(curn,i));
					//res++;
			}
		}
		printf("Case #%d: %ld\n",++cas,s.size());
	}
	return 0;
}