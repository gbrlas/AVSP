#include <fstream>
#include <vector>

using namespace std;

class target
{
public:
	int pos;
	int step;
	target(int p, int s)
	{
		pos = p;
		step = s;
	}
};

vector<target*> A;
vector<target*> B;

int currentA,currentB;

int cpA,cpB;
int cstep;

int steps;

int targets;

int main()
{
	ifstream f("input.txt");
	ofstream f2("output.txt");

	int T;
	f>>T;
	for(int Case = 0; Case < T; Case++)
	{
		steps = 0;
		char bot;
		int val;
		cpA = 0;
		cpB = 0;
		currentA = 1;
		currentB = 1;
		cstep = 0;
		A.clear();
		B.clear();
		f >> targets;
		for(int i=0;i<targets;i++)
		{
			f >> bot >> val;
			if(bot == 'O')
			{
				A.push_back(new target(val,i));
			}
			else{
				B.push_back(new target(val,i));
			}
		}
		bool tick = false;
		bool tickpress = false;
		while(cstep<targets)
		{
			tick = false;
			tickpress = false;
			if(cpA<A.size())
			{
				if(currentA!=A[cpA]->pos)
				{
					tick = true;
					//steps ++;
					if(currentA<A[cpA]->pos)
						currentA++;
					else
						currentA-=1;
				} else {
					if(A[cpA]->step == cstep)
					{
						tick = true;
						cpA ++;
						cstep ++;
						tickpress = true;
					} else {
						// nothing. wait
					}
				}
			}

			if(cpB<B.size())
			{
				if(currentB!=B[cpB]->pos)
				{
					//steps ++;
					tick = true;
					if(currentB<B[cpB]->pos)
						currentB++;
					else
						currentB-=1;
				} else {
					if(B[cpB]->step == cstep && !tickpress)
					{
						cpB ++;
						cstep ++;
						//steps ++;
						tick = true;
					} else {
						// nothing. wait
					}
				}
			}
			if(tick)
				steps++;
		}

		f2<<"Case #"<<Case+1<<": "<<steps<<endl;
	}

	f.close();
	f2.close();
	return 0;
}
