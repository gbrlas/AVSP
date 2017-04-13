#include<iostream>
#include <fstream>
using namespace std;
int main()
{
    string str;
    ifstream fin;
    ofstream fout("output.out");
    fin.open("A-small-attempt0.in");
    int counter=0;
    while (!fin.eof())//(fin.good())
    {
        getline(fin, str);
        if (counter == 0)
        {
            counter++;
        }
        else if (counter <= 30)
        {
            fout << "Case #" << counter++ <<": ";
            for (int i=0 ; i<str.size() ; i++)
            switch (str[i])
            {
                case 'y': fout<<"a"; break;
                case 'n': fout<<"b"; break;
                case 'f': fout<<"c"; break;
                case 'i': fout<<"d"; break;
                case 'c': fout<<"e"; break;
                case 'w': fout<<"f"; break;
                case 'l': fout<<"g"; break;
                case 'b': fout<<"h"; break;
                case 'k': fout<<"i"; break;
                case 'u': fout<<"j"; break;
                case 'o': fout<<"k"; break;
                case 'm': fout<<"l"; break;
                case 'x': fout<<"m"; break;
                case 's': fout<<"n"; break;
                case 'e': fout<<"o"; break;
                case 'v': fout<<"p"; break;
                case 'z': fout<<"q"; break;
                case 'p': fout<<"r"; break;
                case 'd': fout<<"s"; break;
                case 'r': fout<<"t"; break;
                case 'j': fout<<"u"; break;
                case 'g': fout<<"v"; break;
                case 't': fout<<"w"; break;
                case 'h': fout<<"x"; break;
                case 'a': fout<<"y"; break;
                case 'q': fout<<"z"; break;
                default: fout<<str[i]; break;
            }
            fout << endl;
        }
        else break;
    }
    return 0;
}
