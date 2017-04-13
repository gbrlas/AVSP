#include<stdio.h>



int main(){
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	int ii,nn;
	int n,m;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%d %d",&n,&m);
		printf("%s\n",(m%(1<<n)==((1<<n)-1))?"ON":"OFF");
	}
	return 0;
}