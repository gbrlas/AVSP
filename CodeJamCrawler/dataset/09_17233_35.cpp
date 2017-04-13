#include<stdio.h>
int max(int);
void change(int,int);
void sort1(int);

char s1[100];
int p;
int main()
{
	int bc,flag,i,j,k,q,te,lk;
	char s[100];
	freopen("a12.in","r",stdin);
   freopen("b12.txt","w",stdout);	
	scanf("%d",&te);
	for(lk=0;lk<te;lk++)
	{
	scanf("%s",s1);
	strcpy(s,s1);
    flag=1;
	p=strlen(s1);
	for(i=p-2;i>=0;i--)
	{
	 q=max(i);
	 	if(q!=-1) {
	                 flag =0;
					  change(i,q);
					   
					  sort1(i+1);
	                 
					 }
	    if(flag==0) break;    
		        
	}
	printf("Case #%d: ",lk+1);
	if(strcmp(s1,s)!=0) printf("%s",s1);
	else {
		bc=1;
		sort1(0);
		if(s1[0]=='0')
		{while(s1[bc]=='0')
		{bc++;}
		change(0,bc);}
		printf("%c0",s1[0]);
		for(i=1;s1[i]!='\0';i++)
		printf("%c",s1[i]);
	}
	printf("\n");
	}
}
int max(int a)
	{
		int m=-1,i;
		char q=s1[a];
		
		for(i=a+1;i<p;i++)
		 if(s1[i]>q) { q=s1[i]; m=i;  }
		
		for(i=a+1;i<p;i++)
		 if(s1[i]>s1[a] && s1[i]<q ) { q=s1[i]; m=i;   }
	    
		return m;
	}
	
	void sort1(int a)
	{
		int i,j;
		char t;
		  
		  for(i=a;s1[i]!='\0';i++)
	  for(j=i;s1[j]!='\0';j++)
	  {
	  	if(s1[j]<s1[i]){ t=s1[i]; s1[i]=s1[j]; s1[j]=t; }
	  		 
	  }
	   
	}
		 
	void change(int a,int b)
	{
		char x;
		x=s1[a];
		s1[a]=s1[b];
		s1[b]=x;
	}
