#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 1
#ifdef DEBUG
#endif

#define pie 3.14159
int T;
unsigned _int64 r,t ,A,B,C;


int answer;


unsigned _int64 total;








void init()
{

}

void preprocess()
{

	total = 0;
}

void solution(){
	

	freopen("D:\\compete\\sample\\jam_r1\\in_small.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	
	int i;
	for(i=0; i<T; i++)
	{
		init();

		scanf("%d %d", &r, &t);
		
		// TODO
		preprocess();
		
		
		for(int n=0; ; n++)
		{
			
			total += ((r+1+2*n)*(r+1+2*n) - (r+2*n)*(r+2*n));
			if(total > t)
			{
				answer = n;
				break;;
			}
			else if(total == t)
			{
				answer = n+1;
				break;
			}
		}
		printf("Case #%d: %d\n", i+1, answer);
	}
}


void main()
{
	solution();
}