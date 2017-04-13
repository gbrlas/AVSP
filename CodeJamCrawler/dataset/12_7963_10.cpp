#include <cstdio>

int main()
{
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, a, b;
	int i;
	float p[4], q[4];
	float v1, v2, v3, v4, ans;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++)
	{
		scanf("%d %d", &a, &b);
		for(i=0; i<a; i++)
		{
			scanf("%f", &p[i]);
			q[i] = 1 - p[i];
		}
		
		if(a == 1)
		{
			v1 = b*(p[0]) + (2*b+1)*(q[0]);
			v2 = (b+2)*(p[0]) + (b+2)*(q[0]); //v3 == v2
			
			ans = v1<v2?v1:v2;
		}
		else if(a == 2)
		{
			v1 = (b-1) * (p[0]*p[1]) + (2*b) * (p[0]*q[1]) + (2*b) * (q[0]*p[1]) + (2*b) * (q[0]*q[1]);
			v2 = (b+1) * (p[0]*p[1]) + (b+1) * (p[0]*q[1]) + (2*b+2) * (q[0]*p[1]) + (2*b+2) * (q[0]*q[1]);
			v3 = (b+3) * (p[0]*p[1]) + (b+3) * (p[0]*q[1]) + (b+3) * (q[0]*p[1]) + (b+3) * (q[0]*q[1]);
			v4 = (b+2) * (p[0]*p[1]) + (b+2) * (p[0]*q[1]) + (b+2) * (q[0]*p[1]) + (b+2) * (q[0]*q[1]);	// v4 < v3
			
			ans = v1<v2?v1:v2;
			ans = ans<v3?ans:v3;
			ans = ans<v4?ans:v4;
		}
		else
		{
			v1 = (b-2) * (p[0]*p[1]*p[2]) + (2*b-1) * (p[0]*p[1]*q[2] + p[0]*q[1]*p[2] + p[0]*q[1]*q[2] + q[0]*p[1]*p[2] + q[0]*p[1]*q[2] + q[0]*q[1]*p[2] + q[0]*q[1]*q[2]);
			v2 = b * (p[0]*p[1]*p[2] + p[0]*p[1]*q[2]) + (2*b+1)*(p[0]*q[1]*p[2] + p[0]*q[1]*q[2] + q[0]*p[1]*p[2] + q[0]*p[1]*q[2] + q[0]*q[1]*p[2] + q[0]*q[1]*q[2]);
			v3 = (b+2) * (p[0]*p[1]*p[2] + p[0]*p[1]*q[2] + p[0]*q[1]*p[2] + p[0]*q[1]*q[2]) + (2*b+3)*(q[0]*p[1]*p[2] + q[0]*p[1]*q[2] + q[0]*q[1]*p[2] + q[0]*q[1]*q[2]);
			v4 = (b+2) * (p[0]*p[1]*p[2] + p[0]*p[1]*q[2] + p[0]*q[1]*p[2] + p[0]*q[1]*q[2] + q[0]*p[1]*p[2] + q[0]*p[1]*q[2] + q[0]*q[1]*p[2] + q[0]*q[1]*q[2]);
			
			ans = v1<v2?v1:v2;
			ans = ans<v3?ans:v3;
			ans = ans<v4?ans:v4;
		}
		
		printf("Case #%d: %f\n", tc, ans);
	}
	
	return 0;
}
		