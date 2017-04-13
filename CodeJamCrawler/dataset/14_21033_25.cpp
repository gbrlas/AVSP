#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int t;
	int a[2];
	int x[4][2];
	int temp;

	cin >> t;

	for(int ct=1;ct<=t;ct++)
	{
		for(int j=0;j<2;j++)
		{
			cin >> a[j];
			for(int k=1;k<=4;k++)
			{
				for(int l=0;l<4;l++)
				{
					if(k==a[j])
					{
						cin >> x[l][j];
					}
					else
					{
						cin >> temp;
					}
				}
			}
		}

		int samecount = 0;
		int ans = -1;

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(x[i][0] == x[j][1])
				{
					samecount++;
					ans = x[i][0];
				}
			}
		}

		if(samecount == 0)
		{
			cout<<"Case #"<<ct<<": Volunteer cheated!"<<endl;
		}
		else if(samecount == 1)
		{
			cout<<"Case #"<<ct<<": "<<ans<<endl;
		}
		else
		{
			cout<<"Case #"<<ct<<": Bad magician!"<<endl;
		}

	}
}