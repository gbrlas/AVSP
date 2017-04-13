#include<stdio.h>
int main(){
	int t,ca=1,i,j;
	char mp[10][10];
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++){
		for(i=0;i<4;i++)
			scanf("%s",mp[i]);
		bool flag=false;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mp[i][j]!='X' && mp[i][j]!='T')break;
			}
			if(j>=4){
				flag=true;
				break;
			}
			for(j=0;j<4;j++){
				if(mp[j][i]!='X' && mp[j][i]!='T')break;
			}
			if(j>=4){
				flag=true;
				break;
			}
		}
		for(i=0;i<4;i++){
			if(mp[i][i]!='X' && mp[i][i]!='T')break;
		}
		if(i>=4)flag=true;
		for(i=0;i<4;i++){
			if(mp[i][3-i]!='X' && mp[i][3-i]!='T')break;
		}
		if(i>=4)flag=true;
		if(flag){
			printf("Case #%d: X won\n",ca);
			continue;
		}

		//===============
		flag=false;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mp[i][j]!='O' && mp[i][j]!='T')break;
			}
			if(j>=4){
				flag=true;
				break;
			}
			for(j=0;j<4;j++){
				if(mp[j][i]!='O' && mp[j][i]!='T')break;
			}
			if(j>=4){
				flag=true;
				break;
			}
		}
		for(i=0;i<4;i++){
			if(mp[i][i]!='O' && mp[i][i]!='T')break;
		}
		if(i>=4)flag=true;
		for(i=0;i<4;i++){
			if(mp[i][3-i]!='O' && mp[i][3-i]!='T')break;
		}
		if(i>=4)flag=true;
		if(flag){
			printf("Case #%d: O won\n",ca);
			continue;
		}
		flag=true;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mp[i][j]=='.')flag=false;
			}
		}
		if(flag){
			printf("Case #%d: Draw\n",ca);
		}
		else{
			printf("Case #%d: Game has not completed\n",ca);
		}
	}
	return 0;
}
