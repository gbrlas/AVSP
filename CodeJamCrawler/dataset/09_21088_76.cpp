#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class Pattern
{
	private:
		std::vector<std::string> m_tokens;
	public:
		Pattern(const std::string& str,size_t L);
		~Pattern();
		
		bool match(const std::string& str) const;
};

Pattern::Pattern(const std::string& str,size_t L) {
	m_tokens.resize(L);
	bool multi = false;
	size_t indx = 0;
	const size_t len = str.length();
	for (size_t i=0;i<len;i++) {
		char c = str[i];
		if (c=='(') {
			multi = true;	
		} else if (c==')') {
			multi = false;
			indx++;
		} else {
			m_tokens[indx].push_back(c);
			if (!multi) indx++;
		}
	}
}
Pattern::~Pattern() 
{
}

bool Pattern::match(const std::string& str) const {
	const size_t len = str.length();
	for (size_t i=0;i<len;i++) {
		if (std::find(m_tokens[i].begin(),m_tokens[i].end(),str[i])==m_tokens[i].end()) 
			return false;
	}
	return true;
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
	size_t L;
	size_t D;
	size_t N;
	in >> L >> D >> N;
	std::cout << "L=" << L << " D=" << D << " N=" << N << std::endl;
	std::vector<std::string> worlds;
	worlds.resize(D);
	/// read worlds
	for (size_t i=0;i<D;i++) {
		worlds[i].reserve(L+1);
		in >> worlds[i];
	}
	/// read patterns
	for (size_t i=0;i<N;i++) {
		std::string pat_str;
		in >> pat_str;
		Pattern pattern(pat_str,L);
		size_t amount = 0;
		for (size_t j=0;j<D;j++) {
			if (pattern.match(worlds[j])) amount++;
		}
		out << "Case #"<<i+1<<": "<<amount<<std::endl;
	}
	
	return 0;
}
