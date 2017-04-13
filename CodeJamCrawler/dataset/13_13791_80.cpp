
#include <iostream>
#include <stdio.h>
#include<sstream>
#include <string>
#include <vector>
using namespace std;
bool is_palindrom(string s)
{
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}
bool is_palindrom(int N)
{
    stringstream ss;
    ss<<N;
    string str=ss.str();
    return is_palindrom(str);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/igorm/Documents/1.txt","w",stdout
            );
    freopen("/Users/igorm/Documents/A.txt","r",stdin);
    int a[1001];
    for(int i=0;i<1001;i++)
        a[i]=0;
    a[1]=1;
    a[4]=1;
    a[9]=1;
    a[121]=1;
    a[484]=1;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=l;i<=r;i++)
            if(a[i])ans++;
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        //121 484 1 4 9
        
    }
    return 0;
}

