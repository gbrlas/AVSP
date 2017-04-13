#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[5][5];
int flag[20];
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		int a;
		cin>>a;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++){
				cin>>map[i][j];
			}
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=4;i++)
			flag[map[a][i]]++;
		cin>>a;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++){
				cin>>map[i][j];
			}
		for(int i=1;i<=4;i++)
			flag[map[a][i]]++;
		int ans=0;
		int tt;
		for(int i=1;i<=16;i++){
			if(flag[i]==2){
			   	ans++;
				tt=i;
			}
		}
		printf("Case #%d: ",++cnt);
		if(ans==1) cout<<tt<<endl;
		else if(ans>1) cout<<"Bad magician!"<<endl;
		else cout<<"Volunteer cheated!"<<endl;
	}
	return 0;
}
