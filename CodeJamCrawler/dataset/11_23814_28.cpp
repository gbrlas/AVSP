#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int pgcd(int a,int b)
{
    if(a==b)
    {
        return a;
    }
    if(b>a)
    {
        return pgcd(a,b-a);
    }
    return pgcd(a-b,b);
}

int ppcm(int a,int b)
{
    int z=pgcd(a,b);
    return (a*b)/z;
}

int main()
{
    int nb_cas;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        out<<"Case #"<<c+1<<": ";
        int nb_players,min,max;
        in>>nb_players>>min>>max;
        vector <int> harmony;
        harmony.resize(nb_players);
        for(int c2=0;c2<nb_players;c2++)
        {
            in>>harmony[c2];
        }
        for(int c2=min;c2<=max;c2++)
        {
            bool vrai=true;
            for(int c3=0;c3<nb_players;c3++)
            {
                if(harmony[c3]%c2!=0&&c2%harmony[c3]!=0)
                {
                    vrai=false;
                    break;
                }
            }
            if(vrai)
            {
                out<<c2;
                goto end;
            }
        }
        out<<"NO";
        end:
            out<<endl;
    }
}
