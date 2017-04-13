#include<iostream>
#include<algorithm>

using namespace std;

int arr[150];
int val[150] = {0};

int main()
{

	int test;
	scanf("%d",&test);
	for(int t = 1; t <= test; t++)
	{

		int A,N;
		int cnt = 0;

		scanf("%d %d",&A, &N);


		for(int i = 0; i < N;i++)
			scanf("%d",&arr[i]);

		sort(arr,arr+N);

		int ans = (int)1e9; int mx = -1;
		for(int i = 0; i < N;i++)
		{
				if(arr[i] < A) A += arr[i];
				else
				{
					int t_cnt = 0;
					while(A  > 1 && A <= arr[i])
					{
						A += A-1;
						t_cnt++;
					}
					
					if(A > arr[i])
					{

						A += arr[i];

						if((N-i) < t_cnt)
						{
							cnt = cnt + N - i;
							break;
						}
						else
							cnt += t_cnt;
					}
					else
					{
						cnt = cnt + N-i; 
						break;
					}
					
				}

				val[i] = (cnt + N - i -1);
				mx = i;

		}	

		for(int i = 0; i <= mx;i++)
			ans = min(ans,val[i]);

		if(mx < N-1)ans = min(ans, cnt);
		
		ans = min(N,ans);
	
		

		printf("Case #%d: %d\n",t,ans);

	}


	return 0;
}