#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* inp;
	FILE* out;
	inp = fopen("inp.txt","r");
	out = fopen("out.txt","w");
	int n;
	int xsum,sum;
	int T,x,min,r;
       if(inp!=NULL&&out!=NULL)
{
	
	fscanf(inp,"%d",&T);
	r=T;
	while(r)
	{
		fscanf (inp,"%d",&n);
		fscanf (inp,"%d",&x);
		xsum=x;
		min=x;
		sum=x;
		while(n-1)
		{
			fscanf (inp,"%d",&x);
			xsum=xsum^x;
			n--;
			if(x<min)
				min=x;
			sum+=x;
		}
		fprintf(out,"Case #");
		fprintf(out,"%d",T-r+1);
		fprintf(out,": ");
		if(!xsum)
		fprintf(out,"%d\n",sum-min);
		else 
		fprintf(out,"NO\n");	
		r--;
	}
	fclose(inp);
	fclose(out);

}
}
