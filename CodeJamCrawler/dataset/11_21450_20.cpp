/* 
Google Codejam 
2011 Round 1B

A. RPI

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        string solution;
        int N;
        char *s;
        double *win;
        double *lost;
        double *played;
        double *wp;
        double *owp;
        double *oowp;

    public:
	void readInput(istream &in) {
        in >> N;
        s = new char[N*N];
        win = new double[N];
        lost = new double[N];
        played = new double[N];
        wp = new double[N];
        owp = new double[N];
        oowp = new double[N];
		for (int i = 0; i < N ; i++) {
            win[i] = lost[i] = played[i] = 0;
  		    for (int j = 0; j < N ; j++) {
                char c;
                do {
                   in >> c;
                }
                while(c == '\n' || c == '\r');
                s[i*N+j] = c;
                if (c == '1') {
                   win[i]++;
                   played[i]++;
                }
                if (c == '0') {
                   lost[i]++;
                   played[i]++;
                }
            }
        }
	}

	void solve() {
        stringstream ss; 
 		for (int i = 0; i < N ; i++) {
            wp[i] = win[i] / played[i];
            // cout << "wp[" << i << "] = " << wp[i] << endl;
        }
 		for (int i = 0; i < N ; i++) {
            double sumwp = 0;
    		for (int j = 0; j < N ; j++) {
                if (i!=j) {
                   if (s[j*N+i] == '0') {
                        sumwp += (win[j]) / (played[j]-1);
                   }
                   else if (s[j*N+i] == '1') {
                        sumwp += (win[j]-1) / (played[j]-1);
                   }
                }
            }
            owp[i] = sumwp / played[i];
            //cout << "owp[" << i << "] = " << owp[i] << endl;
        }
        for (int i = 0; i < N ; i++) {
             double sumowp = 0;
             for (int j = 0; j < N ; j++) {
                 if (i!=j) {
                   if (s[j*N+i] != '.') {
                         sumowp += owp[j];
                   }
                 }
             }
             oowp[i] = sumowp / played[i];
             double RPI = 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i];
             ss << endl << setiosflags(ios::fixed) << setprecision(6) <<  RPI;
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
