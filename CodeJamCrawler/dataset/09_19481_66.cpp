#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <fstream>

using namespace std;



string word[5000]; 

vector<char> v[15];


string s;

int result = 0;



int main()
{

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int l,d,n;

	fin >> l >> d >> n;

	string tmp;
	for(int i=0;i<d; ++i)
	{
	
		fin>> word[i];
	}

	for(int i=0;i<n;i++)
	{
 
		fin >> tmp;

		int numlet = 0;
		for(int j=0;j<50;j++)v[j].clear();

		for(int j=0;j<tmp.length();++j)
		{
		
			if(tmp[j]=='(')
			{
			   j++;
			   while(tmp[j]!=')')
			   {
				   v[numlet].push_back(tmp[j]); 
				   ++j;
			   }
			}else
			{
				v[numlet].push_back(tmp[j]);
			}

			numlet++;
		}

		

		result = 0;
		for(int j=0;j<d;j++)
		{
		   
			bool ind = true;
			for(int k=0;k<l;k++)
			{
				if(!count(v[k].begin(),v[k].end(),word[j][k])){ind=false;break;}
			
			}
			if(ind)result++;
		
		}

		fout << "Case #"<<i+1<<": "<<result<<endl;
	}



    return 0;
}