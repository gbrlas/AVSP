#include <iostream>
#include <fstream>
#include <set>

int main(int argc, char* argv[])
{
	std::ifstream infile;
	std::ofstream outfile;
	std::string outfilename;
	outfilename.assign(argv[1]);
	outfilename.append(".out");
	infile.open(argv[1]);
	outfile.open(outfilename);

	int T;
	infile>>T;
	for(int i=1; i<=T; ++i)
	{
		std::set<int> candidates;
		int answer;
		infile>>answer;
		for(int j=1; j<=4; ++j)
		{
			for(int k=0; k<4; ++k)
			{
				int val;
				infile>>val;
				if(j==answer)
					candidates.insert(val);
			}
		}
		infile>>answer;
		for(int j=1; j<=4; ++j)
		{
			for(int k=0; k<4; ++k)
			{
				int val;
				infile>>val;
				if(j!=answer)
					candidates.erase(val);
			}
		}
		outfile<<"Case #"<<i<<": ";
		size_t answers = candidates.size();
		switch(answers)
		{
		case 0:
			outfile<<"Volunteer cheated!";
			break;
		case 1:
			outfile<<*(candidates.begin());
			break;
		default:
			outfile<<"Bad magician!";
			break;
		}
		outfile<<std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}