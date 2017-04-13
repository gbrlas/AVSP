#include <iostream.h>
#include <fstream>
#include <string>
using namespace std;

int main() {
   //ifstream in("ain.txt");
   ifstream in("A-small-attempt2.in");
   ofstream cout("aout.txt");
   int n, s, q, i, j, k, c, sel, t;
   string lq, line;

   in >> n;
   in.ignore();
   for(i=1; i<=n; i++){
        in >> s;
        in.ignore();
        string ls[s];
        bool bs[s];
        for(j=0; j<s; j++){
            getline(in, line);
            ls[j] = line;
            bs[j] = 1;
        }
        
        sel = 0;
        c = 0;
        in >> q;
        in.ignore();
        for(j=0; j<q; j++){
            getline(in, line);
            lq = line;
            for(k=0; k<s; k++){
                if(ls[k].compare(lq) == 0){
                    if(bs[k]){
                        bs[k] = 0;
                        sel++;
                        t = k;
                    }
                    break;
                }
            }
            if(sel == s){
                c++;
                for(k=0; k<s; k++)
                    bs[k] = 1;
                bs[t] = 0;
                sel = 1;
            }
        }
        cout << "Case #" << i << ": " << c << endl;
   }   
   in.close();
   //system("pause");
   cout.close();
   return 0;
}
