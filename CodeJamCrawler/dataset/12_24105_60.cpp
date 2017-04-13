#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc<3)
		return 1;
	FILE *input = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");
	int numberOfCase;
	fscanf(input, "%d\n", &numberOfCase);
	for(int i = 0; i<numberOfCase; i++)
	{
		int N, S, p;
		fscanf(input, "%d %d %d ", &N, &S, &p);
		printf("%d %d %d ", N, S, p);
		
		int score;
		int superior = 0;
		for(int j = 0; j<N; j++)
		{
			fscanf(input, "%d ", &score);
			if(score/3>=p)
				superior++;
			else if(score/3 == p-1 && score%3>0)
				superior++;
			else if(score/3 == p-1 && score>2 && S>0)
			{
				S--;
				superior++;
			}
			else if(score/3 == p-2 && score%3>1 && score>1 && S>0)
			{
				S--;
				superior++;
			}
		}
		printf("%d %d\n", superior, S);
		fprintf(output, "Case #%d: %d\n", i+1, superior);
	 }
}
