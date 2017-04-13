#include<iostream>
#include<fstream>
#include<cstdio>

#include<vector>
#include<algorithm>

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)

#define pin fin
#define pout fout
using namespace std;
char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    ifstream fin("q1.in");
    ofstream fout("a1.out");
    int t;
    string s;
    pin>>t;
    pin.ignore();
    fr(i,1,t+1)
    {
        getline(pin,s);
        pout<<"Case #"<<i<<": ";
        fr(j,0,s.length())
          if(s[j]!=' ')
            pout<<map[s[j]-'a'];
          else
            pout<<" ";
        pout<<endl;
    }
    return 0;
}

