/* 
Google Codejam 
B. 

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        int n, m, a;
        string solution;

    public:
	void readInput(istream &in) {
        in >> n >> m >> a;
	}
	
	float distance(int x1, int y1, int x2, int y2) {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }

	void solve() {
        bool found = false;
        int x1, x2, x3, y1, y2, y3;
        if (n*m >= a) {
            for (x1=0; x1<=n; x1++) {
                for (y1=0; y1<=m; y1++) {
                    for (x2=n; x2>=0; x2--) {
                        for (y2=0; y2<=m; y2++) {
                            for (x3=0; x3<=n; x3++) {
                                for (y3=m; y3>=0; y3--) {
                                    int double_area = (int)abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                                    if (double_area == a) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found) break;
                            }
                            if (found) break;
                        }
                        if (found) break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
        }
        if (found) {
         	stringstream ss;
            ss << x1 << " " << y1 << " ";
            ss << x2 << " " << y2 << " ";
            ss << x3 << " " << y3;
            solution = ss.str();
        }
    	else {
            solution = "IMPOSSIBLE";
        }
        cout << solution << endl;
        cout.flush();
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
