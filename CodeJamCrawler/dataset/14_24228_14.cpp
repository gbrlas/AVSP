
#include<stdio.h>

void main()
{
	int testcases;
	int i,j,k,p,q;
	int count,counter;
	double c,f,x,cursecs,minsecs,cookiesecs;
	double output[100]={0.0};
	char newline,space;

	scanf("%d",&testcases);
	if (testcases < 1 || testcases > 100)
	{	
		printf("InputError: Total testcases range [1 to  100]\n");
		return;
	}
	scanf("%c",&newline);
	if (newline!='\n')
	{	
		printf("InputError: Expected newline\n");
		return;
	}
	
	for(i=0;i<testcases;i++)
	{
		scanf("%lf",&c);
		if (c < 1.0 || c > 500.0)
		{	
			printf("InputError: cookies to buy farm range [1 to 500]\n");
			return;
		}
		
		scanf("%c",&space);
		if (space!=' ')
		{	
			printf("InputError: Expected space between inputs\n");
			return;
		}
		scanf("%lf",&f);
		if (f < 1.0 || f > 4.0)
		{	
			printf("InputError: Extra cookies range [1 to  4]\n");
			return;
		}
		
		scanf("%c",&space);
		if (space!=' ')
		{	
			printf("InputError: Expected space between inputs\n");
			return;
		}
		scanf("%lf",&x);
		if (x < 1.0 || x > 2000.0)
		{	
			printf("InputError: final cookies range [1 to 2000]\n");
			return;
		}
		
		scanf("%c",&newline);
		if (newline!='\n')
		{	
			printf("InputError: Expected newline between testcases input\n");
			return;
		}
		
		/* calculate min secs*/
		cursecs=60000.0;
		minsecs=70000.0;
		counter=0;
		double multiplier;
		while(cookiesecs < minsecs)
		{
			if(cursecs < minsecs)
			minsecs = cursecs;
			cursecs = 0;
			cookiesecs=0;	
			counter++;
			count=counter;
			while(count)
			{
				if(cursecs == 0) {
					multiplier = count;
					cursecs = x/(2.0+((multiplier-1.0)*f));
				} else {
					multiplier = count;
					cursecs = cursecs + c/(2.0+((multiplier-1.0)*f));
					cookiesecs = cookiesecs + c/(2.0+((multiplier-1.0)*f));
				}

				count--;
			}
		}
		output[i]=minsecs;
	}

	for(i=0;i<testcases;i++)
	{
		printf("Case #%d: %2.7f\n",i+1,output[i]);
	}
}
