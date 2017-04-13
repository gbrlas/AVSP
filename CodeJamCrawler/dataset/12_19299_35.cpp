#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;



int main()
{
	ifstream infile("B-large.in");
	vector<int> res;
	int input_num;
	infile>>input_num;
	int k=0;
	while(k<input_num)
	{
		int googler_num;
		int surp_num;
		int req;
		infile>>googler_num;
		infile>>surp_num;
		infile>>req;

		int result = 0;
		int used_surp = 0;
		for(int i = 0; i<googler_num;i++)
		{
			int score;
			infile>>score;
			if(score == 0)
			{
				if(req == 0)
					result++;
				else
				;
			}
			else if( req*3<= score)
				result++;
			else if((req-1)*3<score)
				result++;
			else if((req-2)*3+2<=score)
			{
				if(surp_num>used_surp)
				{
					used_surp++;
					result++;
				}
			}
			else
				;
		}
		res.push_back(result);
		
		k++;
	}

	infile.close();
	infile.clear();

	ofstream outfile;
	outfile.open("output.txt");

	for(int i = 0; i<res.size();i++)
	{
		outfile<<"Case #"<<i+1<<": "<<res[i]<<endl;
	}
	outfile.close();
	outfile.clear();
}

