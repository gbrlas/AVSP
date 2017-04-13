#include <iostream>
#include <set>
using namespace std;

int n;
int m;

struct tnode {
	int x,y;
	tnode(int xx,int yy):x(xx),y(yy) {}
};
bool operator<(const tnode& t1,const tnode& t2) {
	if(t1.x!=t2.x) return t1.x<t2.x;
	return t1.y<t2.y;
}
set<tnode> pp[100];

int main() {
	//freopen("in.txt","r",stdin);
	int c;
	cin>>c;
	for(int o=1;o<=c;o++) {
		for(int i=0;i<100;i++) pp[i].clear();
		cin>>n;
		cin>>m;
		for(int i=0;i<m;i++) {
			int t;
			cin>>t;
			for(int j=0;j<t;j++) {
				int x,y;
				cin>>x>>y;
				pp[i].insert(tnode(x,y));
			}
		}
		int min=1<<30;
		int bestm=0;
		for(int mask=0;mask<(1<<n);mask++) {
			bool ok=true;
			int h=0;

			for(int i=0;i<n;i++) {
				int b=mask&(1<<i);
				int bb;
				if(b>0) bb=1; else bb=0;
				h+=bb;
			}

			for(int i=0;i<m;i++) {
				bool ok2=false;
				for(int j=0;j<n;j++) {
					int b=mask&(1<<j);
					if(pp[i].find(tnode(j+1,b>0?1:0))!=pp[i].end()) {
						ok2=true;
						break;
					}
				}
				if(ok2==false) {
					ok=false;
					break;
				}
			}
			if(ok) {
				if(min>h) {
					min=h;
					bestm=mask;
				}
			}
		}
		cout<<"Case #"<<o<<":";
		if(min==1<<30) {
			cout<<" IMPOSSIBLE"<<endl;
		}else{
			for(int i=0;i<n;i++)
				cout<<' '<<((bestm&1<<i)>0?1:0);
			cout<<endl;
			//cout<<min<<' '<<bestm<<endl;
		}
	}
	return 0;
}	