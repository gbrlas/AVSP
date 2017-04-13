#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out","w",stdout);
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	int T;
	cin>>T;
	int ind=0;
	while(T--)
	{
		ind++;
		string n;
		cin>>n;
		int i;
		bool f=true;
		for(i=1;i<n.length();i++)
			if(n[i-1]<n[i])f=false;
		cout<<"Case #"<<ind<<": ";
		if(!f)next_permutation(n.begin(),n.end());
		else
		{
			n+="0";
			sort(n.begin(),n.end());
			i=0;
			while(n[i]=='0')i++;
			swap(n[i],n[0]);
		}
		cout<<n<<endl;
	}
	return 0;
}