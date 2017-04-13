#include<stdio.h>
int main()
{ int t,n,i,j,k;
	char s[105],te[105],a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	scanf("%d\n",&t);
	for(i=0;i<t;i++)
	{	gets(s);
			for(j=0;j<strlen(s);j++)
				if(s[j]==' ')
      te[j]=' ';
				 else
				 te[j]=a[s[j]-'a'];
				te[j]='\0';
 		printf("Case #%d: %s\n",i+1,te);	
	}		
	return 0;
}	
				
