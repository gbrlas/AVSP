/* 
Google Codejam 2009
B. Watersheds

C++ Solution by:
 Marco Chiesi
 chiesi@gmail.com
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Point {
       public:
       int r, c;
       Point (int _r, int _c) : r(_r), c(_c) {};
       bool operator< (const Point &p) const {return r < p.r || (r == p.r && c < p.c) ;};
       bool operator== (const Point &p) const {return p.r == r && p.c == c;}
};

/**
 * Class for a single instance of the problem
 */
class Instance {
    private:
        int W, H;
        vector <vector<int> > alt;
        map <Point, char> label;
        string solution;

    public:
	void readInput(istream &in) {
        in >> H;
        in >> W;
        alt = vector<vector<int> >(H+2);
		for (int i = 0; i < H+2 ; i++) {
            alt[i] = vector<int>(W+2);
            for (int j = 0; j < W+2 ; j++) {
                Point p(i, j);
                if (i>0 && i<=H && j>0 && j<=W) {
                    in >> alt[i][j];
                }
                else {
                    alt[i][j] = 20000;
                }
                label[p] = '0';
            }
        }
	}
	
	Point find_next(Point p) {
         int next_alt = alt[p.r][p.c];
         char dir = '0';
         //cerr << "Alt: " << next_alt << " - N:" << alt[p.r-1][p.c] << ", W: " << alt[p.r][p.c-1];
         //cerr << ", E: " << alt[p.r][p.c+1] << ", S: " << alt[p.r+1][p.c] << endl;
         if (alt[p.r][p.c] > alt[p.r-1][p.c] && next_alt > alt[p.r-1][p.c]) {dir = 'N'; next_alt = alt[p.r-1][p.c];}
         if (alt[p.r][p.c] > alt[p.r][p.c-1] && next_alt > alt[p.r][p.c-1]) {dir = 'W'; next_alt = alt[p.r][p.c-1];}
         if (alt[p.r][p.c] > alt[p.r][p.c+1] && next_alt > alt[p.r][p.c+1]) {dir = 'E'; next_alt = alt[p.r][p.c+1];}
         if (alt[p.r][p.c] > alt[p.r+1][p.c] && next_alt > alt[p.r+1][p.c]) {dir = 'S'; next_alt = alt[p.r+1][p.c];}
         //cerr << "Moving " << dir << endl;
         if (dir == 'W') return Point(p.r, p.c-1);
         if (dir == 'N') return Point(p.r-1, p.c);
         if (dir == 'S') return Point(p.r+1, p.c);
         if (dir == 'E') return Point(p.r, p.c+1);
         return p;
    }
    
    Point find_basin(Point p) {
          //cerr << "Find basin for (" << p.r << "," << p.c << ")" << endl;
          Point cur = p, next = p;
          do {
             cur = next;
             next = find_next(cur);
          }
          while (!(next == cur));
          return cur;
    }
    
    void label_basin(Point p, char cur_label) {
         //cerr << "Label " << cur_label << " to (" << p.r << "," << p.c << ")" << endl;
         label[p] = cur_label;
         vector <Point> nb;
         nb.push_back(Point(p.r,p.c-1));
         nb.push_back(Point(p.r-1,p.c));
         nb.push_back(Point(p.r+1,p.c));
         nb.push_back(Point(p.r,p.c+1));
         for (int i=0; i < nb.size(); i++) {
             if (label[nb[i]] == '0' && nb[i].r > 0 && nb[i].r <= H && nb[i].c > 0 && nb[i].c <= W) {
                 Point next = find_next(nb[i]);
                 if (next == p) {
                    label_basin(nb[i], cur_label);
                 }
             }
         }
    }

	void solve() {
        stringstream ss;
        char cur_label = 'a';
		for (int i = 1; i <= H ; i++) {
            for (int j = 1; j <= W ; j++) {
                Point p(i, j);
                if (label[p] == '0') {
                    Point b = find_basin (p);
                    label_basin (b, cur_label);
                    cur_label++;
                }
            }
        }
        ss << endl;
        for (int i = 1; i <= H ; i++) {
            for (int j = 1; j <= W ; j++) {
                Point p(i, j);
                ss << label[p];
                if (j < W) ss << " ";
            }
            ss << endl;
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
			out << "Case #" << i+1 << ": " << instances[i].getSolution();
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
