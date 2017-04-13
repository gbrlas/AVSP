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

        Instance(istream& in, int caseNo) : in(in), caseNo(caseNo) {
            addToTransl("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            addToTransl("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            addToTransl("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            addToTransl("q", "z");
            addToTransl("z", "q");
        }

        map<char, char> transl;
        void addToTransl(const string& s1, const string& s2) {
            for (int i = 0; i < cSize(s1); ++i) {
                transl[s1[i]] = s2[i];
            }
        }

        istream& in;
        int caseNo;
        string src;
        string res;
        //vector<char> transl;

        void readData() {
            do {
                getline(in, src);
            } while (src.empty());
        }

        void computeResults() {
            res = src;
            for (int i = 0; i < cSize(res); ++i) {
                res[i] = transl[res[i]];
            }
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

vector<int> cnt (256);
void countLetters(const string& s) {
    for (int i = 0; i < cSize(s); ++i) {
        ++cnt[s[i]];
    }
    multimap<int, char> m;
    for (int i = 0; i < 256; ++i) {
        if (cnt[i] != 0) {
            m.insert(make_pair(cnt[i], (char)i));
        }
    }
    for (multimap<int, char>::const_iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->second << " " << it->first << endl;
    }
}


int main(int argc, char**) {

    /*countLetters("our language is impossible to understand "
                 "there are twenty six factorial possibilities "
                 "so it is okay if you want to just give up");*/

    /*countLetters("ejp mysljylc kd kxveddknmc re jsicpdrysi "
                 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd "
                 "de kr kd eoya kw aej tysr re ujdr lkgc jv");*/

    //countLetters("We have come up with the best possible language here at Google, called Googlerese. To translate text into Googlerese, we take any message and replace each English letter with another English letter. This mapping is one-to-one and onto, which means that the same input letter always gets replaced with the same output letter, and different input letters always get replaced with different output letters. A letter may be replaced by itself. Spaces are left as-is. Googlerese is based on the best possible replacement mapping, and we will never change it. It will always be the same. In every test case. We will not tell you the rest of our mapping because that would make the problem too easy, but there are a few examples below that may help.");

    //return 0;


#ifdef READ_FROM_ARGV1
    auto_ptr<ifstream> p;
    istream* in;
    if (argc >= 2) {
        p.reset(new ifstream("/home/ciobi/cpp/QtCreatorTests/Tst01-build-desktop/gcj_2012_Q_A.small.in")); // the value of argv[1] doesn't matter; as long as in IDE there's an argv[1], the specified file is used; OTOH in CLI redirection works well, as argv[1] doesn't exist; so READ_FROM_ARGV1 isn't really needed, but it's used as a precaution
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

/*


c 1
h 1
j 1
k 1
m 1
v 1
x 1
b 2
d 2
f 2
w 2
g 3
p 3
y 3
l 4
n 5
r 5
u 6
a 8
e 9
o 9
s 11
t 11
i 13
  22



b 1
f 1
g 1
h 1
o 1
u 1
x 1
i 2
n 2
t 2
w 2
a 3
l 3
v 3
m 4
p 5
s 5
j 6
y 8
c 9
e 9
d 11
r 11
k 13
  22


*/




