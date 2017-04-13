#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool T[11];
int N;
string S[11];
int out;

void read()
{
    cin>>N;
    for (int i=1; i<=N; i++) cin>>S[i];
}

bool check(string a)
{
    //cout<<a<<"\n";
    bool L[30];
    for (int i=0; i<30; i++) L[i]=false;

    int i=0;
    char prev;

    while (i<a.size())
    {
        prev=a[i];
        //cout<<prev<<"\n";
        if (L[prev-'a']) return false;
        while (i<a.size() && a[i]==prev) i++;
        L[prev-'a']=true;
    }
    return true;
}

void rek(string s, int length)
{
    //cout<<s<<" "<<length<<"\n";
    if (!check(s)) return;

    if (length==N)
    {
        out++;
        return;
    }

    for (int i=1; i<=N; i++)
    {
        if (T[i]) continue;
        T[i]=true;
        rek(s+S[i], length+1);
        T[i]=false;
    }
}

int main()
{
    int ttt;
    cin>>ttt;
    for (int i=1; i<=ttt; i++)
    {
        out=0;
        read();
        rek("", 0);
        cout<<"Case #"<<i<<": "<<out<<"\n";
    }
}
