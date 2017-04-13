#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;
bool mysort(double a, double b)
{
    return a<b;
}
bool mysort2(double a, double b)
{
    return a>b;
}
int N;
double Naomi[1001], Ken[1001],Naomi2[1001], Ken2[1001];
int fv1(int nao,int kenkezd,int kenveg)
{
    if(nao==N+1)
    {
        return 0;
    }
    if(Naomi2[nao]<Ken2[kenkezd])
    {
        return fv1(nao+1,kenkezd+1,kenveg);
    }
    else
    {
        return fv1(nao+1,kenkezd,kenveg-1)+1;
    }

}
int fv (int nao, int kenkezd, int kenveg)
{
    if(nao==N+1)
    {
        return 0;
    }
    if(Naomi[nao]>Ken[kenkezd])
    {
        return fv(nao+1,kenkezd+1,kenveg)+1;
    }
    else
    {
        return fv(nao+1,kenkezd,kenveg-1);
    }
}
int main()
{
    ofstream ki;
    ki.open("D.txt");
    ifstream be;
    be.open("D-small-attempt0.in");
    int T;
    be >>T;
    for(int t=1;t<=T;t++)
    {
        be >>N;
        for(int i=1;i<=N;i++)
        {
            be >>Naomi[i];
            Naomi2[i]=Naomi[i];
        }
        for(int i=1;i<=N;i++)
        {
            be >>Ken[i];
            Ken2[i]=Ken[i];
        }
        sort(Ken+1,Ken+N+1,mysort);
        sort(Naomi+1,Naomi+N+1,mysort);
        sort(Ken2+1,Ken2+N+1,mysort2);
        sort(Naomi2+1,Naomi2+N+1,mysort2);
        ki <<"Case #" <<t <<": "<<fv(1,1,N) << " " << fv1(1,1,N) <<endl;

    }
    be.close();
    ki.close();
    return 0;
}
//CodeBlocks 13.12,Win8.1
