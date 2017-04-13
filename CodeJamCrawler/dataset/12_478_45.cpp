#include <fstream>
using namespace std;

int power(int b,int p)
{
	int total = 1;
	int v = b;
	while(p > 0)
	{
		if(p & 1) total *= v;
		p >>= 1;
		v*=v;
	}
	return total;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int t; fin >> t;
	for(int cas = 1; cas <= t; cas++)
	{
		int l,h,r=0;fin >> l >> h;
		for(int n = l; n <= h; n++)
		{
			int size=1,tmp=n;while((tmp/=10)>0) size++;
			int pb = power(10,size);
			for(int i = 1; i < size; i++)
			{
				int p = power(10,i);
				int k = (n/p) + (n%p)*(pb/p);
				if(k > n && k <= h) r++;
			}
		}
		fout << "Case #" << cas << ": " << r << endl;
	}
	return 0;
}