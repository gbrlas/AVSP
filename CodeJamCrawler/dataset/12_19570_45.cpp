#include <iostream>
#include <map>
using namespace std;

void setup_map(map<char,char> &m) {
    m.insert(pair<char, char>('y', 'a'));
    m.insert(pair<char, char>('n', 'b'));
    m.insert(pair<char, char>('f', 'c'));
    m.insert(pair<char, char>('i', 'd'));
    m.insert(pair<char, char>('c', 'e'));
    m.insert(pair<char, char>('w', 'f'));
    m.insert(pair<char, char>('l', 'g'));
    m.insert(pair<char, char>('b', 'h'));
    m.insert(pair<char, char>('k', 'i'));
    m.insert(pair<char, char>('u', 'j'));
    m.insert(pair<char, char>('o', 'k'));
    m.insert(pair<char, char>('m', 'l'));
    m.insert(pair<char, char>('x', 'm'));
    m.insert(pair<char, char>('s', 'n'));
    m.insert(pair<char, char>('e', 'o'));
    m.insert(pair<char, char>('v', 'p'));
    m.insert(pair<char, char>('z', 'q'));
    m.insert(pair<char, char>('p', 'r'));
    m.insert(pair<char, char>('d', 's'));
    m.insert(pair<char, char>('r', 't'));
    m.insert(pair<char, char>('j', 'u'));
    m.insert(pair<char, char>('g', 'v'));
    m.insert(pair<char, char>('t', 'w'));
    m.insert(pair<char, char>('h', 'x'));
    m.insert(pair<char, char>('a', 'y'));
    m.insert(pair<char, char>('q', 'z'));
}

int main(int argc, char *argv[]) {
    map<char, char> m;
    setup_map(m);
    
    int N;
    cin >> N;
    
    for(int c = 1; c <= N; c++) {
        
        cout << "Case #" << c << ": ";
        cin >> ws;
        
        string line;
        getline(cin, line);
        const char* linec = line.c_str();
        
        for(int j = 0; j < line.length(); j++) {
            if(linec[j] < 'a' || linec[j] > 'z') {
                cout << ' ';
                continue;
            }
            
            cout << m[linec[j]];
        }
        
        cout << endl;
}
    
    return 0;
}
        
