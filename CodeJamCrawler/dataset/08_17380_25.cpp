
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Time
{
public:
	Time(){used=0;};
	int start,end,used;
};

int setTime(char*a)
{
	int index1 = 0,rv;
	while(a[index1]!=':')index1++;
	if(index1==2)
		rv = (((((int)a[0])-48)*10)+(((int)a[1])-48))*60;
	else
		rv = (((int)a[1])-48);

	rv += ((((int)a[index1+1])-48)*10)+(((int)a[index1+2])-48);
	return rv;
}

bool my_compare(Time* a,Time* b)
{
	return a->start<b->start;
}

int main()
{
	ifstream in("B-small-attempt0.in");
	ofstream out("out.txt");

	int cases;
	in>>cases;
	for(int k=0;k<cases;k++)
	{
		vector<Time*> vecNa,vecNb;
		int ta,na,nb,earlier=3000;
		in>>ta>>na>>nb;
		char temp[10];
		for(int i=0;i<na;i++)
		{
			vecNa.push_back(new Time());
			in>>temp;
			vecNa[i]->start = setTime(temp);
			in>>temp;
			vecNa[i]->end = setTime(temp)+ta;
		}
		sort(vecNa.begin(),vecNa.end(),my_compare);

		for(int i=0;i<nb;i++)
		{
			vecNb.push_back(new Time());
			in>>temp;
			vecNb[i]->start = setTime(temp);
			in>>temp;
			vecNb[i]->end = setTime(temp)+ta;
		}
		sort(vecNb.begin(),vecNb.end(),my_compare);

		for(int i=0;i<na;i++)
		{
			for(int j=0;j<nb;j++)
			{
				if(vecNa[i]->end <= vecNb[j]->start && vecNb[j]->used==0)
				{
					vecNb[j]->used=1;
					break;
				}
			}
		}

		for(int i=0;i<nb;i++)
		{
			for(int j=0;j<na;j++)
			{
				if(vecNb[i]->end <= vecNa[j]->start && vecNa[j]->used==0)
				{
					vecNa[j]->used=1;
					break;
				}
			}
		}

		int countA=0,countB=0;

		for(int i=0;i<na;i++)
		{
			if(vecNa[i]->used!=1)
				countA++;
			delete(vecNa[i]);
		}
		for(int i=0;i<nb;i++)
		{
			if(vecNb[i]->used!=1)
				countB++;
			delete(vecNb[i]);
		}

		out<<"Case #"<<k+1<<": "<<countA<<" "<<countB<<endl;

		vecNa.clear();
		vecNb.clear();
	}

	out.close();
	return 0;
}