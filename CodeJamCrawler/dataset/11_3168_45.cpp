#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;

vector<string> combine;
vector<string> opposed;

char okis1(string s)
{
	for (int i = 0; i < (int)combine.size(); ++i)
	{
		if ( (s[0] == combine[i][0] && s[1] == combine[i][1]) ||
			(s[1] == combine[i][0] && s[0] == combine[i][1])
		   )
		{
			return combine[i][2];
		}
	}
	return '*';
}

int okis2(string s)
{
	char X = s[s.size() - 1];  //  Ultimo
	
	for (int i = 0; i < (int)opposed.size(); ++i)
	{
		if (opposed[i][0] == X)
		{
			for (int j = 0; j < (int)s.size() - 1; ++j)
			{
				if (s[j] == opposed[i][1])
				{
					return j;
				}
			}
		}
		if (opposed[i][1] == X)
		{
			for (int j = 0; j < (int)s.size() - 1; ++j)
			{
				if (s[j] == opposed[i][0])
				{
					return j;
				}
			}
		}
	}
	return -1;
}

string go(string s)
{
	
	int index = 0;
	while (index < s.size())
	{
		//cout<<s<<endl;
		//cout<<index<<" " <<s[index]<<endl;
		bool change = false;
		if(index > 0)
		{
			char c = okis1(s.substr(index - 1, 2));
			if (c != '*')
			{
				s.erase(s.begin() + index - 1);
				s[index - 1] = c;
				change = true;
				continue;
			}
		}		
		if (change == false)
		{
			int temp = okis2(s.substr(0,index + 1));
			if (temp != -1)
			{
				s = s.substr(index+1 ,s.size() - (index + 1) );
				index = 0;
				continue;
			}
		}
		index++;
	}
	return s;
}

string convert(string s)
{
	string R = "[";
	for(int i = 0; i < (int)s.size(); ++i)
	{
		R += s[i];
		if (i != s.size()-1)
		{
			R += ", ";
		}
	}
	R += "]";
	return R;
}
		
int main()
{
	int T;
	scanf("%d", &T);
	int n1;
	int n2;
	string s;
	for(int caso = 1; caso <= T; ++caso)
	{
		combine.clear();
		opposed.clear();
		cin>>n1;
		for(int j = 0; j < n1; ++j)
		{
			cin>>s;
			combine.push_back(s);
		}
		cin>>n2;
		for(int j = 0; j < n2; ++j)
		{
			cin>>s;
			opposed.push_back(s);
		}
		cin>>s;
		cin>>s;
		string R = go(s);
		cout<<"Case #"<<caso<<": "<<convert(R)<<endl;
	}
}


