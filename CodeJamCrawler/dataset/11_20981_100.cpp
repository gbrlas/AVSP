#include<iostream>
using namespace std;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("ansC.txt","w",stdout);

	int N;
	cin>>N;
	for(int ri=1;ri<=N;ri++)
	{
		int M;
		cin>>M;
		int small=10000000;
		int sum=0;
		int tem;
		int xor=0;
		for(int i=1;i<=M;i++)
		{
			cin>>tem;
			if(small>tem)
				small=tem;
			sum+=tem;
			xor^=tem;
		}
		cout<<"Case #"<<ri<<": ";
		if(xor)
		{
			cout<<"NO"<<endl;
		}
		else
			cout<<sum-small<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
