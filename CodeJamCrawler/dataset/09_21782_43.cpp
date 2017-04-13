#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
char arr[10000] ;
#define mod (int)1e5
long long isvalid(int index ,int sr)
{
    static char search[] = "welcome to code jam" ;
	if(sr == strlen(search))
	   return 1  ;
	int l = strlen(arr);
	long long ans = 0 ;
	for(int i=index;i<l && sr < strlen(search);++i)
	{
		if(search[sr] == arr[i])
			ans = (ans + isvalid(i+1,sr+1)) % mod ;
	}
	return ans % mod ;
}
void print(FILE *fout,int s)
{
	if(s<=0) return ;
	while(s-- ) fprintf(fout,"0");
}
int main()
{
	FILE  * fin = fopen("C:/inp1.txt","r");
	FILE  *fout = fopen("C:/out1.txt","w");
	int nt;
	fscanf(fin,"%d",&nt);
	char ch;
	fscanf(fin,"%d",&ch);
	int cases = 0;
	while(nt--)
	{
		fgets(arr,9999,fin);
		long long res = isvalid(0,0);
		char j[100]; sprintf(j,"%lld",res);
        fprintf(fout,"Case #%d: ",++cases);
		print(fout,4-strlen(j));
		fprintf(fout,"%lld\n",res);
	}
}
