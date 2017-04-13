#include<stdio.h>
#include<math.h>

int numofdigits(long num)
{
	int count=0;
	while(num){
      num=num/10;
      count++;
  }
  return count;
}

long powr(int num,int upto)
{   long i=1;
	while(upto-->0)
	{
		i = i*num;
	}	
	return i;
}

int rotate(long giv,long end)
{   long number =giv;
	int numofdigit = numofdigits(number);
	//printf("%d \n",numofdigit);
	long numberdiv = powr(10,numofdigit-1);
	//printf("%ld \n",numberdiv);
	int count=0;
	
    while(1==1)
    {
    	int q = number/10;
    	int r = number%10;
    	
    	number = q+r*numberdiv;
    	//printf("%ld ",number);
    	if(number==giv)break;
    	if(number<=end && number>giv) count++;
    }
    //printf("\n ");
    return count;
}

main()
{
	int total=0;
	int k=1;
	int i;
	char a[100];
	long start,end;
	FILE *in ;
    in= fopen("A-small-attempt0.in","r");
    FILE *out;
    out = fopen("A-small-attempt0.out","a+");
     fscanf(in,"%d",&i);
	 while(k<=i){
	 total=0;
        if(fscanf(in, "%ld %ld", &start,&end) != EOF){
	//fscanf(a,"%d %d",start,end);
		while(start<end)
		{
		total +=rotate(start,end);
		start++;
		}
		fprintf(out,"Case #%d: %d\n",k,total);
		}
       k++; 
    }
	
	//printf("%d\n",total);
}
