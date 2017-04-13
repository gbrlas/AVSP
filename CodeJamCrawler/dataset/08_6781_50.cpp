#include	<cstdio>
#include	<vector>
#include	<string>
#include	<conio.h>
#include	<iostream>
#include	<algorithm>

using namespace std;

int main()
{
	int n,m,ca,cb;
	cin >> n;
	for(m=0;m<n;m++)
	{
		vector <int> ad,bd,aa,ba;
		int tt,na,nb;
		int hh,mm;
		int x,y,p;

		ad.clear();
		bd.clear();
		aa.clear();
		ba.clear();
		ca=cb=0;

		cin >> tt >> na >> nb;
		while(na--)
		{
			scanf("%d:%d",&hh,&mm);
			ad.push_back(hh*60+mm);
			scanf("%d:%d",&hh,&mm);
			ba.push_back(hh*60+mm+tt);
		}
		while(nb--)
		{
			scanf("%d:%d",&hh,&mm);
			bd.push_back(hh*60+mm);
			scanf("%d:%d",&hh,&mm);
			aa.push_back(hh*60+mm+tt);
		}

		sort(aa.begin(),aa.end());
		sort(ba.begin(),ba.end());
		sort(ad.begin(),ad.end());
		sort(bd.begin(),bd.end());

		for(x=0;x<ad.size();x++)
		{
			for(y=p=0;y<aa.size() && aa[y]<=ad[x];y++)
			{
				p++;
			}
			if(p+ca-(x+1) < 0) ca++;
		}

		for(x=0;x<bd.size();x++)
		{
			for(y=p=0;y<ba.size() && ba[y]<=bd[x];y++)
			{
				p++;
			}
			if(p+cb-(x+1) < 0) cb++;
		}

		cout << "Case #" << m+1 << ": " << ca << " " << cb << endl ;
	}
	return 0;
}