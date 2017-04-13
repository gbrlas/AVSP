#include <fstream>
#include <string>

using namespace std;

int normalize(char c)
{
    if(c>='0' && c<='9') return c-'0';
    return c-'a'+10;
}

int main()
{
    ifstream f("a.in");
    ofstream f2("a.out");
    int nrcases;
    f>>nrcases;
    for(int hh=1;hh<=nrcases;hh++)
    {
        string s;
        f>>s;
        int map[256];
        memset(map,-1,sizeof(map));
        int digit = 0;
        bool procsecond = 0;
        for(int i=0;i<s.size();++i)
        {
            int d = normalize(s[i]);
            if(map[d]==-1)
            {
                if(i>0 && !procsecond) { map[d] = 0;  procsecond = 1; }
                else map[d] = ++digit;
            }
        }
        int base = digit + 1;
        f2<<"Case #"<<hh<<": ";
        //convert:
        long long res = 0;
        long long bpow = 1;
        for(int i=s.size()-1; i>=0; i--)
        {
            res += bpow*map[normalize(s[i])];
            bpow *= base;
        }
        f2<<res<<"\n";
    }
    return 0;
}
