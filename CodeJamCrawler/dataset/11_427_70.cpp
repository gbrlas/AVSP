#include <fstream>
#include <iostream>
using namespace std;

class motion
{
public:
	int step;
	int pos;
	motion():step(0),pos(0){}
};

int main()
{
	ifstream fi("A-large.in");
	ofstream fo("output.txt");

	int T;fi >> T;
	for(int i=0; i<T; i++)
	{
		int time = 0;
		int step = -1;
		motion m[2][100];
		int max[2]={0},tmax=0;
		char robot;
		int crobot,orobot;
		int p[2]={1,1};
		int index[2]={0};
		int dtime;
		int dtime2;
		int dir;

		fi >> tmax;
		//cout << "case " << i+1 << " size " << tmax << endl;
		for(int j=0; j<tmax; j++)
		{
			fi >> robot;
			if(robot == 'O')
			{
				m[0][max[0]].step = j;
				fi >> m[0][max[0]].pos;
				max[0]++;
			//	cout << "Orange step " << j << " position " << m[0][max[0]-1].pos << endl;
			}
			else
			{
				m[1][max[1]].step = j;
				fi >> m[1][max[1]].pos;
				max[1]++;
			//	cout << "Blue step " << j << " position " << m[1][max[1]-1].pos << endl;
			}
		}

		//cout << "Orange steps " << max[0] << " Blue steps " << max[1] << endl;

		//cout << "Time " << time << " Orange position " << p[0] << " Blue position " << p[1]  << endl;

		while(true)
		{
			if(max[0]==0)
			{crobot = 1;orobot=0;}//cout << "only Blue" << endl;}
			else if(max[1]==0)
			{crobot = 0;orobot=1;}//cout << "only Orange" << endl;}
			else if(m[0][index[0]].step > m[1][index[1]].step)
			{crobot = 1;orobot=0;}//cout << "chosen Blue" << endl;}
			else
			{crobot = 0;orobot=1;}//cout << "chosen Orange" << endl;}

			if(max[crobot]==index[crobot]){/*cout << "Robot " << crobot << " index " << index[crobot] << endl;*/break;}

			dtime = m[crobot][index[crobot]].pos - p[crobot];
			if(dtime < 0) dtime=-dtime;
			dtime++;
			time += dtime;
			p[crobot] = m[crobot][index[crobot]].pos;

			dtime2 = m[orobot][index[orobot]].pos - p[orobot];
			if(dtime!=0)
			{
				dir=1;
				if(dtime2 < 0){dtime2=-dtime2;dir=-1;}
				if(dtime2<=dtime){p[orobot]=m[orobot][index[orobot]].pos;}
				else{if(dir>0)p[orobot]+=dtime;else p[orobot]-=dtime;}
			}

			//cout << "Time " << time << " Orange position " << p[0] << " Blue position " << p[1]  << endl;

			index[crobot]++;
		}

		while(max[orobot]>index[orobot])
		{
			dtime = m[orobot][index[orobot]].pos - p[orobot];
			if(dtime < 0) dtime=-dtime;
			dtime++;
			time += dtime;
			p[orobot] = m[orobot][index[orobot]].pos;
			index[orobot]++;
		}

		//cout << "Time " << time << " Orange position " << p[0] << " Blue position " << p[1]  << endl;

		fo << "Case #" << i+1 << ": " << time << endl;
	}

	return 0;
}