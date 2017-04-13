/* 
Google Codejam 2009
A. Alien Language

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        vector<vector<char> > pattern;
        string solution;
        int letters;

    public:
	void readInput(istream &in, int L) {
        letters = L;
        pattern = vector<vector<char> >(L);
		for (int i = 0; i < L ; i++) {
            char c;
            in >> c;
            if (c == '(') {
                  do {
                        in >> c;
                        if (c != ')') pattern[i].push_back(c);
                  }
                  while (c != ')');
            }
            else {
                 pattern[i].push_back(c);
            } 
            sort(pattern[i].begin(), pattern[i].end());
        }
	}

	void solve(const vector<string> dictionary) {
        stringstream sss;
        int matches = 0;
        
        for (int i=0; i < dictionary.size(); i++) {
            string cur = dictionary[i];
            bool match = true;
            for (int j = 0; j < letters; j++) {
                if (find(pattern[j].begin(), pattern[j].end(), cur.at(j)) == pattern[j].end()) {
                   match = false;
                   break;
                }
                if (!match) break;
            }
            if (match) matches++;
        }
        sss << matches;
    	solution = sss.str();
	}

	string getSolution() {
    	stringstream ss;
        ss << solution;
		return ss.str();
	}
};

/**
 * Class for a problem
 */
class Problem {
	private:
        Instance *instances;
        int L, D, cases;  
        vector<string> dictionary;
	
	public:
	void readInput(istream &in) {
        in >> L;
        in >> D;
        in >> cases;
        dictionary = vector<string>(D);
		for (int i = 0; i < D; i++) {
          in >> dictionary[i]; 
        } 
        sort(dictionary.begin(), dictionary.end());
		instances = new Instance[cases];
		for (int i = 0; i < cases; i++) {
			instances[i].readInput(in, L);
			//cerr << "Completed reading " << i << endl;
		}
	}
	
	void solve() {
		for (int i = 0; i < cases; i++) {
            //cerr << "Solving pattern " << i << endl;
			instances[i].solve(dictionary);
		}
	}
	
	void writeOutput(ostream &out) {
		for (int i = 0; i < cases; i++) {
			out << "Case #" << i+1 << ": " << instances[i].getSolution() << endl;
		}
	}
};

/**
 * Main function
 */
int main(int argc, char *argv[]) {
    istream *in;
    ostream *out;
    if (argc > 1) {
        in = new fstream(argv[1], fstream::in);
    }
    else {
        in = &cin;
    }
    if (argc > 2) {
        out = new fstream(argv[2], fstream::out);
    }
    else {
        out = &cout;
    }
    Problem *problem = new Problem();
    problem->readInput(*in);
    problem->solve();
    problem->writeOutput(*out);
    return 0;
}
