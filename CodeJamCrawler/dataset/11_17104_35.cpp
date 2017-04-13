#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,val[1000],prev_o,prev_b,t,k,time,time_o,time_b,n,x;
	char ch,colo[1000];
	freopen("3.in","r",stdin);
	freopen("4.txt","w",stdout);
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		time=time_o=time_b=0;
		prev_o=prev_b=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  scanf("%c%c%d",&ch,&colo[i],&val[i]);
//	for(i=0;i<n;i++)
//	printf("%c %d\n",colo[i],val[i]);
	  
	for(j=0;j<n;j++)
	{
	   if(colo[j]=='O') { 	x=abs(prev_o-val[j]);
	   						if(time_o + x <= time) {time++; time_o=time;} 
	   						else {time=time_o+x+1; time_o=time;}
	   					prev_o=val[j];
						   }
	 
	   if(colo[j]=='B') { 	x=abs(prev_b-val[j]);
	   						if(time_b + x <= time) {time++; time_b=time;} 
	   						else {time=time_b+x+1; time_b=time;}
	   					prev_b=val[j];
						   }
	}
	printf("Case #%d: %d\n",k,time);
	}
}
	   					  					
