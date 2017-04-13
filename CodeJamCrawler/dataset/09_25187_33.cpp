#include<iostream>
#include<string>
#include<vector>
#include<cstring>


using namespace std;

class MyClass
{
	public:
	int a[26][15];
	void constructTable(string& key)
	{
		memset(a,0,sizeof(a));
		vector<string> list;
		for(int i = 0; i < key.size(); i++)
		{
			string s;
			if( key[i] == '(')
			{	i++;
				while(key[i]!= ')')
				{	s+=key[i];
					i++;
				}
				list.push_back(s);
			}
			else
			{
				s+= key[i];
				list.push_back(s);
			}
			
		}
		for(int i = 0; i < list.size(); i++)
			for(int j = 0; j < list[i].size(); j++)
				a[list[i][j]-'a'][i] = 1;
			
		
	}
	int howMany(vector<string> &list,string &key)
	{
		int count = 0;
		constructTable(key);
		for(int i = 0; i < list.size(); i++)
		{
			int flag = 0;
			for(int j = 0; j < list[i].size(); j++)
				if(!a[list[i][j]-'a'][j])
					flag = 1;
			if( flag == 0)
				count++;
		}
		return count;
	}
};

int main()
{
	int l,d,n;
	MyClass m;
	cin>>l;
	cin>>d;
	cin>>n;
	vector<string> list;
	for(int i = 0; i < d; i++)
	{
		string s;
		cin>>s;
		list.push_back(s);
	}
	for(int i = 0; i < n; i++)
	{
		string key;
		cin>>key;
		cout<<"Case #"<<i+1<<": "<<m.howMany(list,key)<<endl;
	}
	return 0;
}
		
