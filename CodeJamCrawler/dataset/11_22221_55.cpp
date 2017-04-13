#include<iostream>

using namespace std;

int process(int a,int b)
{
	int c = 0;
	for(int i=0;i<30;i++){
		if((((1<<i) & b) !=0) && (((1<<i) & a) !=0))
		{
			continue;
		}
		if(((1<<i) & b) !=0 )
		{
				//set C's bit
				c|=(1<<i);
		}
		else if (((1<<i) & a) !=0 )
		{
				//set c's bit
				c|=(1<<i);
		}
	}
	return c;
}
		

int main()
{
	int t;
	cin>>t;
	int cases = 1;
	while(t>0)
	{
		int n;
		cin>>n;
		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		int maxm = 0;
		bool found = false;
		for(int i=1;i<(1<<n)-1;i++){
			int sumA=0;
			int sumB=0;
			int realSumA=0;
			int realSumB=0;
			for(int j=0;j<30;j++){
				if(((1<<j) & i)!=0)
				{
					if(j<n)
					{
						sumA=process(sumA,a[j]);
						realSumA+=a[j];
					}
				}
				else
				{
					if(j<n)
					{
						sumB=process(sumB,a[j]);
						realSumB+=a[j];
					}
				}
			}
			if(sumA==sumB)
			{
				found = true;
				int present = max(realSumA,realSumB);
				maxm = max(present,maxm);
			}
		}
		
			t--;
			if(!found)
				cout<<"Case #"<<cases++<<": "<<"NO"<<endl; 
			else
				cout<<"Case #"<<cases++<<": "<<maxm<<endl; 
		}
	return 0;
}



