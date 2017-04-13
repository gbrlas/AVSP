#include <fstream>

using namespace std;

int Pg,Pd,G,D,N,Wd;
int Case;

bool solve()
{
	for(int i=1;i<=N;i++)
	{
		D = i;
		float temp1 = ((float)(Pd*D)/100);
		int temp = (int)(temp1);
		if(Pd == 0 || temp1 == temp)
		{
			Wd = temp;
			bool ok = false;
			int steps = D / 100 + 1;
			if(steps*100 >= D && Pg*steps >=Wd && (100-Pg)*steps >= D-Wd)
				return true;
		}
	}
	return false;
}

int main()
{
	ifstream f("in.txt");
	ofstream f2("out.txt");

	int T;
	f>>T;

	for(Case = 1; Case<=T; Case++)
	{
		f>>N>>Pd>>Pg;
		bool rez = solve();
		if(rez)
		{
			f2<<"Case #"<<Case<<": Possible"<<endl;
		} else {
			f2<<"Case #"<<Case<<": Broken"<<endl;
		}
	}

	f.close();
	f2.close();
	return 0;
}