#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(int argc, char *argv[]) { 
        
    int T;
    cin >> T;
            
    for(int c = 1; c <= T; c++) {
        set<pair<int, int> > dups;
        int A, B;
        cin >> A >> B;
        
        int count = 0;
    
        for(int i = A; i <= B; i++) {
                    
            stringstream cnv;
            string istr;
            cnv << i;
            istr = cnv.str();
                
            for(int k = 0; k < istr.length(); k++) {
                    
                int v;
                istr.insert(0, 1, istr[istr.length() - 1]);
                istr.erase(istr.length() - 1);
                    
                if(istr[0] == '0')
                    continue;
                    
                stringstream(istr) >> v;
                
                if(v > B || v <= i)
                    continue;
                
                dups.insert(pair<int, int>(i, v));
            }        
        }
        
        cout << "Case #" << c << ": " << dups.size() << endl;
    }
}