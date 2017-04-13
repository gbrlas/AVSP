#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
void solve(int k, std::vector<string> list, ofstream &out)
{
	string s1 = list[0];
	string s2 = list[1];
	int n1 = min(list[0].length(),list[1].length());
	int n2 = max(list[0].length(),list[1].length());
	if(n1==list[0].length())
	{
		s1 = list[0];
		s2 = list[1];
	}
	else
	{
		s1 = list[1];
		s2 = list[0];
	}
	double cost = 0;
	
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2)
	{
		if(s1[i] == s2[j])
		{
			cost+=0;
			i++;
			j++;
		}
		else
		{
			if(i>0 && s1[i]==s1[i-1])
			{
				cost+=1;
				i++;
			}
			else if(j>0 && s2[j]==s2[j-1])
			{
				cost+=1;
				j++;
			}
			else
			{
				cost=-1;
				break;
			}
		}
	}
	if(i != n1 && j!= n2)
	{
		cost =-1;
	}
	else if(j < s2.length())
	{
		//n2 is the longer string
		while(j < s2.length())
		{
			if(s2[j]==s2[j-1])
			{
				cost+=1;
				j++;
			}
			else
			{
				cost = -1;
				break;
			}
		}
	}
	else if(i < s1.length())
	{
		while(i < s1.length())
		{
			if(s1[i]==s1[i-1])
			{
				cost+=1;
				i++;
			}
			else
			{
				cost = -1;
				break;
			}
		}
	}
	
	if(cost >= 0)
	out<<"Case #"<<k<<": "<<cost<<endl;
	else
	out<<"Case #"<<k<<": Fegla Won"<<endl;
}
int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
        ofstream output("repeater.txt",ios::trunc|ios::out);
	int T;
	input >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		input >> N;
		std::vector<std::string> list;
		for(int j = 0; j < N; j++)
		{
			string s;
			input >> s;
			list.push_back(s);
		}
		solve(i+1,list,output);
	}
	return 0;
}
