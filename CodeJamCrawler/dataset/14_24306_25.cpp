#include<cstdio>
#include<cstdlib>

#define PP 1000000007


int main()
{
    int T, n;
    freopen("cj1.in", "r", stdin);
    freopen("cj1.out", "w", stdout);
    
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
	int A[4][4];
	int B[4][4];
	int a, b;
	scanf("%d",&a);
	for(int i=0;i<4; i++)
		for(int j=0;j<4; j++)
			scanf("%d", &A[i][j]);
	scanf("%d",&b);
	for(int i=0;i<4; i++)
		for(int j=0;j<4; j++)
			scanf("%d", &B[i][j]);
	int ans = -1;
	a--;b--;
	for(int i=0;i<4; i++)
		for(int j=0; j<4; j++)
			if(A[a][i] == B[b][j]) {
				if(ans == -1) ans = A[a][i];
				else if(ans == -2) break;
				else ans = -2;
			}
	if (ans == -1) 
        	printf("Case #%d: Volunteer cheated!\n", t);
	else if (ans == -2) 
        	printf("Case #%d: Bad magician!\n", t);
	else
        	printf("Case #%d: %d\n", t, ans);

    }
    return 0;
}
