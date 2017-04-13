#include <fstream>
using namespace std;

int t, its, i, ans;
char cur[501], c, eth[20]="welcome to code jam";
int res[10000];

int count (int pos, int keypos)
{
	if (pos>i)
		return 0;
	if (res[pos*19+keypos]!=-1)
		return res[pos*19+keypos];
	if ((cur[pos]==eth[keypos])&&(keypos<18))
		res[pos*19+keypos]=(count(pos+1,keypos+1)+count(pos+1,keypos))%10000;
	else if (((cur[pos]==eth[keypos]))&&(keypos==18))
		res[pos*19+keypos]=(count(pos+1, keypos)+1)%10000;
	else res[pos*19+keypos]=count(pos+1,keypos)%10000;

	return res[pos*19+keypos];
}

int main()
{
	ifstream fi ("C-large.in");
	ofstream fo ("C-large.out");
	fi >> t;

	for (its=0; its<t; its++)
	{
		for (i=0; i<10000; i++)
			res[i]=-1;
		do c=fi.get();
		while ((c==10)||(c==13));
		i=0;
		while (((c>='a')&&(c<='z'))||(c==' '))
		{
			cur[i]=c; i++; c=fi.get();
		}
		cur[i]=0; i--;
		ans=count(0,0);
		fo << "Case #" << its+1 << ": ";
		if (ans<10)
			fo << "000" << ans;
		else
			if (ans<100)
				fo << "00" << ans;
			else
				if (ans<1000)
					fo << "0" << ans;
				else fo << ans;
		fo << endl;
	}
	
	fi.close();
	fo.close();
	return 0;
}