#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>
#include <sstream>

const char elements[8]={'Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F'};

void check_combine(std::string& input, const std::map<std::string,char>& combine){
	if(input.size()<2)return;
	std::map<std::string,char>::const_iterator it;
	it=combine.find(input.substr(input.size()-2,2));
	if(it==combine.end())return;
	input = input.substr(0,input.size()-2)+it->second;
}

void check_opposed(std::string& input, const std::vector<std::pair<char,char> >& opposed){
	if(input.size()<2)return;

	for(std::vector<std::pair<char,char> >::const_iterator it=opposed.begin();it!=opposed.end();it++){
		if( it->first == input[input.size()-1]){
			for(int i=0; i<input.size()-1; i++){
				if( it->second == input[i]){
					input="";
					return;
				}
			}
		}
	}
}

std::string trial(const std::string& str){
	int c,d,n;
	std::map<std::string,char> combine;
	std::vector<std::pair<char,char> > opposed;
	std::string input;
	std::string temp_output="";

	std::istringstream iss(str);
	iss >> c;
	for(int i=0;i<c;i++){
		std::string tmp;
		iss >> tmp;

		std::string key=tmp.substr(0,2);
		combine[key]=tmp.substr(2,1)[0];
		key=tmp.substr(1,1)+tmp.substr(0,1);
		combine[key]=tmp.substr(2,1)[0];
	}
#if 0
	for(std::map<std::string,char>::iterator it=combine.begin(); it!=combine.end(); it++){
		std::cerr << it->first << ":" << it->second << std::endl;
	}
#endif
	iss >> d;
	for(int i=0;i<d;i++){
		std::string tmp;
		iss >> tmp;
		opposed.push_back(std::make_pair(tmp[0],tmp[1]));
		opposed.push_back(std::make_pair(tmp[1],tmp[0]));
	}
#if 0
	for(std::vector<std::pair<char,char> >::iterator it=opposed.begin(); it!=opposed.end(); it++){
		std::cerr << it->first << ":" << it->second << std::endl;
	}
#endif
	iss >> n;
	iss >> input;


	for(std::string::iterator it=input.begin(); it!=input.end(); it++){
		bool iselement=false;
		for(int i=0;i<8;i++){
			if(elements[i]==*it){
				iselement=true;
			}
		}
		if(iselement==false){
			std::cerr << "Not an element" << std::endl;
			continue;
		}
		temp_output+= *it;

		check_combine(temp_output, combine);
		check_opposed(temp_output, opposed);
	}

	if(temp_output.size()==0) return "[]";
	if(temp_output.size()==1) return "["+temp_output+"]";
	std::ostringstream oss;
	oss << "[";
	std::string::iterator it=temp_output.begin();
	oss << *it;
	for(it++; it!=temp_output.end(); it++){
		oss << ", "<<*it;
	}
	oss << "]";

	return oss.str();
}

int main(int argc, char **argv){
	std::string str;
	int n;
	std::getline(std::cin,str);
	n=std::atoi(str.c_str());
	std::vector<std::string> query;
	for(int i=0;i<n;i++){
		std::getline(std::cin,str);
		query.push_back(str);
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
