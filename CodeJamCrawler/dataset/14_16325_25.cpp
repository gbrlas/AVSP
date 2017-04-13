#include <set>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("A-small-attempt0.in");
    ofstream out("trick.out");
    int nrt,r, x;
    set<int> candidates, final;
    
    in>>nrt;
    for (int it = 1;it<=nrt;it++) {
        candidates.clear();
        final.clear();
        in>>r;
        for (int i = 0;i<4;i++) {
            for (int j = 0;j<4;j++) {
                in>>x;
                if (i==(r-1)) {
                    candidates.insert(x);
                }
            }
        }
        in>>r;
        for (int i = 0;i<4;i++) {
            for (int j = 0;j<4;j++) {
                in>>x;
                if (i==(r-1)) {
                    if (candidates.count(x)>0)
                        final.insert(x);
                }
            }
        }
        out<<"Case #"<<it<<": ";
        if (final.size() == 0)
            out<<"Volunteer cheated!\n";
        else if (final.size() >1)
            out<<"Bad magician!\n";
        else out<<*(final.begin())<<"\n";
    }
    
    return 0;
}