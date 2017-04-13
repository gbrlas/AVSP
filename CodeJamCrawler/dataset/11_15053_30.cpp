#include <stdio.h>

int main()
 {
	int T,i,N,j,k,ba[101],oa[101],bs=0,os=0,zo,bp=1,op=1,time=0,butp=0,bi,oi,sti,brank[101],orank[101],mti;
	char c,str[3];
	scanf("%d",&T);
	if(T<1 || T>100)
		return 1;
	for(i=0;i<T;i++)
	 {
		time=0;bs=0;os=0;bp=1;op=1;butp=0;
		scanf("%d",&N);
		if(N<1 || N>100)
			return 1;
		for(k=0;k<N;k++)
		 {
			scanf("%s",str);
			c=str[0];
			if(c=='O' || c=='o')
			 {
				scanf("%d",&oa[os++]);
				if(oa[os-1]<1 || oa[os-1]>100)
					return 1;
				orank[os-1]=k;
			 }
			else if(c=='B' || c=='b')
			 {
				scanf("%d",&ba[bs++]);
				if(ba[bs-1]<1 || ba[bs-1]>100)
					return 1;
				brank[bs-1]=k;
			 }
			else
				return 1;
		 }
		bi=0;oi=0;sti=0,mti=0;zo=0;
		while(butp<N)
		 {
				mti=0;sti=0;zo=0;
				if(oi<os && bi<bs)
				 {
					zo=1;
					if(orank[oi] < brank[bi])
					 {
						if(op==oa[oi])
						 {
							butp++;
							oi++;
							sti=1;
						 }
					 }
					 if(!sti && op<oa[oi])
						op++;
					 if(!sti && op>oa[oi])
						op--;
					if(!sti)
					 {
						if(brank[bi] < orank[oi])
						 {
							if(bp==ba[bi])
							 {
								butp++;
								bi++;
								mti=1;
							 }
						 }
						if(!mti && bp<ba[bi])
							bp++;
						if(!mti && bp>ba[bi])
							bp--;
					 }
					else
					 {
						sti=0;
						if(bp<ba[bi])
							bp++;
						else if(bp>ba[bi])
							bp--;
					 }
				  }
				 if(!zo && oi<os)
				  {
					if(op==oa[oi])
					 {
						butp++;
						oi++;
						sti=1;
					 }
					 if(!sti && op<oa[oi])
						op++;
					 if(!sti && op>oa[oi])
						op--;
				   }
				  if(!zo && bi<bs)
				  {
					if(bp==ba[bi])
					 {
						butp++;
						bi++;
						mti=1;
					 }
					 if(!mti && bp<ba[bi])
						bp++;
					 if(!mti && bp>ba[bi])
						bp--;
				   }

			time++;
		 }
		printf("Case #%d: %d\n",i+1,time);
	 }
	return 0;
 }
