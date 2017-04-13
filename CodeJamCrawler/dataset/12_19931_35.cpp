#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <string>
#include <memory>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;


namespace {

    // numeric_limits<int>::max()

    template<class T> int cSize(const T& c) // returns the size of a container as an int
    {
        return (int)c.size();
    }

    struct Instance {
        Instance(istream& in, int caseNo) : in(in), caseNo(caseNo) {}

        istream& in;
        int caseNo;
        int res;

        void readData() {
            int N, S, p;
            in >> N >> S >> p;
            res = 0;
            for (int i = 0; i < N; ++i) {
                int s;
                in >> s;

                if (p <= 1) {
                    if (s >= p) {
                        ++res;
                    }
                } else {
                    if (s >= 3*(p - 2) + 2) {
                        if (s > 3*(p - 2) + 3) {
                            ++res;
                        } else {
                            if (S > 0) {
                                ++res;
                                --S;
                            }
                        }
                    }
                }
            }
        }

        void computeResults() {
        }

        void printResults() {
            cout << "Case #" << caseNo << ": " << res << endl;
            //cout << "=================================\n";
        }

        void solve() {
            readData();
            computeResults();
            printResults();
        }
    };
}



int main(int argc, char**) {

#ifdef READ_FROM_ARGV1
    auto_ptr<ifstream> p;
    istream* in;
    if (argc >= 2) {
        p.reset(new ifstream("/home/ciobi/cpp/QtCreatorTests/Tst01-build-desktop/gcj_2012_Q_B.tst.in")); // the value of argv[1] doesn't matter; as long as in IDE there's an argv[1], the specified file is used; OTOH in CLI redirection works well, as argv[1] doesn't exist; so READ_FROM_ARGV1 isn't really needed, but it's used as a precaution
        in = p.get();
    } else {
        in = &cin;
    }
#else
    istream* in (&cin);
#endif
    int t;
    (*in) >> t;

    for (int i = 0; i < t; ++i) {
        Instance inst (*in, i + 1);
        inst.solve();
    }
    return 0;
}






