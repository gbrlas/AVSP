#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
    string str;
    char arr[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    int t,i=1;
    string::iterator it;
    scanf("%d ",&t);
    while(t--) {
        getline(cin,str);
        cout<<"Case #"<<i++<<": ";
        for(it=str.begin();it!=str.end();it++)
          if((int)*it==32)cout<<" ";
          else cout<<arr[(int)*it-97];
        cout<<endl;
    }
    return 0;
}
