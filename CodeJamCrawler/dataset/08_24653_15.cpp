#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N,P,K,num,temp;
	cin>>N;
	for(int z=1;z<=N;z++)
	{
		vector<long> array;

		long total=0;
		cin>>P>>K>>num;
		for(int y=0;y<num;y++)
		{
			cin>>temp;
			array.push_back(temp);
		}
		sort(array.begin(),array.end(),greater<int>());
		
		int a=0,count=0,i=1;
		while(count<num)
		{
			a++;
			if(a>K)
			{
				a=1;
				i++;
			}
			total=total+(array[count]*i);
			
			count++;
		}
		cout<<"Case #"<<z<<": "<<total<<endl;
	}
	return 0;
}
