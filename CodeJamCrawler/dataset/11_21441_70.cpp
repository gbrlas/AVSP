/* 
Google Codejam 
Qualification Round 2011
A. Bot Trust

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
        int solution;
        int N;
        char *R;
        int *P;
        

    public:
	void readInput(istream &in) {
        in >> N;
        R = new char[N];
        P = new int[N];
		for (int i = 0; i < N ; i++) {
            in >> R[i];
            in >> P[i];
        }
	}

	void solve() {
        int total = 0;
        int Op = 1;
        int Bp = 1;
        int Oa = 0;
        int Ba = 0;
        for (int i = 0; i < N; i++) {
            int d;
            if (R[i] == 'O') {
                d = abs(P[i] - Op);
                if (i > 0 && R[i-1] == 'B') {
                    d = max(0, d - Ba); 
                }
                Ba = 0;
                Oa += d + 1;
                Op = P[i];
            }
            if (R[i] == 'B') {
                d = abs(P[i] - Bp);
                if (i > 0 && R[i-1] == 'O') {
                    d = max(0, d - Oa); 
                }
                Oa = 0;
                Ba += d + 1;
                Bp = P[i];
            }
            total += d + 1;
            //cout << R[i] << P[i] << " d:" << d << " total:" << total;
            //cout << " Op:" << Op << " Bp:" << Bp;
            //cout << " Oa:" << Oa << " Ba:" << Ba << endl;
        }
    	solution = total;
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
