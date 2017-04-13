#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;


// podany string -> bez powtórzeń do s;
// liczba powtórzeń w count;
struct mystr {
    string s;
    vector<int> count;
};

void push(vector<mystr> &str, string s) {
    int i=0,c,l=s.length();
    mystr * ms = new mystr;
    (ms->s).clear();
    (ms->count).clear();
    
    (ms->s).push_back(s[0]);
    (ms->count).push_back(1); // count[0]
    c=0;
    
    for (i=1; i<l; i++) {
        if (s[i]==s[i-1]) {
            ((ms->count)[c])++;
        }
        else {
            (ms->s).push_back(s[i]);
            (ms->count).push_back(1);
            c++;
        }
    }
    str.push_back(*ms);
    delete ms;
}

void show(vector<mystr> &str) {
    int i,j,s=str.size(),n;
    cout << "<start>\n";
    for (i=0; i<s; i++) {
        cout << (str[i]).s << endl;
        n=str[i].count.size();
        for (j=0; j<n; j++) {
            cout << (str[i]).count[j] << ", ";
        }
        cout << endl;
    }
    cout << "<stop>\n";
}

// are all shortened strings the same?
bool sameS(vector<mystr> &str){
    int i,s=str.size();
    string base = str[0].s;
    i=1;
    while (str[i].s==base && i<s) {
        i++;
    }
    return (i==s);
}

int actions(vector<mystr> &str) {
    int i,j,letters=str[0].s.length(), acts=0, average, size=str.size();
    for (i=0; i<letters; i++) {
        average=0;
        for (j=0; j<size; j++) {
            average+=str[j].count[i];
        }
        average = average / size;
        for (j=0; j<size; j++) {
            acts+= abs(str[j].count[i]-average);
        }
    }
    return acts;
}

int main() {
    int i,j,T,N;
    string s;
    vector<mystr> str;
    cin >> T;
    for (i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": ";
        str.clear();
        cin >> N;
        for (j=0; j<N; j++) {
            cin >> s;
            push(str,s);
        }
        if (sameS(str)) {
            cout << actions(str) << endl;
        }
        else {
            cout << "Fegla Won\n";
        }
    }
    return 0;
}