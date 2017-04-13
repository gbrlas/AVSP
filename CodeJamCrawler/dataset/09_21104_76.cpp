#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

static const char* string = "welcome to code jam";

void calc_pattern(const char* str,const char* pattern,size_t& res) {
	if (*pattern==0) return;
	while (str = ::strchr(str,pattern[0])) {
		if (*(pattern+1)==0) { 
			res++;
			if (res>10000)
				res-=10000;
		}
		str++;
		calc_pattern(str,pattern+1,res);	
	}
}

size_t calc(const char* str,const char* pattern) {
	size_t res = 0;
	calc_pattern(str,pattern,res);
	return res;
}

int main(int argc,char** argv)
{
	if (argc<3) {
		std::cout << "usage : " << argv[0] << " infile outfile" << std::endl;
		return 0;
	}
	std::ifstream in(argv[1]);
	if (!in) {
		std::cout << " error opening file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream out(argv[2]);
	if (!out) {
		std::cout << " error creating file " << argv[2] << std::endl;
		return 1;
	}
	size_t N;
	in >>  N;
	std::string line;
	std::getline(in,line);
	std::cout << "N=" << N << std::endl;
	for (size_t i=0;i<N;i++) {
		std::getline(in,line);
		size_t val = calc(line.c_str(),string);
		std::cout << val << std::endl;
		out << "Case #"<<i+1<<": " << 
			std::setfill('0') << std::setw(4) << val << std::endl;
	}
	return 0;
}
