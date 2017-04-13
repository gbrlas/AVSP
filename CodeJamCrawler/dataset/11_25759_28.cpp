#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>

struct Data{
	int n;
	int l;
	int h;
	std::vector<int> notes;
};

std::string trial(const Data& in){
	int result=-1;

	std::cerr << "n=" << in.n;
	std::cerr << " l=" << in.l;
	std::cerr << " h=" << in.h << std::endl;
	for(int i=0;i<in.n;i++) std::cerr << in.notes[i] << " ";
	std::cerr << std::endl;


	for(int i=in.l; i<=in.h; i++){
		bool isok=true;
		for(int j=0;j<in.n;j++){
			if(in.notes[j] % i != 0 && i % in.notes[j]!=0){
				isok=false;
				break;
			}
		}
		if(isok){result=i;break;}
	}

	std::ostringstream oss;

	if(result==-1) oss << "NO";
	else oss << result;
	return oss.str();
}

int main(int argc, char **argv){
	std::string str;
	int t;

	std::cin >> t;
	std::vector<Data> query(t);
	for(int i=0;i<t;i++){
		std::cin >> query[i].n;
		std::cin >> query[i].l;
		std::cin >> query[i].h;
		for(int j=0;j<query[i].n;j++){
			int c;
			std::cin >> c;
			query[i].notes.push_back(c);
		}
	}

	std::vector<std::string> result(t);
#ifdef _OPENMP
#pragma omp parallel for
#endif
	for(int i=0;i<t;i++){
		result[i]=trial(query[i]);
	}

	for(int i=0;i<t;i++){
		std::cout << "Case #" << i+1 << ": " << result[i] << std::endl;
	}
	return 0;
}
