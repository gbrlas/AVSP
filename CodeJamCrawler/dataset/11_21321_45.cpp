#include <iostream>
using namespace std;

int main()
{
	int t, n, i, j;
	int xor, c, min, sum;
// 	freopen("C-small-attempt0.in","r",stdin);
//  	freopen("C-small-attempt0.out","w",stdout);
	cin>>t;
	for (i = 0; i < t;)
	{
		cin>>n;
		xor = 0;
		min = 1000001;
		sum = 0;
		for (j = 0; j < n; ++j)
		{
			cin>>c;
			if (c < min)
				min = c;
			sum += c;
			xor ^= c;
		}
		printf("Case #%d: ", ++i);
		if (xor == 0)
			cout<<sum - min<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}