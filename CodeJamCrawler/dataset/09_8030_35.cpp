#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f("b.in");
    ofstream f2("b.out");
    int nrcases;
    f>>nrcases;
    for(int hh=1; hh<=nrcases; hh++)
    {
        f2<<"Case #"<<hh<<": ";
        string s;
        f>>s;

        if(s.size()<2) { f2<<s<<"0\n"; continue; }

        int x = s.size()-1;
        int cnt[10];
        memset(cnt,0,sizeof(cnt));
        while(x>0 && s[x]<=s[x-1]) { ++cnt[s[x]-'0']; x--; }
        ++cnt[s[x]-'0'];
        --x;
        if(x==-1) //add 0
        {
            int z = s.size()-1;
            int zcnt = 0;
            while(s[z]=='0') { ++zcnt; --z; }
            f2<<s[z]<<"0";
            for(int i=0;i<zcnt;++i) f2<<"0";
            for(int i=z-1; i>=0; --i) f2<<s[i];
            f2<<"\n";
            continue;
        }

        int min = s[x]-'0'+1;
        while(min<=9 && cnt[min]==0) ++min;
        for(int i=0;i<x;++i) f2<<s[i];
        f2<<min;
        --cnt[min];
        ++cnt[s[x]-'0'];
        for(int i=0;i<=9;++i)
            for(int j=0;j<cnt[i];++j)
                f2<<i;

        f2<<"\n";

    }
    return 0;
}
