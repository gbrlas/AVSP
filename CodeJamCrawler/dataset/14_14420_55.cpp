#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>

using namespace std;
int main()
{
	string iFile ="A-small-attempt0.in",oFile = "output.txt";
	ifstream input;
	input.open(iFile);
	int cases,tmp,firstRow,secondRow, match,answer;
	set<int> first;
	vector<int> second;
	stringstream ss;
	input>>cases;
	for(int c =1 ; c<=cases ; ++c)
	{
		first.clear();
		second.clear();
		match = 0;
		input>>firstRow;
		for(int i = 0 ; i <16 ; ++i)
		{
			input>>tmp;
			if(i/4 == (firstRow-1))first.insert(tmp);
		}
		input>>secondRow;
		for(int i = 0 ; i <16 ; ++i)
		{
			input>>tmp;
			if(i/4 == (secondRow-1))
				second.push_back(tmp);
		}
		for(int i = 0 ; i <4 ; ++i)
		{
			if(first.find(second[i])!= first.end())
			{
				match++;
				answer = second[i];
			}
		}
		ss<<"Case #"<<c<<": ";
		if(match ==0)ss<<"Volunteer cheated!\n";
		else if(match ==1) ss<<answer<<"\n";
		else ss<<"Bad magician!\n";
	}
	input.close();
	ofstream output;
	output.open(oFile);
	output<<ss.rdbuf();
	output.flush();
	output.close();
	return 0;
}
