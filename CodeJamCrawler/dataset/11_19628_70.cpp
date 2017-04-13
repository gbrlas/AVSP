#include <stdio.h>
#include <stdlib.h>

int C, TC=1, N,a[205], i,po, pb, s, idletimeforB, idletimeforO, timerequired;
char c;
int main ()
{
    for (scanf ("%d", &C); TC <= C; TC++)
    {
		po = pb = 1;
		s=0;
		scanf("%d", &N);
		int imax=2*N;
		for(i=0;i<imax;i+=2)
		{
			scanf(" %c", &a[i]);
			scanf(" %d", &a[i+1]);
		}
		idletimeforO = idletimeforB = 0;
		for(i=0; i<imax; i+=2)
		{
			if(a[i]=='O')
			{
				timerequired = abs(a[i+1]-po);
				if(timerequired <= idletimeforO)
					timerequired = 0;
				else
					timerequired -= idletimeforO;
				idletimeforO = 0;
				idletimeforB += timerequired+1;
				po = a[i+1];
				s += timerequired+1;
			}
			else //'B'
			{
				timerequired = abs(a[i+1]-pb);
				if(timerequired <= idletimeforB)
					timerequired = 0;
				else
					timerequired -= idletimeforB;
				idletimeforB = 0;
				idletimeforO += timerequired+1;
				pb = a[i+1];
				s += timerequired+1;
			}

		}


		printf ("Case #%d: %d\n", TC,s);
    }

    return 0;
}
