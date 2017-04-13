/* 
Google Codejam 
Qualification Round 2011
B. Magicka

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
        int C, D, N;
        string *comb;
        string *opp;
        string input;
        string base;
        combMatrix cm;
        oppSet os;
        

    public:
	void readInput(istream &in) {
        base =  "QWERASDF";
        in >> C;
        comb = new string[C];
		for (int i = 0; i < C ; i++) {
            in >> comb[i];
            string st1, st2;
            st1 = st2 = "";
            st1 += comb[i][0];
            st1 += comb[i][1];
            st2 += comb[i][1];
            st2 += comb[i][0];
            cm[st1] = comb[i][2];
            cm[st2] = comb[i][2];
        }
        in >> D;
        opp = new string[D];
		for (int i = 0; i < D ; i++) {
            in >> opp[i];
            string st1, st2;
            st1 = st2 = "";
            st1 += opp[i][0];
            st1 += opp[i][1];
            st2 += opp[i][1];
            st2 += opp[i][0];
            os.insert(st1);
            os.insert(st2);
        }
        in >> N;
        in >> input;
	}

	void solve() {
        string buffer;
        string check, last;
        buffer = input[0];
        for (int i = 1; i < N; i++) {
            buffer = buffer + input[i];
            //cout << buffer << " -> " ;
            // Check combination
            if (buffer.size() >= 2) {
                check = buffer.substr(buffer.size() - 2, 2);
                if (cm.count(check)>0) {
                    buffer = buffer.substr(0, buffer.size() - 2) + cm[check];
                }
            }
            // Check opposite
            for (int j = 0; j < buffer.size(); j++) {
                for (int k = j; k < buffer.size() - 1; k++) {
                    last = buffer[buffer.size() - 1];
                    check = "";
                    check += buffer[k];
                    check += last;
                    if (os.count(check) > 0) {
                       buffer = "";
                       break;
                    }
                }
            }
            //cout << buffer << endl;
        }
        stringstream ss;
        ss << "[";
        for (int i = 0; i < buffer.size(); i++) {
            if (i > 0) {
                  ss << ", ";
            }
            ss << buffer[i];
        }
        ss << "]";
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
