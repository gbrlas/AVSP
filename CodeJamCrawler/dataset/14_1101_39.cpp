#include <stdio.h>

int main(void) {
	int t,i,o,count=0,f=0;
	int k1,k2,k3,l1,l2,l3;
	int a[4][4],b[4][4];
	scanf("%d",&t);
	int g=1;
	while(g<=t)
	{  count=0;
		scanf("%d",&i);i=i-1;
		for( k1=0;k1<4;k1++)
		{
			for( l1=0;l1<4;l1++)
			   scanf("%d",&a[k1][l1]);
	    }
		scanf("%d",&o);o=o-1;
		for(k2=0;k2<4;k2++)
		{
			for(l2=0;l2<4;l2++)
			   scanf("%d",&b[k2][l2]);
	    }
	    for(k3=0;k3<4;k3++)
	     {
	     	for(l3=0;l3<4;l3++)
	     	   {
	     	   	 if(a[i][k3]==b[o][l3])
	     	   	    {
	     	   	    	count=count+1;f=b[o][l3];
	     	   	    }
	     	   }
	     }
	if(count==1) printf("Case #%d: %d\n",g,f);
	else{
		  if(count==0) printf("Case #%d: Volunteer Cheated!\n",g);
		  else printf("Case #%d: Bad Magician!\n",g);
	    }
	    g++;
	    //printf("%d",f);
	}
	

	return 0;
}

