#include <fstream>
#include <string>
using namespace std;

int main()
{
	char trans[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int t;fin >> t;
	fin.ignore(1);
	for(int i=1; i<=t; i++)
	{
		char c[1024] = "";
		fin.getline(c,1024);
		string str(c);
		fout << "Case #" << i << ": ";
		for(int k = 0; k < str.length(); k++)
		{
			if(str[k] == ' ') fout << ' ';
			else if(str[k] >= 'a' && str[k] <= 'z') fout << trans[str[k]-'a'];
		}
		fout << endl;
	}
	return 0;
}