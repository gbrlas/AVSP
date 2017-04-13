#include<stdio.h>
#include<stdlib.h>
int testforint(float val)
{
    int flr;
    float diff;
    flr=val;
    diff=val-(float)flr;
    if(diff==0.00)
    return 1;
    else 
    return 0;
}
int main()
{
	FILE* inp;
	FILE* out;
	inp = fopen("inp.txt","r");
	out = fopen("out.txt","w");
	int N,D,G;
	int T,r;
	int L,i,w;
       if(inp!=NULL&&out!=NULL)
{
	
	fscanf(inp,"%d",&T);
	r=T;
	while(r)
	{
            L=0;
            
		fscanf (inp,"%d",&N);
		fscanf (inp,"%d",&D);
	    fscanf (inp,"%d",&G);
	    if((G==0&&D!=0)||(G==100&&D!=100))
               L=0;
	    else 
	         {
                for(i=0;i<N;i++)
                 {
                                 printf("%d ",(N-i)*D);
                                 if(((N-i)*D)%100==0)
                                 L=1;
                                 
                 }  
             }
             printf("\n");
		fprintf(out,"Case #");
		fprintf(out,"%d",T-r+1);
		fprintf(out,": ");
		if(L)
		fprintf(out,"Possible\n");
		else 
		fprintf(out,"Broken\n");	
		r--;
		
	}
	fclose(inp);
	fclose(out);

}
scanf("%d",&N);
}
