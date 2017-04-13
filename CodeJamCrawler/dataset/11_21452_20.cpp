/* 
Google Codejam 
Round 1C 2011

A. Square tiles

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        int R, C;
        string solution;
        char **b;

    public:
	void readInput(istream &in) {
        in >> R;
        in >> C;
        b = new char*[R];
		for (int i = 0; i < R ; i++) {
            b[i] = new char[C];
            for (int j = 0; j < C ; j++) {
                do {
                   in >> b[i][j];
                }
                while (b[i][j] == '\n' || b[i][j] == '\r');
            }
        }
	}

	void solve() {
        bool impossible = false;  
		for (int i = 0; i < R - 1; i++) {
  		    for (int j = 0; j < C - 1 ; j++) {
                if (b[i][j] == '#' && b[i+1][j] == '#' && b[i][j+1] == '#' && b[i+1][j+1] == '#') {
                     b[i][j] = b[i+1][j+1] = '/';       
                     b[i+1][j] = b[i][j+1] = '\\';                          
                }
            }
        }        
		for (int i = 0; i < R ; i++) {
  		    for (int j = 0; j < C ; j++) {
                if (b[i][j] == '#') {
                   impossible = true;
                }
            }
        }        
        stringstream ss;
        if (impossible) {
           ss << endl << "Impossible";;            
        }
        else {
           for (int i = 0; i < R ; i++) {
               ss << endl;
  		       for (int j = 0; j < C ; j++) {
                   ss << b[i][j];
               }
           }
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
