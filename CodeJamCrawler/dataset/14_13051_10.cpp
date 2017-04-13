#include <iostream>
#include <fstream>

using namespace std;
struct struttura{char carattere; short int ripetuto;} ;
struttura stringa1[100],stringa2[100];
int nCarStringa1=0,nCarStringa2=0;
char riga[100];
int ScorriRiga(struttura stringa[])
{
    int nCar;
    stringa[0].carattere=riga[0];
    stringa[0].ripetuto=1;
    int i=1;
    nCar=0;
    while (riga[i]!='\0')
    {
        if (riga[i]==stringa[nCar].carattere)
            stringa[nCar].ripetuto++;
        else
        {
            nCar++;
            stringa[nCar].carattere=riga[i];
            stringa[nCar].ripetuto=1;
        }
        i++;
    }
    nCar++;
    return nCar;
}

int inline ValAssoluto(int ris){ if (ris<0) return -ris; else return ris;}

int short Controlla()
{
    int mosse=0,i;
    if (nCarStringa1!=nCarStringa2) return -1;
    for (i=0;i<nCarStringa1;i++)
    {
        if (stringa1[i].carattere==stringa2[i].carattere)
            mosse+=ValAssoluto(stringa1[i].ripetuto-stringa2[i].ripetuto);
        else return -1;
    }
    return mosse;
}


int main()
{
    ifstream input("s.txt");
    ofstream output("out.txt");
    int n,ncasi,i;
    int risultato; //-1 se è sbagliato
    input>>ncasi;
    for (n=1;n<=ncasi;n++)
    {
        output<<"Case #"<<n<<": ";
        input>>i; //i serve a leggere il valore 2 fisso
        input>>riga;
        nCarStringa1=ScorriRiga(stringa1);
        input>>riga;
        nCarStringa2=ScorriRiga(stringa2);
        risultato=Controlla();
        if (risultato==-1) output<<"Fegla Won"; else output<<risultato;
        if (n!=ncasi) output<<endl;
    }
    return 0;
}
