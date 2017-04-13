#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    
    map<char, char> m;
    
    while(!cin.eof()) {
        
        string l1, l2;
        
        getline(cin, l1);
        getline(cin, l2);
        
        const char *enc = l1.c_str(), *dec = l2.c_str();
        
        for(int i = 0; i < l1.length(); i++) {
            if(dec[i] < 'a' || dec[i] > 'z') 
                continue;
            
            m.insert(pair<char, char>(enc[i], dec[i]));
        }
        
        cin.peek();
    }
    
    map<char,char>::iterator it;
    
    for (it=m.begin(); it != m.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
    
    return 1;
}