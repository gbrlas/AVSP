#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("al.out");
	int L,D,N;
	fin>>L>>D>>N;
	//cout<<L<<' '<<D<<' '<<N<<endl;

	vector<string> dic;
	vector<string> words;
	for(int i=0;i<D;i++)
	{
		string temp;
		fin>>temp;
		dic.push_back(temp);
		//cout<<dic[i]<<endl;
	}
	for(int i=0;i<N;i++)
	{
		string temp;
		fin>>temp;
		char* cstr = new char [temp.size()+1];
		strcpy (cstr, temp.c_str());
	//	cout<<temp<<' '<<temp.size()<<endl;

		int position=0;
		bool fixed=false;
		bool* is_dic=new bool[D];
		for(int k=0;k<D;k++)
			is_dic[k]=true;
		for(int p=0;p<temp.size();p++)
		{
			if(cstr[p]=='(') 
				fixed=true;
			else if(cstr[p]==')')
			{
				fixed=false;
			}
			else
			{
				for(int j=0;j<D;j++)
				{
					if(cstr[p]!=dic[j][position]&&!fixed)
						is_dic[j]=false;
					else if(cstr[p]!=dic[j][position]&&fixed)
					{
						if(cstr[p+1]==')')
						{
							int x=p-1;
								while(cstr[x]!='('&&x>0)
								{
									if(cstr[x]!=dic[j][position])
										x--;
									else break;
								}
							if(cstr[x]=='('|| x==0)
								is_dic[j]=false;
						}
					}
				}
			}
			if(!fixed) position++;
		}
	/*				for(int k=0;k<D;k++)
				cout<<k+1<<" is "<<is_dic[k]<<endl;*/

		int count=0;
		for(int j=0;j<D;j++)
			if(is_dic[j]) count++;
		cout<<"Case #"<<i+1<<": "<<count<<endl;
		fout<<"Case #"<<i+1<<": "<<count<<endl;
	}
	return 0;
}