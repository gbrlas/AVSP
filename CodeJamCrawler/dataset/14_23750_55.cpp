#include<cstdio>
#include<vector>
using namespace std;
int A[5][5],B[5][5];
vector<int>V;
int main()
{
	int it,i,j,T,a,b;
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("Magic.out","w",stdout);
	scanf("%d",&T);
	for(it=1; it<=T; it++)
	{
		scanf("%d",&a);
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)  scanf("%d",&A[i][j]);
		}
		scanf("%d",&b);
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)  scanf("%d",&B[i][j]);
		}
		V.clear();
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)
			{
				if(A[a][i]==B[b][j])
				{
					V.push_back(A[a][i]);
					break;
				}
			}
		}
		printf("Case #%d: ",it);
		if(V.size()==1)  printf("%d\n",V[0]);
		else if(V.size()==0) printf("Volunteer cheated!\n");
		else if(V.size()>1)  printf("Bad magician!\n");
	}
	return 0;
}

