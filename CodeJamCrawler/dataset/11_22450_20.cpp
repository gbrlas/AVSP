#include <fstream>

using namespace std;

int score[101][101];
int N;

double wp[101];
double owp[101];
double oowp[101];

double calcwp(int fort,int except)
{
	int tscore,tgames;
	tscore=0;
	tgames=0;
	for(int i=1;i<=N;i++)
	{
		if(i!=fort && i!=except && score[fort][i]!=-1)
		{
			tscore+=score[fort][i];
			tgames++;
		}
	}
	return (double)(((double)tscore)/tgames);
}

double calcowp(int fort)
{
	double tscore = 0;
	int tgames = 0;
	for(int i=1;i<=N;i++)
	{
		if(score[fort][i]!=-1)
		{
			tscore+=calcwp(i,fort);
			tgames++;
		}
	}
	return tscore/tgames;
}

double calcoowp(int fort)
{
	double tscore = 0;
	int tgames = 0;
	for(int i=1;i<=N;i++)
	{
		if(score[fort][i]!=-1)
		{
			tscore+=owp[i];
			tgames++;
		}
	}
	return tscore/tgames;
}

double rpi(int fort)
{
	double RPI = 0.25 * wp[fort] + 0.50 * owp[fort] + 0.25 * oowp[fort];
	return RPI;
}

int main()
{
	ifstream f("in.txt");
	ofstream f2("out.txt");

	int T;
	f>>T;

	for(int Case = 0; Case<T; Case++)
	{
		f>>N;
		char temp;
		for(int i=1;i<=N;i++)
		{
			for(int y=1;y<=N;y++)
			{
				f>>temp;
				if(temp=='.')
					score[i][y]=-1;
				if(temp=='0')
					score[i][y]=0;
				if(temp=='1')
					score[i][y]=1;
			}
		}

		for(int i=1;i<=N;i++)
		{
			wp[i] = calcwp(i,-1);
		}

		for(int i=1;i<=N;i++)
		{
			owp[i] = calcowp(i);
		}

		for(int i=1;i<=N;i++)
		{
			oowp[i] = calcoowp(i);
		}

		f2<<"Case #"<<Case+1<<": "<<endl;
		for(int i=1;i<=N;i++)
		{
			f2<<rpi(i)<<endl;
		}
	}

	f.close();
	f2.close();
	return 0;
}
