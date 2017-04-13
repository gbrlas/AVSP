/* Problem : 
 * Author  : Ivan Cachicatari <ivancp@latindevelopers.com>
 * Date    : sáb may 22 11:11:16 PET 2010
 * */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Path
{
	struct FOLDERS
	{
		map<string,FOLDERS> folders;
	};

	map<string,bool> root;
	map<string,bool> commands;
	public:
	void check(string s,bool add)
	{
		//it = root.find(s);
		//if(it == it.end() && add == true )

		map<string,bool>::iterator it;
		it = root.find(s);
		if(it == root.end() && add)
		{
			string cmd = "mkdir " + s;
			commands[cmd] = true;
		}
		root[s] = true;
	}
	 void parsePath(string s,bool add)
	 {
		string f;
	 	for(int i = 0 ; i < s.size();i++)
		{
			f += s[i];
			if(s[i+1] == '/')
			{
				check(f,add);
			}
		}
		check(f,add);
	 }
	 int getCmds()
	 {
		 /*
		map<string,bool>::iterator it;
		it= commands.begin();
		while(it != commands.end())
		{
			cout<<it->first<<endl;
			it++;
		}*/
		 return commands.size();
	 }
};

int getCommands(vector<string> & v1,vector<string> & v2)
{
	Path p;
	for(int i = 0 ; i  < v1.size();i++)
		p.parsePath(v1[i],false);
	for(int i = 0 ; i  < v2.size();i++)
		p.parsePath(v2[i],true);

	return p.getCmds();
}
int main(int argc, char *argv[])
{
	int cases;
	cin>>cases;
	int c = 1;
	while(cases--)
	{
		int n,m;
		cin>>n>>m;
		vector<string> vpath;
		vector<string> vadd;
		char line[255];
		for(int i = 0 ; i < n;i++)
		{
			cin>>line;
			string s(line);
			vpath.push_back(s);
			//cout<<line<<s.c_str()<<endl;
		}
		for(int j = 0 ; j < m;j++)
		{
			cin>>line;
			string s = line;
			vadd.push_back(s);
			//cout<<line<<s.c_str()<<endl;
		}
		cout<<"Case #"<<c++<<": "<<getCommands(vpath,vadd)<<endl;
	}
	return 0;
}


