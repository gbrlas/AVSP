#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int i,j,k;
int transStringToInt(const string s)
{	
	int n;
	stringstream  stream;//trans string to int
	stream<<s;
	stream>>n;
	stream.clear();
	return n;

}

int countSwitch(const vector <string> &a,const vector <string> &b)
{
/*		cout<<"engine:"<<endl;		
		for(j=0;j<a.size();j++)
		{
			cout<<j+1<<":"<<a[j]<<endl;
		}
		cout<<"quary:"<<endl;
		for(j=0;j<b.size();j++)
		{
			cout<<j+1<<":"<<b[j]<<endl;
		}		
		if(b.empty())cout<<"NULL"<<'\n';
		cout<<"%%%%%%%%%%%"<<'\n';
*/
		int count=0;
		int q=b.size(),s=a.size();
		count=s;
		vector<string> vtemp;
		vtemp=a;
		int switchMark=0;
		for(j=0;j<q;j++)
		{
			for(int k=0;k<s;k++)
			{
				
				if(vtemp[k]==b[j])
				{
					vtemp[k]="";
					count--;
//					cout<<"same in "<<k+1<<"   and count is "<<count<<'\n';
					break;
					
				}
			
			}
			if(count==0)   // when all the engines have showed,it`s time to switch
			{
				cout<<j<<":"<<b[j]<<endl;
				switchMark++;
				j--;	
				count=s;
				vtemp=a;
			}
			
		}	
		cout<<switchMark<<'\n';
	return switchMark;
}

int main()

{
	cout<<"start-----"<<endl;
	string slin,engine,quary;
	int n,s,q;
	vector<string> vengine,vquary;
	ifstream in("A-large.in");
	ofstream out("A-large.out");
	getline(in,slin);
	n=transStringToInt(slin);   // get case
	for(int i=0;i<n;i++)
	{
		vengine.clear();
		vquary.clear();
		getline(in,slin);   
		s=transStringToInt(slin);
		for(int j=0;j<s;j++)
		{
			getline(in,slin);
			vengine.push_back(slin);
		}                        //get the engine

		getline(in,slin);
		q=transStringToInt(slin);
		for(j=0;j<q;j++)
		{
			getline(in,slin);
			vquary.push_back(slin);
		//	quary+=slin+"\n";
		}                        //get the quary


		/////////////////////finding

		cout<<"---------------------------------------------"<<'\n';
		cout<<"Case #"<<i+1<<":"<<endl;
		out<<"Case #"<<i+1<<": "<<countSwitch(vengine,vquary)<<'\n';

		////////////////////////////////
/*		cout<<"*************** "<<endl;  //output test
		cout<<"case   "<<i<<endl;  
		cout<<"engine:"<<s<<endl;		
		for(j=0;j<s;j++)
		{
			cout<<j+1<<":"<<vengine[j]<<endl;
		}
		cout<<"quary:"<<q<<endl;
		for(j=0;j<q;j++)
		{
			cout<<j+1<<":"<<vquary[j]<<endl;
		}
*/	
	}
	return 0;
}



