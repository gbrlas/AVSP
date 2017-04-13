#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct CaseNode
{
	CaseNode(vector<string>& vEngine,vector<string>& vQuery)
	{
		EngineNumber=vEngine.size();
		QueryNumber=vQuery.size();
		for(int i=0;i<EngineNumber;i++)
		{
			vector<int> siEngine;
			for(int j=0;j<QueryNumber;j++)
			{
				siEngine.push_back(vEngine[i]==vQuery[j]?1:0);
			}
			matrix.push_back(siEngine);
		}
	}

	void Decide(int pos,int& newPosition, int& index)
	{
		for(int i=0;i<EngineNumber;i++)
		{
			if(matrix[i][pos]==0)
			{
				if(pos+1==QueryNumber)
				{
					newPosition=pos+1;
					index=i;
					return;
				}
				for(int j=pos+1;j<QueryNumber;j++)
				{
					if(matrix[i][j]==1)
					{
						if(j-1>newPosition)
						{
							newPosition=j-1;
							index=i;
						}
						break;
					}

					else if(j==QueryNumber-1)
					{
						newPosition=j;
						index=i;
						return;
					}
				}
			}
		}
	}

	int SwitchCount()
	{
		if(QueryNumber==0 || QueryNumber==1)
			return 0;
		int curPosition=-1;
		int curIndex=-1;
		int postion=0;
		int count=0;
		do 
		{
			Decide(postion,curPosition, curIndex);
			postion=curPosition+1;
			if(postion<QueryNumber)
				++count;
		} while (postion<QueryNumber);
		return count;
	}
	vector<vector<int>> matrix;
	vector<vector<int>> vPostion;
	vector<vector<int>> vValue;
	int EngineNumber;
	int QueryNumber;
};

int main()
{
	int CaseNumber;
	cin>>CaseNumber;
	vector<CaseNode> vCase;
	for(int i=0;i<CaseNumber;i++)
	{
		vector<string> vEngine;
		vector<string> vQuery;
		int EngineNumber;
		int QueryNumber;

		cin>>EngineNumber;
		cin.get();
		for(int j=0;j<EngineNumber;j++)
		{
			string strEngine;
			getline(cin,strEngine);
			vEngine.push_back(strEngine);
		}
		
		cin>>QueryNumber;
		cin.get();
		for(int k=0;k<QueryNumber;k++)
		{
			string strQuery;
			getline(cin,strQuery);
			vQuery.push_back(strQuery);
		}
		CaseNode node(vEngine,vQuery);
		vCase.push_back(node);
	}

	for(int i=0;i<CaseNumber;i++)
	{
		   cout<<"Case #"<<i+1<<": "<<vCase[i].SwitchCount()<<endl;
	}

	return 0;
}