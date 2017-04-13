#include<stdio.h>
#include<string.h>
char set[100],str[100];
char comb[100][100];
char diss[100][100];
int d,c;
int dissolve(char ch)
{
	int i,j;
	for(i=0;set[i]!='\0';i++)
	  {
	  	for(j=0;j<d;j++)
	  	  if((set[i]==diss[j][0] && ch==diss[j][1]) || (set[i]==diss[j][1] && ch==diss[j][0])) { set[0]='\0'; return 1 ; }
	  }
	return 0;
}
int check(char ch)
{
	int i,j,x;
	x=strlen(set);
	if(x>0)
	  	for(j=0;j<c;j++)
	  	{
	  	if((set[x-1]==comb[j][0] && ch==comb[j][1]) || (set[x-1]==comb[j][1] && ch==comb[j][0])) { set[x-1]=comb[j][2]; set[x]='\0'; return 1;}
	  	}
	return 0;  	
}
int main()
{
	int x,i,n,t,j;
	freopen("1.in","r",stdin);
	freopen("2.txt","w",stdout);
//	char str[100];
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
    	set[0]='\0';
     scanf("%d",&c);
     for(i=0;i<c;i++)
     scanf("%s",comb[i]);
     
     
     scanf("%d",&d);
     for(i=0;i<d;i++)
     scanf("%s",diss[i]);
     
     
     scanf("%d",&n);
     scanf("%s",str);
     
     for(i=0;str[i]!='\0';i++)
     {
     	x=strlen(set);
     if(!check(str[i]))
     	if(!dissolve(str[i])) {set[x]=str[i]; set[x+1]='\0';}
  //   printf("%s\n",set);
	 }
     printf("Case #%d: [",j);
     for(i=0;set[i]!='\0';i++)
      	if(i==0) printf("%c",set[i]);
      	else printf(", %c",set[i]);
 printf("]\n");
    }
}

