#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "stdlib.h"
#include "math.h"

using namespace std;

int t, res;
int b[64];

__int64 value(int len, int sys){

	__int64 res = 0;
	int i;
	for (i=0;i<len;i++)
	{
		res += b[i]*pow((double)sys, (double) (len - i - 1));
		//cout<<res<<endl;
	}

	return res;

}

int main(){

	int i, j, k;

	freopen("C:\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);

	cin>>t;
	for (k=0;k<t;k++)
	
	{
		res = 0;
		char tgt[64];
		cin>>tgt;
		int len = strlen(tgt), sys = 1;
		int bit = 0, max = 1;
		b[0] = 1;
		for (i=1;i<len;i++)//bit for each bit
		{
			for (j=0;j<i;j++)
			{
				if (tgt[i] != tgt[j]) continue;
				b[i] = b[j]; 
				break;
			}
			if (j==i)
			{				
				sys++;
				if (sys == 2) b[i] = 0;
				else b[i] = sys - 1;
			}

		}
		if (sys<2) sys = 2;

// 		for (i=0;i<len;i++)//bit for each bit
// 		{
// 
// 			cout<<b[i];
// 		}
// 		cout<<endl;

		cout<<"Case #"<<k+1<<": ";
		cout<<value(len, sys)<<endl;

	}

	//b[0] = 1;b[1] = 0;b[2] = 2; b[3]=2;

	

}