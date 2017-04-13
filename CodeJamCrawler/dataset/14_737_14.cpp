#include <stdio.h>
#include <string.h>

int main()
{
	int ex[17];
	FILE* inp = fopen("A.txt","r"), *outp = fopen("out.txt","w");
	int t; fscanf(inp,"%i",&t);
	int i = 1;
	for(;i<=t;++i)
	{
		memset(ex,0,17*sizeof(int));
		int r; fscanf(inp,"%i",&r);
		int from = ((r-1)<<2), to1 = from + 4;
		int j = 0,v;
		for(;j<from;++j) fscanf(inp,"%i",&v);
		for(;j<to1;++j){ fscanf(inp,"%i",&v); ex[v]=1; }
		for(;j<16;++j)   fscanf(inp,"%i",&v);
		fscanf(inp,"%i",&r);
		from = ((r-1)<<2); to1 = from + 4;
		j = 0;
		int res = 0;
		for(;j<from;++j) fscanf(inp,"%i",&v);
		for(;j<to1;++j){ fscanf(inp,"%i",&v); if(ex[v]>0){ if(res > 0) res = -1; else if(res == 0) res = v; } }
		for(;j<16;++j)   fscanf(inp,"%i",&v);
		if(res > 0) fprintf(outp,"Case #%i: %i\n",i,res);
		else if(res == 0) fprintf(outp,"Case #%i: Volunteer cheated!\n",i);
		else fprintf(outp,"Case #%i: Bad magician!\n",i);
	}
	return 0;
}