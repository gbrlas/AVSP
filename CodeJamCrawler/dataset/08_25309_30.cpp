#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct time
{
	int h,m;
	bool from;
}timetablea[202],timetableb[101];

bool predicta(const struct time a,const struct time b)
{
	if(a.h!=b.h) return a.h<b.h;
	if(a.m!=b.m) return a.m<b.m;
	return !a.from;
}

bool predictb(const struct time a,const struct time b)
{
	if(a.h!=b.h) return a.h<b.h;
	if(a.m!=b.m) return a.m<b.m;
	return a.from;
}

int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.txt","w",stdout);
	int cases,curr_case;
	int turnaround_time;
	int num_a,num_b,total_trips;
	int ans_a,ans_b,temp;
	int h,m;
	int i;

	scanf("%d",&cases);
	curr_case=1;
	while(cases--)
	{
		scanf("%d",&turnaround_time);
		scanf("%d%d",&num_a,&num_b);
		total_trips=num_a+num_b;
		ans_a=ans_b=0;
		for(i=0;i<num_a;i++)
		{
			scanf("%d:%d",&h,&m);
			timetablea[i].h=h;
			timetablea[i].m=m;
			timetablea[i].from=true;

			scanf("%d:%d",&h,&m);
			m=m+turnaround_time;
			if(m>=60) h+=m/60,m=m%60;
			timetableb[i].h=h;
			timetableb[i].m=m;
			timetableb[i].from=true;
		}
		for(;i<num_a+num_b;i++)
		{
			scanf("%d:%d",&h,&m);
			timetableb[i].h=h;
			timetableb[i].m=m;
			timetableb[i].from=false;

			scanf("%d:%d",&h,&m);
			m=m+turnaround_time;
			if(m>=60) h+=m/60,m=m%60;
			timetablea[i].h=h;
			timetablea[i].m=m;
			timetablea[i].from=false;
		}

		sort(timetablea,timetablea+total_trips,predicta);
		sort(timetableb,timetableb+total_trips,predictb);

		temp=0;
		for(i=0;i<total_trips;i++)
		{
			if(timetablea[i].from) temp++;
			else temp--;
			if(temp>ans_a) ans_a++;
		}
		temp=0;
		for(i=0;i<total_trips;i++)
		{
			if(!timetableb[i].from) temp++;
			else temp--;
			if(temp>ans_b) ans_b++;
		}
		printf("Case #%d: %d %d\n",curr_case++,ans_a,ans_b);
	}

	return 0;
}