#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");
    char L[200];
    int N;
    in>>N;
    cout<<N;
    in.getline(L,200);
    for(int i = 0; i < N; i++)
    {
        in.getline(L,200);
        int F = strlen(L);
        out<<"Case #"<<i+1<<": ";
        for(int j = 0; j < F; j++)
        {
            if(L[j] == 'a')
                out<<'y';
            else if(L[j] == 'b')
                out<<'h';
            else if(L[j] == 'c')
                out<<'e';
            else if(L[j] == 'd')
                out<<'s';
            else if(L[j] == 'e')
                out<<'o';
            else if(L[j] == 'f')
                out<<'c';
            else if(L[j] == 'g')
                out<<'v';
            else if(L[j] == 'h')
                out<<'x';
            else if(L[j] == 'i')
                out<<'d';
            else if(L[j] == 'j')
                out<<'u';
            else if(L[j] == 'k')
                out<<'i';
            else if(L[j] == 'l')
                out<<'g';
            else if(L[j] == 'm')
                out<<'l';
            else if(L[j] == 'n')
                out<<'b';
            else if(L[j] == 'o')
                out<<'k';
            else if(L[j] == 'p')
                out<<'r';
            else if(L[j] == 'q')
                out<<'z';
            else if(L[j] == 'r')
                out<<'t';
            else if(L[j] == 's')
                out<<'n';
            else if(L[j] == 't')
                out<<'w';
            else if(L[j] == 'u')
                out<<'j';
            else if(L[j] == 'v')
                out<<'p';
            else if(L[j] == 'w')
                out<<'f';
            else if(L[j] == 'x')
                out<<'m';
            else if(L[j] == 'y')
                out<<'a';
            else if(L[j] == 'z')
                out<<'q';
            else if(L[j] == ' ')
                out<<' ';
        }
            out<<endl;

    }
    out.close();
    in.close();

    return 0;
}
