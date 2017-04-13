#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

int bit[20];

std::vector<int> countCandyCodes(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end){
	std::vector<int> retval(20,0);
	int val;

	for(std::vector<int>::const_iterator it=begin; it!=end; it++){
		val= *it;
		for(int i=0;i<20;i++){
			if( (val & bit[i]) == bit[i] ){
				retval[i]++;
			}
		}
	}

	return retval;
}

std::string trial(const std::vector<std::string>& query){
	std::cerr << query[1] << std::endl;
	int value=0;
	std::vector<int> candies;
	std::vector<int> candycodes;

	int num=0;
	{
		std::istringstream iss(query[0]);
		iss >> num;
	}
	{
		std::istringstream iss(query[1]);
		int temp;
		for(int i=0;i<num;i++){
			iss >> temp;
			candies.push_back(temp);
		}
		std::sort(candies.begin(),candies.end());
	}
	
	candycodes=countCandyCodes(candies.begin(),candies.end());
	for(int i=0;i<20;i++) if(candycodes[i]%2!=0)return "NO";

	value=std::accumulate(candies.begin()+1,candies.end(),0);
	

	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int main(int argc, char **argv){
	std::string str;
	int n;
	std::getline(std::cin,str);
	n=std::atoi(str.c_str());
	std::vector<std::vector<std::string> > query;
	for(int i=0;i<n;i++){
		std::getline(std::cin,str);
		std::vector<std::string> tmp;
		tmp.push_back(str);
		std::getline(std::cin,str);
		tmp.push_back(str);
		query.push_back(tmp);
	}

	for(int i=0;i<20;i++){
		bit[i]=(int)std::pow(2.0,i);
	}

	std::vector<std::string> result(n);
#ifdef _OPENMP
#pragma omp parallel for
#endif
	for(int i=0;i<n;i++){
		result[i]=trial(query[i]);
	}

	for(int i=0;i<n;i++){
		std::cout << "Case #" << i+1 << ": " << result[i] << std::endl;
	}
	return 0;
}
