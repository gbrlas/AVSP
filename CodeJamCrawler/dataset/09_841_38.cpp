#include <iostream>
#include <string>
using namespace std;

bool flag[36];
int cc[36];
bool has[36];
int base;

int main() {
	freopen("D:\\A-small-attempt0.in", "r",stdin);
	freopen("D:\\A-small-attempt0.out","w",stdout);
	int t;
	string line;
	cin>>t;
	int ca=0;
	while(t--) {
		cin>>line;
		ca++;
		cout<<"Case #"<<ca<<": ";
		memset(flag,false,sizeof(flag));
		memset(cc,-1,sizeof(cc));
		memset(has,false,sizeof(has));
		for(int i=0;i<line.size();i++) {
			int id=line[i];
			if(id>='a'&&id<='z') {
				id=id-'a';
			}else{
				id='z'-'a'+1+id-'0';
			}
			flag[id]=true;
		}
		base=0;
		for(int i=0;i<36;i++) if(flag[i]) base++;
		if(base<2) base=2;
		long long rrr = 0;
		for(int i=0;i<line.size();i++) {
			int id=line[i];
			if(id>='a'&&id<='z') {
				id=id-'a';
			}else{
				id='z'-'a'+1+id-'0';
			}
			if(cc[id]!=-1) {
				rrr=rrr*base+cc[id];
			}else{
				if(i==0) {
					cc[id]=1;
					has[1]=true;
				}else{
					for(int j=0;j<base;j++) if(!has[j]) {
						cc[id]=j;
						has[j]=true;
						break;
					}
				}
				rrr=rrr*base+cc[id];
			}
		}
		cout<<rrr<<endl;
	}
	return 0;
}
