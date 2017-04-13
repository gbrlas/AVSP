#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream in("a.in");
ofstream out("a.out");

int cnt[20];
int t;
int main()
{
	int i, j, k, x;
	in>>t;
	for (int v=1; v<=t; v++)
	{
		int sum=0, ans;
		for (i=1; i<=16; i++)
			cnt[i]=0;
		in>>k;
		for (i=1; i<=4; i++)
			for(j=1; j<=4; j++)
			{
				in>>x;
				if (i==k) cnt[x]++;
			}
		in>>k;
		for (i=1; i<=4; i++)
			for(j=1; j<=4; j++)
			{
				in>>x;
				if (i==k) cnt[x]++;
			}
		for (i=1; i<=16; i++)
			if (cnt[i]==2)
			{
				sum++;
				ans=i;
			}
		out<<"Case #"<<v<<": ";
		if (sum==1)
			out<<ans<<endl;
		else
			if (sum>1)
				out<<"Bad magician!"<<endl;
			else
				out<<"Volunteer cheated!"<<endl;
	}
}