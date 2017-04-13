#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    int l, d, n;
    cin >> l >> d >> n;
    vector<string> alien_lang;
    for(int read = 0; read < d; read++){
        string str;
        cin >> str;
        alien_lang.push_back(str);
    }
    
    for (int caseno = 1; caseno <= n; caseno++) {
        string str;
        cin >> str;
        
        vector<string> possible_lang;
        string tmp;
        bool in_blanket = false;
        for(int len = 0; len < str.length(); len++){
            if( str[len] == '('){
                in_blanket = true;
            }else if(str[len] == ')'){
                in_blanket = false;
                possible_lang.push_back(tmp);
                tmp = "";
            }else{
                if(in_blanket){
                    tmp += str[len];
                }else{
                    possible_lang.push_back(string(1, str[len]));
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < alien_lang.size(); i++){
            bool flag = true;
            for(int pi = 0; pi < possible_lang.size(); pi++){
                if(possible_lang[pi].find(alien_lang[i][pi]) == -1){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        printf("Case #%d: %d\n", caseno, cnt);
    }
}
