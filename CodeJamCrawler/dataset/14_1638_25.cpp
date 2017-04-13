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
		double C,F,X;
		infile>>C;
		infile>>F;
		infile>>X;
		double rate=2.0;
		double farm_time=0.0;
		double time_to_win = X/rate;
		double new_time_to_win = time_to_win;
		do{
			time_to_win = new_time_to_win;
			farm_time+=C/rate;
			rate += F;
			new_time_to_win = farm_time + X/rate;
		}while(new_time_to_win < time_to_win);

		outfile<<"Case #"<<i<<": ";
		outfile.precision(7);
		outfile.setf(std::ios::fixed,std::ios::floatfield);
		outfile<<time_to_win<<std::endl;

		outfile<<std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}