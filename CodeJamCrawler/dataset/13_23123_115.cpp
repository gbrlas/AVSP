#include<cstdio>

using namespace std;

int array[]={1,4,9,121,484};

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	scanf("%d",&T);
	int caseNo=0;
	while(T--)
	{
		caseNo++;
		int A,B,count=0;
		scanf("%d %d",&A,&B);
		for(int i=0;i<5;i++)
			if(array[i]>=A&&array[i]<=B) count++;
		printf("Case #%d: %d\n",caseNo,count);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
			