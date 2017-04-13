#include<iostream>
#include<string>
using namespace std;

int l,d,n;
string dict[5000];
string str;
char buffer[300];

bool canBuild(int index){
	int last = 0;
	bool ok;
	for(int i=0;i<dict[index].length();i++){
		if(str[last]!='('){
			if(str[last]!=dict[index][i])
			return false;
			else {last++;continue;}
		}
		else{   ok=false;
			last++;
			while(str[last]!=')'){
				if(str[last]==dict[index][i])
				ok = true;
				last++;
			}
			last++;
			if(!ok) return false;
		}
	}
	return true;
		
}

int main(){
 freopen("A-small.in","r",stdin);
 freopen("A-small.out","w",stdout);
scanf("%d%d%d",&l,&d,&n);

for(int i=0;i<d;i++){
	scanf("%s",buffer);
	dict[i] = buffer;
}
char *report = "Case #";
char ch = ':';
for(int i=1;i<=n;i++){
	scanf("%s",buffer);
	str = buffer;
	int ans = 0;
	for(int j=0;j<d;j++){
		if(canBuild(j))
		ans++;
	}
	printf("%s",report);
	printf("%d",i);
	printf("%c ",ch);
	printf("%d\n",ans);
}
return 0;
}