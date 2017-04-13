#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int T;
	int X;
	char C;
	scanf("%d",&T);
	for(int caso=1;caso<=T;++caso)
	{	
		vector<pair<char,int> > v;
		vector<int> objectiveOrange;
		vector<int> objectiveBlue;
		
		int t;
		scanf("%d",&t);
		for(int i=0;i<t;++i)
		{
			cin>>C>>X;
			v.push_back(make_pair(C,X));
			if ( C=='O') objectiveOrange.push_back(X);
			else objectiveBlue.push_back(X);
		}
		objectiveOrange.push_back(-1);
		objectiveBlue.push_back(-1);
		
		
		int currentOrange = 1;
		int currentBlue = 1;
		
		//index on ObjectiveOrange
		int nextObjectiveOrange = 0;
		int nextObjectiveBlue = 0;
		
		int index = 0;
		int maxi = 0;
		while (index < v.size())
		{
			//cout<<currentOrange<<" "<<currentBlue<<endl;
			//cout<<"objective"<<endl;
			//cout<<objectiveOrange[nextObjectiveOrange]<<" "<<objectiveBlue[nextObjectiveBlue]<<endl;
			if (v[index].first == 'O' && v[index].second == currentOrange)
			{
				//cout<<"push O"<<endl;
				nextObjectiveOrange++;
				if ( objectiveBlue[nextObjectiveBlue] != -1 )
				{
					if ( currentBlue != objectiveBlue[nextObjectiveBlue])
					{
						if (currentBlue < objectiveBlue[nextObjectiveBlue])
						{
							currentBlue++;
						}
						else
						{
							currentBlue--;
						}
					}
					else
					{
						//en el otro buble lo presiona
					}
				}
				index++;
				maxi++;
				continue;
			}
			
			if (v[index].first == 'B' && v[index].second == currentBlue)
			{
				//cout<<"push B"<<endl;
				nextObjectiveBlue++;
				if ( objectiveOrange[nextObjectiveOrange] != -1 )
				{
					if ( currentOrange != objectiveOrange[nextObjectiveOrange])
					{
						if (currentOrange < objectiveOrange[nextObjectiveOrange])
						{
							currentOrange++;
						}
						else
						{
							currentOrange--;
						}
					}
					else
					{
						//en el otro buble lo presiona
					}
				}
				index++;
				maxi++;
				continue;
			}
			if ( v[index].first == 'O' )
			{
				int distO = abs(objectiveOrange[nextObjectiveOrange] - currentOrange);
				
				if (objectiveBlue[nextObjectiveBlue] != -1)
				{
					int distB = abs(objectiveBlue[nextObjectiveBlue] - currentBlue);
					if (distO >= distB)
					{
						currentBlue = objectiveBlue[nextObjectiveBlue];
						//nextObjectiveBlue++;			
					}
					else if(distO < distB)
					{
						if(objectiveBlue[nextObjectiveBlue] - currentBlue > 0)
						{
							currentBlue += distO;
						}
						else 
						{
							currentBlue -= distO;
						}
					}
				}
				currentOrange = objectiveOrange[nextObjectiveOrange];
				//nextObjectiveOrange++;
				maxi += distO;
				//index++;
				continue;
			}
			else
			{
				int distB = abs(objectiveBlue[nextObjectiveBlue] - currentBlue);
				
				if (objectiveOrange[nextObjectiveOrange] != -1)
				{
					int distO = abs(objectiveOrange[nextObjectiveOrange] - currentOrange);
					if (distB >= distO)
					{
						currentOrange = objectiveOrange[nextObjectiveOrange];
						//nextObjectiveOrange++;
					}
					else if (distB < distO)
					{
						if(objectiveOrange[nextObjectiveOrange] - currentOrange > 0)
						{
							currentOrange += distB;
						}
						else 
						{
							currentOrange -= distB;
						}
					}
				}
				currentBlue = objectiveBlue[nextObjectiveBlue];
				//nextObjectiveBlue++;
				maxi += distB;
				//index++;
				continue;
			}

		}
		
		//cout<<maxi<<endl;
		cout<<"Case #"<<caso<<": "<<maxi<<endl;
	}
}










