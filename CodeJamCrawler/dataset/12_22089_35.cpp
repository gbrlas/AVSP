#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;

	int a[8][3] = { {0,2,0},{0,2,-1},{0,2,1},{0,2,2},{0,-2,0},{0,-2,1},{0,-2,-1},{0,-2,-2}};
	int c[5][3] = { {0,0,0},{0,1,0},{0,-1,0},{0,1,1},{0,-1,-1} };
	int cases = 1;
	while(t-->0)
	{
		int n,s1,k;
		cin>>n>>s1>>k;
	
		int b[n];
		for(int i=0;i<n;i++)
			cin>>b[i];
		int maxm = 0;

		pair<int,int> dp[n];
		pair<int,int>dp2[n];
		for(int i=0;i<=10;i++)
		{
			int s = 3*i - 4;
			int e = 3*i + 4;
			for(int j=0;j<n;j++)
			{
				bool surprise = false;
				//cout<<b[j]<<"   ddd "<<" "<<i<<" "<<s<<" "<<e<<endl;
				if(b[j]>=s && b[j]<=e)
				{
					for(int m1=0;m1<8;m1++)
					{
						int sum = 0;
						bool good = true;
						for(int m2=0;m2<3;m2++)
						{
							sum+=(i+a[m1][m2]);
							if(i+a[m1][m2]>10 || i+a[m1][m2]<0)
								good = false;
						}
						//cout<<sum<<" "<<b[j]<<" "<<good<<endl;
						if(sum == b[j] && good)
						{
							surprise = true;
							break;
						}
					}
				}
				if(surprise)
				{
					if(i>=k)
						dp[j].first = 1;
					dp2[j].first = 1;
				}
				
				for(int m1=0;m1<5;m1++)
				{
					int sum =0;
					bool good = true;
					for(int m2=0;m2<3;m2++)
					{
						sum+=(i+c[m1][m2]);
						if(i+c[m1][m2]>10 || i+ c[m1][m2]<0)
						{
							//cout<<i<<" "<<m1<<" error "<<m2<<" "<<b[j]<<endl;
							good = false;
						}
					}
					//cout<<i<<" "<<sum<<" "<<b[j]<<" 2nd "<<good<<endl;
					if(sum == b[j] && good)
					{
						if(i>=k)
							dp[j].second = 1;
						dp2[j].second = 1;
						break;
					}
				}
				
			}

		}
        
        int surp = 0;
        int both = 0;
		int other =0;
        for(int j=0;j<n;j++)
        {
			//cout<<b[j]<<" "<<dp[j].first<<" "<<dp[j].second<<endl;
            if(dp[j].first && dp[j].second)
                both++;
			else if(dp[j].first)
				surp++;
			else if(dp[j].first || dp[j].second)
				other++;
        }
        //cout<<surp<<" "<<both<<" "<<other<<endl;

		
        if(!(surp > s1) && surp+both>=s1)
            maxm= max(surp+both+other,maxm);
		if(surp>s1 && surp+both>=s1)
			maxm = max(s1+both+other,maxm);
		if(both>=s1)
			maxm = max(maxm,both+other);

		if(surp + both < s1)
		{
			for(int i=0;i<n;i++)
			{
				//cout<<dp2[i].first<<" "<<dp2[i].second<<endl;
			}
			int convert =0;	
			for(int j=0;j<n;j++)
			{
				if(dp[j].first && dp[j].second)
					continue;
				if(dp[j].first)
				{
					continue;
				}
				//cout<<"he he"<<endl;
				if(dp2[j].first)
					convert++;
			}
			if(convert + surp + both >=s1)
			{
				maxm = max(maxm,both+surp+other);
			}
		}
						
		cout<<"Case #"<<cases<<": "<<min(maxm,n)<<endl;
		cases++;
	}

}


