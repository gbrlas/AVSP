
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct train{
	int inmidchain;
	int arrmin;
	int depmin;
} traina[100],trainb[100];

void sortindex(int arrindx[], struct train trains[],char ad,int notrains)
{
	int i;
	for(i=0;i<notrains;++i)
	{
		arrindx[i] = i;
	}
	for(i=0;i<notrains;++i)
	{
		for(int j=0;j<notrains;++j)
		{
			int bless = 0;
			if(ad =='a')
			{
				if(trains[arrindx[j]].arrmin < trains[arrindx[i]].arrmin)
					bless = 1;
			}
			else
			{
				if(trains[arrindx[j]].depmin < trains[arrindx[i]].depmin)
					bless = 1;
			}
			if(bless==1)
			{
				int temp;
				temp = arrindx[i];
				arrindx[i] = arrindx[j];
				arrindx[j] = temp;
			}
		}
	}
}

int main()
{

	int sortedaarr[100],sortedadep[100],sortedbarr[100],sortedbdep[100];

	int nocases,turnaround;
	int count = 0;
	int notrainsa,notrainsb;

	char arrival[6], departure[6];

	scanf("%d",&nocases);

	while(count < nocases)
	{
		++count;
		int trainsfroma =0;
		int trainsfromb =0;

		scanf("%d",&turnaround);

		scanf("%d",&notrainsa);
		scanf("%d",&notrainsb);

		int i=0;
		while(i<notrainsa)
		{
			scanf("%s",departure);
			scanf("%s",arrival);

			int hr = (arrival[0]-'0')*10 + (arrival[1]-'0');
			traina[i].arrmin = hr*60 + (arrival[3]-'0')*10 + (arrival[4]-'0');

			hr = (departure[0]-'0')*10 + (departure[1]-'0');
			traina[i].depmin = hr*60 + (departure[3]-'0')*10 + (departure[4]-'0');

			traina[i].inmidchain =0;

			++i;
		}
		i=0;
		while(i<notrainsb)
		{
			scanf("%s %s",departure,arrival);

			int hr = (arrival[0]-'0')*10 + (arrival[1]-'0');
			trainb[i].arrmin = hr*60 + (arrival[3]-'0')*10 + (arrival[4]-'0');

			hr = (departure[0]-'0')*10 + (departure[1]-'0');
			trainb[i].depmin = hr*60 + (departure[3]-'0')*10 + (departure[4]-'0');

			trainb[i].inmidchain =0;

			++i;
		}

		sortindex(sortedaarr,traina,'a',notrainsa);
	    sortindex(sortedadep,traina,'d',notrainsa);

	    sortindex(sortedbarr,trainb,'a',notrainsb);
	    sortindex(sortedbdep,trainb,'d',notrainsb);

		for(i=0;i<notrainsa;++i)
		{
			for(int j=0;j<notrainsb;++j)
			{
				if((trainb[sortedbdep[j]].inmidchain == 0) &&
					((traina[sortedaarr[i]].arrmin+turnaround) <= trainb[sortedbdep[j]].depmin))
				{
					trainb[sortedbdep[j]].inmidchain = 1;
					break;
				}
			}
		}

		for(i=0;i<notrainsb;++i)
		{
			for(int j=0;j<notrainsa;++j)
			{
				if((traina[sortedadep[j]].inmidchain == 0) &&
					((trainb[sortedbarr[i]].arrmin+turnaround) <= traina[sortedadep[j]].depmin))
				{
					traina[sortedadep[j]].inmidchain = 1;
					break;
				}
			}
		}

		for(i=0;i<notrainsa;++i)
		{
			if(traina[i].inmidchain == 0) ++trainsfroma;
		}
		for(i=0;i<notrainsb;++i)
		{
			if(trainb[i].inmidchain == 0) ++trainsfromb;
		}

		printf("Case #%d: %d %d\n",count,trainsfroma,trainsfromb);
	}

	return 0;
}
