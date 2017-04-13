#include<stdio.h>
main()
{
 double  c,f,x,pt,nt,p,pw,nw;
 int   i,t,nf=0;
  scanf("%d",&t);
 for(i=0;i<t;i++)
 { 
      scanf("%lf %lf %lf",&c,&f,&x);
    p=2;
	while(1)
	{
		if(nf==0)
		{
			pw=0;
			pt=x/p;
			nw=c/p;
		}
	    nt=nw+x/(p+f);
	   p=p+f;
	    nw=nw+c/(p);
	    if(pt<=nt)
		break;
		pt=nt;
		nf++;
    }
    nf=0;
 
    printf("case #%d: %.7f\n",i+1,pt);
   
    } 
 }