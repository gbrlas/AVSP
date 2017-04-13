#include <fstream>

using namespace std;

int num_of_subseq(const char* text, const char* pattern, unsigned int t_begin, unsigned int t_end, unsigned int p_begin, unsigned int p_end) {
	int result = 0;
	if (p_end - p_begin == 1) {
		for (unsigned int i = t_begin; i < t_end; i++)
			if (text[i] == pattern[p_begin])
				result++;
		result = result % 10000;
	} else {
		for (unsigned int i = t_begin; i < t_end; i++)
			if (text[i] == pattern[p_begin]) {
				result = result + num_of_subseq(text, pattern, i + 1, t_end, p_begin + 1, p_end);
				result = result % 10000;
			}
	}
	return result;
}

int main() {
	ifstream in("C-small-attempt0.in");
	ofstream out("C-small.out");
	
	int N;
	string welcome = "welcome to code jam";
	const char* pattern = welcome.c_str();
	int pattern_len = welcome.size();
	string text;
	string ignore;
	
	in >> N;
	getline(in, ignore);
	for (int i = 0; i < N; i++) {
		getline(in, text);
		int text_len = text.size();
		int result;
		const char* text_str = text.c_str();
		result = num_of_subseq(text_str, pattern, 0, text_len, 0, pattern_len);
		out << "Case #" << i + 1 << ": " << (result%10000)/1000 << (result%1000)/100 << (result%100)/10 << result%10 << endl;
	}
	return 0;
}
