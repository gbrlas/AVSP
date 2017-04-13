#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("data.out","w",stdout);
	int T=0;
	int tcase=0;
	scanf("%d",&T);
	while (tcase++<T)
	{
		int N=0;
		int i=0;
		int olocation=1;
		int lastoTime=0;
		int blocation=1;
		int lastbTime=0;
		int time=0;
		scanf("%d ",&N);
		while (i<N)
		{
			int button=0;
			int x = getchar();
			if(x=='O'){
				scanf("%d ",&button);
				int actualTime = abs(button-olocation);
				int deltaTime = (time - lastoTime>=actualTime)?0:(lastoTime+actualTime-time);
				deltaTime++;
				time+=deltaTime;
				lastoTime=time;
				olocation = button;
			}
			else{
				scanf("%d ",&button);
				int actualTime = abs(button-blocation);
				int deltaTime = (time - lastbTime>=actualTime)?0:(lastbTime+actualTime-time);
				deltaTime++;
				time+=deltaTime;
				lastbTime=time;
				blocation = button;
			}
			i++;
		}
		printf("Case #%d: %d\n",tcase,time);
	}
	return 0;
}