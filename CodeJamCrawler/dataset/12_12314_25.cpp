#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, char> hash;

    hash.insert( make_pair('a', 'y') );
    hash.insert( make_pair('b', 'h') );
    hash.insert( make_pair('c', 'e') );
    hash.insert( make_pair('d', 's') );
    hash.insert( make_pair('e', 'o') );
    hash.insert( make_pair('f', 'c') );
    hash.insert( make_pair('g', 'v') );
    hash.insert( make_pair('h', 'x') );
    hash.insert( make_pair('i', 'd') );
    hash.insert( make_pair('j', 'u') );
    hash.insert( make_pair('k', 'i') );
    hash.insert( make_pair('l', 'g') );
    hash.insert( make_pair('m', 'l') );
    hash.insert( make_pair('n', 'b') );
    hash.insert( make_pair('o', 'k') );
    hash.insert( make_pair('p', 'r') );
    hash.insert( make_pair('q', 'z') );
    hash.insert( make_pair('r', 't') );
    hash.insert( make_pair('s', 'n') );
    hash.insert( make_pair('t', 'w') );
    hash.insert( make_pair('u', 'j') );
    hash.insert( make_pair('v', 'p') );
    hash.insert( make_pair('w', 'f') );
    hash.insert( make_pair('x', 'm') );
    hash.insert( make_pair('y', 'a') );
    hash.insert( make_pair('z', 'q') );
    hash.insert( make_pair(' ', ' ') );

    int n;
    cin >> n;
    cin.ignore();

//    cout << "n: " << n << endl;
    for( int i=0; i<n; i++ ) {
        string str;
        getline( cin, str );

        for(int j=0; j<str.length(); j++) {
            char ch = str[j];
            auto it = hash.find( ch );
            if( it != hash.end() )
                str[j] = hash[ ch ];
        }

        cout << "Case #" << i+1 << ": " << str << endl;
    }
    return 0;
}
