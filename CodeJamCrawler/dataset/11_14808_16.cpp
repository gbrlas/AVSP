#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <ctime>
#include <complex>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define sqr(a) ((a)*(a))

using namespace std;

typedef long long LL;
typedef pair<int,int> PAIR;

const int maxn=103;
const int maxm=103;
const int inf=2000000001;

int t,n,m;
string alpha[maxn],order[maxm];
bool f[maxn];

string work1(string order){
	int i,j,k,x,ret=0,cost,ct,ans=0;
	bool ay[maxn];
	char ch;
	bool flag;
	for1(i,1,n){
		cost=0;
		ct=n;
		memset(f,0,sizeof(f));
		memset(ay,0,sizeof(ay));
		for1(j,1,n)	
			if (alpha[j].length()!=alpha[i].length()){
				f[j]=true;
				ct--;
			}
		for1(j,1,26){
			ch=order[j-1];
			flag=false;
			for1(k,1,n){
				if (!f[k] && alpha[k].find(ch)!=-1){
					flag=true;
					break;
				}
			}
			if (flag){
				if (alpha[i].find(ch)==-1){
					cost++;
					for1(k,1,n)
						if (k!=i && !f[k] && alpha[k].find(ch)!=-1){
							f[k]=true;
							ct--;
						}
				}else{
					for1(k,1,alpha[i].length())
						if (alpha[i][k-1]==ch)ay[k]=true;
					flag=true;
					for1(k,1,alpha[i].length())
						if (!ay[k]){
							flag=false;
							break;
						}
					if (flag)break;
					for1(k,1,n){
						if (!f[k] && k!=i){
							for1(x,1,alpha[i].length())
								if ((ay[x] && alpha[i][x-1]!=alpha[k][x-1])||(!ay[x] && ch==alpha[k][x-1])){
									f[k]=true;
									ct--;
									break;
								}
						}
					}
				}
			}else{
				continue;
			}
			if (ct<=1)break;
		}
		//cout<<cost<<' '<<i<<endl;
		if (ret==0 || cost>ans){
			ans=cost;
			ret=i;
		}
	}
	return alpha[ret];
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i,j,k;
	char ch;
	string s;
	for1(i,1,t){
		cin>>n>>m;
		//cout<<n<<' '<<m<<endl;
		getchar();
		for1(j,1,n){
			alpha[j]="";
			while ((ch=getchar())!='\n' && ch!=-1)alpha[j]+=ch;
			//cout<<alpha[j].data()<<endl;
		}
		for1(j,1,m){
			order[j]="";
			for1(k,1,26){
				ch=getchar();
				order[j]+=ch;
			}
			getchar();
			//cout<<order[j].data()<<endl;
		}
		printf("Case #%d:",i);
		for1(j,1,m){
			//cout<<order[j].data()<<endl;
			s=work1(order[j]);
			cout<<' '<<s.data();
		}
		puts("");
	}
    return 0;
}
