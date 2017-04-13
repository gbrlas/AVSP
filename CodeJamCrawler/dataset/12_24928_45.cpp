#include <iostream>
#include <vector>
using namespace std;

int main(){

    string i = "";
    i += "ejp mysljylc kd kxveddknmc re jsicpdrysi ";
    i += "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd ";
    i += "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    
    string o = "";
    o += "our language is impossible to understand ";
    o += "there are twenty six factorial possibilities ";
    o += "so it is okay if you want to just give up";

    vector<char> m(1000, '#');
    for(int x = 0; x <i.length(); x++){
        m[i[x]] = o[x];
    }

    m['q'] = 'z';
    m['z'] = 'q';
    // check
    for(char c='a'; c<='z'; c++)
        if(m[c] == '#') cout << "Error for " << c << endl;

    
    string l;
    getline(cin, l);
    int T = atoi(l.c_str());
    for(int i = 0; i < T; i++){
        printf("Case #%d: ", i+1);
        getline(cin, l);
        for(int j = 0; j < l.length(); j++)
            printf("%c", m[l[j]]);
        printf("\n");
    }


    return 0;
}
