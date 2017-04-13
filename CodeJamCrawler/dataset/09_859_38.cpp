#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool flag[101];
vector<int> pl;

int p,q;
int n;

int getfs() {
	memset(flag,false,sizeof(flag));
	int tot=0;
	for(int i=0;i<q;i++) {
		int id=pl[i];
		for(int j=id-1;j>=1;j--) {
			if(flag[j]) break;
			tot++;
		}
		for(int j=id+1;j<=p;j++) {
			if(flag[j]) break;
			tot++;
		}
		flag[id]=true;
	}
	return tot;
}

int main() {
	freopen("E:\\C-small-attempt0.in","r",stdin);
	freopen("E:\\C-small-attempt0.out","w",stdout);
	cin>>n;
	int cac=0;
	while(n--) {
		cac++;
		cin>>p>>q;
		int a;
		pl.clear();
		for(int i=0;i<q;i++) {
			cin>>a;
			pl.push_back(a);
		}
		sort(pl.begin(),pl.end());
		int r=1<<30;
		do{
			int gg=getfs();
			r=min(r,gg);
		}while(next_permutation(pl.begin(),pl.end()));
		cout<<"Case #"<<cac<<": "<<r<<endl;
	}
	return 0;
}

