#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <set>


#define MAX 10000
#define CAS 15
using namespace std;

int main(int argc,char*argv[]){
	int n,m;
	int t;
	__int64 result;
	int vettLeft[MAX];
	int vettRight[MAX];
	int vettCost[MAX];
	FILE*fin,*fout;
	fin=fopen("input.in","r");
	fout=fopen("output.out","w");
	fscanf(fin,"%d",&t);
	for(unsigned i=0;i<t;++i){
		result=0;
		fscanf(fin,"%d",&n);
		memset(vettCost,0,sizeof(int)*n);
		for(unsigned j=0;j<n;++j){
			fscanf(fin,"%d%d",&vettLeft[j],&vettRight[j]);	
		}
		for(unsigned j=0;j<n; ++j){
			for(unsigned k=0;k<n;++k){
				if(k==j) continue;
				if((vettLeft[k]>vettLeft[j])&&(vettRight[k]<vettRight[j]))
					vettCost[j]++;
			}
			for(unsigned k=0;k<n;++k){
				if(vettCost[j]==0) break;
				if((vettLeft[k]<vettLeft[j])&&(vettRight[k]>vettRight[j]))
					vettCost[j]--;
			}
			result+=vettCost[j];
		}
		fprintf(fout,"Case #%d: %I64d\n",i+1,result);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
