#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int nb_cas;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        int nb_lignes,nb_colonnes;
        in>>nb_lignes>>nb_colonnes;
        vector <string> toit;
        toit.resize(nb_lignes);
        out<<"Case #"<<c+1<<":"<<endl;
        for(int c2=0;c2<nb_lignes;c2++)
            in>>toit[c2];
        for(int c2=0;c2<nb_lignes-1;c2++)
        {
            for(int c3=0;c3<nb_colonnes-1;c3++)
            {
                if(toit[c2][c3]=='#')
                {
                    if(toit[c2+1][c3]=='#'&&toit[c2+1][c3+1]=='#'&&toit[c2][c3+1]=='#')
                    {
                        toit[c2][c3]='/';
                        toit[c2+1][c3]='\\';
                        toit[c2+1][c3+1]='/';
                        toit[c2][c3+1]='\\';
                    }
                    else
                    {
                        out<<"Impossible"<<endl;
                        goto fin;
                    }
                }
            }
        }
        for(int c2=0;c2<nb_lignes;c2++)
        {
            if(toit[c2][nb_colonnes-1]=='#')
             {
                 out<<"Impossible"<<endl;
                 goto fin;
             }
        }
        for(int c3=0;c3<nb_colonnes;c3++)
        {
            if(toit[nb_lignes-1][c3]=='#')
            {
                out<<"Impossible"<<endl;
                goto fin;
            }
        }
        for(int c2=0;c2<nb_lignes;c2++)
            out<<toit[c2]<<endl;
        fin:;
    }
}
