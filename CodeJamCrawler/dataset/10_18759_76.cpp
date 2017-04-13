#include<stdio.h>
main(int argc, char**argv)
{
	FILE *fin;
	FILE *fout;
	long a[]={2,4,8,16,32,64,128,256,512,
	1024,2048,4096,8192,16384,32768,65536,
	131072,262144,524288,1048576,2097152,
	4194304,8388608,16777216,33554432,67108864,
	134217728,268435456,536870912,1073741824,2147483648};
	fin=fopen(argv[1],"r");
	fout=fopen(argv[2],"w");
	int t;
	fscanf(fin,"%d",&t);
	int tt;
	int n;
	long k;
	for(tt=0;tt<t;tt++)
	{
		fscanf(fin,"%d %ld",&n,&k);
		int i;
		if((k+1)%a[n-1]==0)
		{
			fprintf(fout,"Case #%d: ON\n", tt+1);
		}
		else
		{
			fprintf(fout,"Case #%d: OFF\n", tt+1);
		}
	}
	fclose(fin);
	fclose(fout);
}
