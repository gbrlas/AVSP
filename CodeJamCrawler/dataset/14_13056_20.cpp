#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream input ("s.in");
ofstream output ("out.txt");
double p,q;
double divisione;

int Calcolo()
{
    double div2=divisione;
    int controllo;
    bool esatto=false;
    int i;
    for (i=0;i<40;i++)
    {
        controllo=div2;
        if (div2==controllo) {esatto=true; break;} else div2*=2;
    }
    if (!esatto) return-1;
    for (i=0;i<40;i++)
    {
        if (divisione>=1) return i; else divisione*=2;
    }
}

int main()
{
    int n,ncasi,risultato;
    input>>ncasi;
    char sbarra;
    for (n=1;n<=ncasi;n++)
    {
        input>>p>>sbarra>>q;
        divisione=p/q;
        risultato=Calcolo();
        output<<"Case #"<<n<<": ";
        if (risultato==-1) output<<"impossible"<<endl;
        else output<<risultato<<endl;
    }
    return 0;
}
