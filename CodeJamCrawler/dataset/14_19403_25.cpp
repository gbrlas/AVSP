#include<stdio.h>
#include<conio.h>



int main()
{
	double c,f,x,t,r,temp1,temp2,cookies,time;
	int i,j;
	int testcase=1;
	FILE *in_ptr,*out_ptr;
	
	in_ptr=fopen("in1.txt","r+");
	
	out_ptr=fopen("out1.txt","w+");
	fscanf(in_ptr,"%lf",&t);

	while(t>0)
	{

        fscanf(in_ptr,"%lf",&c);
        fscanf(in_ptr,"%lf",&f);
        fscanf(in_ptr,"%lf",&x);
		time=0;
		temp1=0;
		temp2=0;
		r=2;
		
    	while(1)
		{
			temp1=x/r;
			temp2=c/r + x/(r+f);
		
			if(temp1>temp2)
			{
				time+=c/r;
				r=r+f;
        	}
			else
			{
				time+=x/r;
				break;
			}



	}


		fprintf(out_ptr,"Case #%d: %.7lf\n",testcase,time );
		t--;
		testcase++;
	}
	fclose(in_ptr);
	fclose(out_ptr);
}
