#include <stdio.h>

int main()
 {
	int t,n,i,j,k,l,h,freq[101],dig,flag;
	scanf("%d",&t);
	if(t<1 || t>40)
		return 1;
	for(i=0;i<t;i++)
	 {
		scanf("%d %d %d",&n,&l,&h);
		if(n<1 || n>100)
			return 1;
		if(l<1 || l>10000)
			return 1;
		for(j=0;j<n;j++)
			scanf("%d",&freq[j]);
		for(dig=l;dig<=h;dig++)
		 {
			flag=0;
			for(j=0;j<n && (!flag);j++)
			 {
				if(dig%freq[j]!=0 && freq[j]%dig!=0)
					flag=1;
			 }
			if(!flag)
				break;
		 }
		if(!flag)
			printf("Case #%d: %d\n",i+1,dig);
		else
			printf("Case #%d: %s\n",i+1,"NO");
	 }
	return 0;
 }
