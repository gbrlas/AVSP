#include<iostream>
#include<string>

using namespace std;

int N;
int max1(char *p,int i){
	int j;
	int max1;
	max1 = -1;
	for(j=0;j<N;j++)
		if(p[j]=='1')
			max1 = j;

	if(max1<=i)
		return 1;
	else
		return 0;
}
int main(){
	int i,j,cs,ii,jj,CSN,ans;
	char s[50][50],t[50];
	bool ok;

	freopen("out.out","w",stdout);

	scanf("%d\n",&CSN);
	for(cs=1;cs<=CSN;cs++){
		printf("Case #%d: ",cs);
		scanf("%d",&N);

		ans = 0;
		for(i=0;i<N;i++){
			scanf("%s",s[i]);
		}

		for(i=0;i<N;i++){

			for(j=i;j<N;j++){
				if(max1(s[j],i)){
					break;
				}
			}

			if(j==N)
				continue;

			memcpy(t,s[j],sizeof(s[j]));

			for(ii=j;ii>i;ii--){
				memcpy(s[ii],s[ii-1],sizeof(s[ii-1]));
				ans++;
			}
			memcpy(s[i],t,sizeof(t));
		}

		cout<<ans<<endl;

	}

}