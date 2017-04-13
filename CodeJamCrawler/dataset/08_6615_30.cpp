#include<stdio.h>
#include<string.h>
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int n,s,q,i,j,rr,tt=0,count,flag[102];
	char name[102][102],query[1002][102];
	scanf("%d",&n);
	while(n--){
		scanf("%d",&s);
		for(i=0;i<s;++i)
		  scanf(" %[^\n]",name[i]);
		scanf("%d",&q);
		for(i=0;i<q;++i)
		  scanf(" %[^\n]",query[i]);
		rr=0;count=0;
		memset(flag,0,sizeof(flag));
		for(j=0;j<q;++j)
		  for(i=0;i<s;++i)
			 if(strcmp(query[j],name[i])==0){
				if(flag[i]==0){ 
				   count++;
				   flag[i]=1;
				  if(count==s){
				     rr++;
				     count=1;
				     memset(flag,0,sizeof(flag));
				     flag[i]=1;
			      }
			   }
			  break;
			}
	   printf("Case #%d: %d\n",++tt,rr);
   }
   return 0;
}
			 
		  
		   
	
		
