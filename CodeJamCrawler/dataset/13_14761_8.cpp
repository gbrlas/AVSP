#include <iostream>
#include <fstream>

using namespace std;

bool consecutive_n(string s, int n)
{
    int buf = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(buf >= n)
           return true;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            buf = 0;
        else
            buf++;
    }
    if(buf >= n)
        return true;
    else
        return false;
}

int problemA(string s, int n)
{
    int result = 0;
    string sub;
    for(int i=n; i<=s.length(); i++)
    {
        for(int j=0; j<=s.length() - i; j++)
        {
            sub = s.substr (j,i);
            if(consecutive_n(sub,n))
                result ++;
        }
    }
    return result;
}
int main()
{
    ifstream filein("A-small-attempt0.in");
    ofstream fileout("A-small-attempt0.out");
    int N,n_val,counter = 1;
    string str;
    filein>>N;
    while(N > 0)
    {
        filein>>str>>n_val;
        fileout<<"Case #"<<counter<<": "<<problemA(str,n_val)<<endl;
        N--;
        counter++;
    }
    return 0;
}
