#include <fstream>
#include <string>

using namespace std;

const string W = "welcome to code jam";

int count(char* line)
{
    int a[503][25];
    int l = strlen(line);

    a[0][0] = (line[0]==W[0]);
    for(int i=1;i<l;++i)
        a[i][0] = a[i-1][0] + (line[i]==W[0]);
    for(int j=1;j<W.size();++j) a[0][j] = 0;

    for(int i=1;i<l;++i)
        for(int j=1;j<W.size();++j)
        {
            a[i][j] = a[i-1][j];
            if(line[i]==W[j]) a[i][j] += a[i][j-1];
            a[i][j] %= 10000;
        }
    return a[l-1][W.size()-1];
}

int main()
{

    ifstream f("welcome.in");
    ofstream f2("welcome.out");
    int tn;
    f>>tn;
    f.get();
    for(int hh=1;hh<=tn;++hh)
    {
        char line[502];
        f.getline(line,503);
        f2<<"Case #"<<hh<<": ";
        int res = count(line);
        if(res<1000) f2<<"0";
        if(res<100) f2<<"0";
        if(res<10) f2<<"0";
        f2<<res<<"\n";
    }
    return 0;
}
