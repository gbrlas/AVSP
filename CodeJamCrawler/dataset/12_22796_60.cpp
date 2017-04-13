#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;




int main()
{




    string const nomFichier("C:/test/scores.txt");
    string const aa("C:/test/B");
    ifstream monFlux(aa.c_str());
    ofstream monFluxo(nomFichier.c_str());


    int T;
    monFlux >> T;

    for (int i=0;i<T;i++)
    {
        int resultat(0);
        int j;
        int N,S,p;
        monFlux >> N >> S >> p;
        int g[N];
        for (j=0;j<N;j++)
            monFlux >> g[j];




        for (j=0;j<N;j++)
            if (g[j]>=p+2*(p-1))
            {
                resultat++;
                g[j]=-3;
            }

        for (j=0;j<N;j++)
            if (g[j]>=p+2*(p-2) && S>0 && p>1)
             {
                resultat++;
                S--;
                g[j]=-3;
             }

        if (p=0) resultat=N;
        monFluxo << "Case #"<<i+1<< ": "<< resultat << endl;
    }


    return 0;
}
/*
for (i=0;i<T+1;i++)
        getline(std::cin, chaine[i]); */
