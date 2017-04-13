#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {


    int m;
    ifstream in(argv[1]);
    ofstream output("b.output");

    in >> m;
    int combine[30][30];
    int op[30][30];
    for (int i = 0; i < m; ++i) {
        cout << "******" << endl << endl;
        for (int p = 0; p < 30; ++p)
            for (int q = 0; q < 30; ++q)
                combine[p][q] = op[p][q] = -1;

        int c;
        in >> c;
        for (int j = 0; j < c; ++j) {
            string str;
            in >> str;
            combine[str[0]-'A'][str[1]-'A'] = str[2] - 'A';
            combine[str[1]-'A'][str[0]-'A'] = str[2] - 'A';
        }

        int d;
        in >> d;
        for (int j = 0; j < d; ++j) {
            string str;
            in >> str;
            op[str[0]-'A'][str[1]-'A'] = 1;
            op[str[1]-'A'][str[0]-'A'] = 1;
        }
        
        int n;
        in >> n;
        string str;
        in >> str;
        cout << str << endl;
        
        char ret[101];
        int idx = 0;
        ret[0] = str[0];
        for (int p = 1; p < n; ++p) {
            cout << "step --- " << p << endl;
            if (idx == -1) {
                ret[++idx] = str[p];
                continue;
            }
            cout << "  " << ret << endl;
            char a = str[p];
            char b = ret[idx];
            cout << "new " << a << " last " << b << endl;;
            char tt = combine[a-'A'][b-'A'];
            if (tt != -1) {
                ret[idx] = tt + 'A';
                cout << "comed" << endl;
                continue;
            }
            
            // op
            int mm = 0;
            int tmp = idx;
            for (mm = 0; mm <= idx; ++mm) {
                char d = ret[mm];
                if (op[a-'A'][d-'A'] == 1) {
                    idx = -1;
                    cout << "oped" << endl;
                    break;
                }
            }
            if (mm < tmp+1)
                continue;

            // nothing
            ret[++idx] = a;
            
        }
        
        
        ret[++idx] = '\0';
        output << "Case #" << i+1 << ": [";
        for (int kk = 0; kk < idx-1; ++kk) {
            output << ret[kk] << ", ";
        }
        if (idx-1 >=0 )
            output << ret[idx-1] << ']' << endl;
        else output << ']' << endl;


    
    }


    return 1;

}
