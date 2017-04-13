#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct TrainNode
{
	TrainNode(string sTime1,string sTime2,int t)
	{
		int hour1,minute1,hour2,minute2;
		hour1 = (sTime1[0] - '0') * 10 + (sTime1[1] - '0');
		minute1 = (sTime1[3] - '0') * 10 + (sTime1[4] - '0');

		hour2 = (sTime2[0] - '0') * 10 + (sTime2[1] - '0');
		minute2 = (sTime2[3] - '0') * 10 + (sTime2[4] - '0');

		departure = hour1 * 60 + minute1;
		arrival = hour2 * 60 + minute2+t;
	}
	int departure;
	int arrival;
};

struct CaseNode 
{
	CaseNode(int na,int nb,int t)
	{
		NA = na;
		NB = nb;
		turnaround = t;
	}
	void SortA2B()
	{
		//sort by departure from a to b
		for (int i = 0; i < NA; i++)
			for (int j = i + 1; j < NA; j++)
				if (arrTrainNode[i].departure > arrTrainNode[j].departure)
				{
					TrainNode tempNode = arrTrainNode[i];
					arrTrainNode[i] = arrTrainNode[j];
					arrTrainNode[j] = tempNode;
				}

				// sort by arrival from b to a
				for (int i = NA; i < NA + NB; i++)
					for (int j = i + 1; j < NA + NB; j++)
						if (arrTrainNode[i].arrival > arrTrainNode[j].arrival)
						{
							TrainNode tempNode = arrTrainNode[i];
							arrTrainNode[i] = arrTrainNode[j];
							arrTrainNode[j] = tempNode;
						}
	}

	void SortB2A()
	{
		//sort by arrival from a to b
		for(int i=0;i<NA;i++)
			for(int j=i+1;j<NA;j++)
				if(arrTrainNode[i].arrival>arrTrainNode[j].arrival)
				{
					TrainNode tempNode = arrTrainNode[i];
					arrTrainNode[i] = arrTrainNode[j];
					arrTrainNode[j] = tempNode;
				}

				// sort by departure from b to a
				for (int i = NA; i < NA + NB; i++)
					for(int j=i+1;j<NA+NB;j++)
						if(arrTrainNode[i].departure>arrTrainNode[j].departure)
						{
							TrainNode tempNode = arrTrainNode[i];
							arrTrainNode[i] = arrTrainNode[j];
							arrTrainNode[j] = tempNode;
						}
	}
	int FromA()
	{
		SortA2B();
		int count = 0;

		for (int i = NA, j = 0; i < NA + NB && j<NA; )
		{
			if (arrTrainNode[i].arrival <= arrTrainNode[j].departure)
			{
				++count;
				++i;
				++j;
			}
			else
				++j;   
		}
		return NA-count;
	}

	int FromB()
	{
		SortB2A();
		int count=0;
		for(int i=0,j=NA;i<NA && j<NA+NB;)
		{
			if (arrTrainNode[i].arrival <= arrTrainNode[j].departure)
			{
				++count;
				++i;
				++j;
			}
			else
				++j;               
		}
		return NB - count;
	}

	vector<TrainNode> arrTrainNode;
	int NA;
	int NB;
	int turnaround;
};
int main()
{
	int CaseNumber;
	cin>>CaseNumber;
	vector<CaseNode> vCase;
	for(int i=0;i<CaseNumber;i++)
	{
		int t,na,nb;
		cin>>t>>na>>nb;
		CaseNode node(na,nb,t);
		for(int j=0;j<na+nb;j++)
		{
			string stime1,stime2;
			cin>>stime1>>stime2;
			TrainNode tNode(stime1,stime2,t);
			node.arrTrainNode.push_back(tNode);
		}
		vCase.push_back(node);		
	}

	for(int i=0;i<CaseNumber;i++)
	{
		cout<<"Case #"<<i+1<<": "<<vCase[i].FromA()<<" "<<vCase[i].FromB()<<endl;
	}

	return 0;
}