#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    //"yhesocvxduiglbkr#tnwjpfma#"
    string t = "yhesocvxduiglbkrztnwjpfmaq";
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    for(int i=0;i<n;++i) {
        getline(cin,s);
        for(int j=0;j<s.size();++j)
            if(s[j]!=' ') {
                s[j] = t[s[j]-'a'];
            }
        cout<<"Case #"<<i+1<<": "<<s<<endl;
    }
    return 0;
}
