#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

bool isSqrt(long x) {
     return x == (floor(sqrt(x)) * floor(sqrt(x)));
}

bool isPal(long x) {
     string in;
     ostringstream conv;
     conv << x;
     in = conv.str();
     for(int i = 0; i < in.size(); i++) {
        if(in.at(i) != in.at(in.size() - i -1) )   {
                    return false;
        }
     }     
     return true;
     
}

int main() {
    int num = 0;
    ifstream in;
    in.open("in3.txt");    
    string line = "";
    getline(in, line);  
    num = atoi(line.c_str());
    ofstream out ("out3.txt");  
    long a = 0;
    long b = 0;
    int output = 0;
    for(int i = 0; i < num; i++) {
            output = 0;
            getline(in,line);
            istringstream line2(line);        
            line2 >> a;
            line2 >> b;
            for(;a <= b; a++) {
                   if(isSqrt(a)) {
                                 cerr << a << endl;
                       if(isPal(a)) {
                                    if(isPal((long)floor(sqrt(a)))){
                                    cerr << a << "pal" << endl;
                                    output++;
                                    }
                       }
                       a += 2 * (long)floor(sqrt(a));
                   }
            }    
            out << "Case #" <<  i + 1 << ": " << output << endl;
    }
    cin >> num;
    
}
