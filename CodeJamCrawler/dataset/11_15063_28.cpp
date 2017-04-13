#include <stdio.h>
#include <string.h>

int main()
 {
	int t,i,j,k,flag=0,r,c;
	char str[22][22];
	scanf("%d",&t);
	if(t<0 || t>20)
		return 1;
	for(i=0;i<t;i++)
	 {
		flag=0;
		scanf("%d%d",&r,&c);
		if(r<1 || r>6)
			return 1;
		if(c<1 || c>6)
			return 1;
		for(j=0;j<r;j++)
		 {	
			scanf("%s",str[j]);
			if(strlen(str[j])!=c)
				return 1;
		 }
		for(j=0;j<r && !flag;j++)
		 {
			for(k=0;k<c && !flag;k++)
			 {
				if(str[j][k]=='#')
				 {
					if(str[j][k+1]=='#' && str[j+1][k]=='#' && str[j+1][k+1]=='#')
					 {
						str[j][k]='/';
						str[j][k+1]='\\';
						str[j+1][k]='\\';
						str[j+1][k+1]='/';
					 }
					else
					 {
						flag=1;
					 }
				 }
 			 }
		 }
		printf("Case #%d:",i+1);
		if(!flag)
		 {
			printf("\n");
			for(j=0;j<r;j++)
			 {	
				printf("%s\n",str[j]);
			 }
		 }
		else
			printf("\nImpossible\n");
  	 }
	return 0;
 }
