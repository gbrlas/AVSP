#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int cases,t,n,i,win,limit,score,s,maxcount,mincount;
	cin>>cases;
	for(t=1;t<=cases;t++)
	{
		cin >> n >> s >> win;
		maxcount = 0;
		mincount = 0;
		limit = max(3*win-2,0);
		int limit2 = max(3*win-4,0);
 	 	for( i=0;i<n;i++ )
		{
			cin>>score;
			if(score>=limit)
				maxcount++;
			else
			{
				if(score>=limit2 && score>=win)	
					mincount++;
			}
		}
		int tot = min(mincount, s) + maxcount;
                cout<<"Case #"<<t<<": "<<tot<<"\n";
	}
} 
 
