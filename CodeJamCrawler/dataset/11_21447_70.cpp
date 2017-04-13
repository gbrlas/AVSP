/* 
Google Codejam 
Qualification Round 2011
C. Candy Splitting

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef map<string, string> combMatrix;
typedef set<string> oppSet;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        string solution;
        int N;
        int *C;

    public:
	void readInput(istream &in) {
        in >> N;
        C = new int[N];
		for (int i = 0; i < N ; i++) {
            in >> C[i];
        }
	}

	void solve() {
        int minC = C[0];
        int sumC = C[0];
        int xorC = C[0];
        for (int i=1; i < N; i++) {
            sumC = sumC + C[i];
            xorC = xorC ^ C[i];
            minC = min(minC, C[i]);
        }
        stringstream ss; 
        if (xorC == 0) {
           ss << (sumC - minC);
        }
        else {
           ss << "NO";  
        }
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
