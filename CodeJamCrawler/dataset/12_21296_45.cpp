#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int cs;
int main() {
    string map1 = "abcdefghijklmnopqrstuvwyxz";
    string map = "yhesocvxduiglbkrztnwjpfmaq";
    string map2 = map;
    sort(map2.begin(),map2.end());
    bool val = map1 == map2;

    int runs;
    cin >> runs;getchar();

    string s;
    while( runs-- ) {
           getline(cin,s);
           for(int i=0;i<s.size();i++)
           if( s[i] >= 'a' && s[i] <= 'z' )
           s[i] = map[ s[i]-'a' ];
           printf("Case #%d: %s\n",++cs,s.c_str());
    }
    return 0;
}
