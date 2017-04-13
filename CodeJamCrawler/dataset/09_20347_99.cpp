/* 
Google Codejam 2009
C. Welcome to Code Jam

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
        string pattern; 
        vector<vector<int> > indices; 
        vector<vector<int> > counter;
        vector<int> pos;
        string test;
        string solution;

    public:
	void readInput(istream &in) {
        char str[501];
        in.getline(str, 501);
        test = str;
        pattern = "welcome to code jam";
        indices = vector<vector<int> >(pattern.length());
        counter = vector<vector<int> >(pattern.length());
	}
	
	int count_matches(int pattern_pos, int test_pos) {
        //cerr << "Checking " << pattern[pattern_pos] << " at position " << test_pos << " of " << test << endl;
        if (pattern_pos >= pattern.length()) {
                //cerr << "Hit" << endl;
                return 1;
        }
        if (counter [pattern_pos][test_pos] != -1) {
           return counter [pattern_pos][test_pos];
        }
        int partial = 0;
        int total = 0;
        int cur_test_pos = 0;
        int next_pos;
        for (int i=0; i<indices[pattern_pos].size(); i++) {
            cur_test_pos = indices[pattern_pos][i];
            if (cur_test_pos < test_pos) {
               continue;
            }
            if (pattern_pos + 1 >= pattern.length()) {
               partial = 1;
            }
            else {
               next_pos = cur_test_pos+1;
               if (next_pos >= test.length()) next_pos--;
               partial = count_matches(pattern_pos+1, next_pos);
                counter [pattern_pos+1][next_pos] = partial;
            }
            total += partial;
        }
        return total % 10000;
    }

	void solve() {
         int count;
        bool impossible = false;
        // find indices
        for (int i=0; i<pattern.length(); i++) {
            bool found = false;
            for (int j=0; j<test.length(); j++) {
                if (pattern[i] == test[j]) {
                   found = true;
                   indices[i].push_back(j);
                   // cerr << "Found " << pattern[i] << " at position " << j << endl;
                }
                counter[i].push_back(-1);
            }
            if (!found) {
               impossible = true;
               break;
            }
        }
       if (!impossible) {
           count = count_matches(0, 0);
        }
        else {
             count = 0;
        }
        stringstream ss;
        if (count < 1000) ss << "0";
        if (count < 100) ss << "0";
        if (count < 10) ss << "0";
        ss << count;
    	solution = ss.str();
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
	    int cases;
	
	public:
	void readInput(istream &in) {
		in >> cases;
		instances = new Instance[cases];
		char ignore[10];
		in.getline(ignore, 10);
		for (int i = 0; i < cases; i++) {
			instances[i].readInput(in);
		}
	}
	
	void solve() {
		for (int i = 0; i < cases; i++) {
			instances[i].solve();
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
