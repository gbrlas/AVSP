#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int n;
string str[10];
int fie[11][11];

int C(){
	int cnt=0;
	for(int i=0;i<4;i++){
		cnt=0;
		for(int j=0;j<4;j++){
			if(fie[j][i]==0 || fie[j][i]==2)cnt++;
			else cnt=0;
			if(cnt==4)return 0;
		}
	}
	for(int i=0;i<4;i++){
		cnt=0;
		for(int j=0;j<4;j++){
			if(fie[i][j]==0 || fie[i][j]==2)cnt++;
			else cnt=0;
			if(cnt==4)return 0;
		}
	}
	cnt=0;
	for(int j=0;j<4;j++){
		if(fie[j][j]==0 || fie[j][j]==2)cnt++;
		else cnt=0;
		if(cnt==4)return 0;
	}
	
	for(int j=0;j<4;j++){
		if(fie[j][3-j]==0 || fie[j][3-j]==2)cnt++;
		else cnt=0;
		if(cnt==4)return 0;
	}
	
	for(int i=0;i<4;i++){
		cnt=0;
		for(int j=0;j<4;j++){
			if(fie[j][i]==1 || fie[j][i]==2)cnt++;
			else cnt=0;
			if(cnt==4)return 1;
		}
	}
	for(int i=0;i<4;i++){
		cnt=0;
		for(int j=0;j<4;j++){
			if(fie[i][j]==1 || fie[i][j]==2)cnt++;
			else cnt=0;
			if(cnt==4)return 1;
		}
	}
	cnt=0;
	for(int j=0;j<4;j++){
		if(fie[j][j]==1 || fie[j][j]==2)cnt++;
		else cnt=0;
		if(cnt==4)return 1;
	}
	for(int j=0;j<4;j++){
		if(fie[j][3-j]==1 || fie[j][3-j]==2)cnt++;
		else cnt=0;
		if(cnt==4)return 1;
	}
	
	
	return -1;
}

int main(void){
	scanf("%d",&n);
	for(int inp=1;inp<=n;inp++){
		bool f=true;
		for(int j=0;j<4;j++)cin >> str[j];
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(str[j][k]=='O')fie[j][k]=0;
				if(str[j][k]=='X')fie[j][k]=1;
				if(str[j][k]=='T')fie[j][k]=2;
				if(str[j][k]=='.')fie[j][k]=-1,f=false;
			}
		}
		int k=C();
		if(k==0)printf("Case #%d: O won",inp);
		if(k==1)printf("Case #%d: X won",inp);
		if(k==-1){
			if(f)printf("Case #%d: Draw",inp);
			else printf("Case #%d: Game has not completed",inp);
		}
		printf("\n");
	}
	return 0;
}