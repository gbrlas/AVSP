#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{
    string inp;
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char cryptext[26][2] = {{'a','y'},{'b','h'},{'c','e'},{'d','s'},{'e','o'},{'f','c'},{'g','v'},{'h','x'},{'i','d'},{'j','u'},{'k','i'},{'l','g'},{'m','l'},{'n','b'},{'o','k'},{'p','r'},{'q','z'},{'r','t'},{'s','n'},{'t','w'},{'u','j'},{'v','p'},{'w','f'},{'x','m'},{'y','a'},{'z','q'}};
    ifstream input ("A-small-attempt0.in");
    ofstream output ("output.txt");
    if(input.is_open())
    {
        getline(input,inp);
//        inp.
        n = atoi(inp.c_str());
//        istringstream ( inp ) >> n;
        for(i = 1; i <= n; i++)
        {
            getline(input,inp);
            output << "Case #" << i << ": ";
            for(j = 0; j < inp.length(); j++)
            {
                char a = inp[j];
                a = tolower(a);
                if(isalpha(a))
                {
                    for(k = 0; k < 26; k++)
                    {
                        if(a == cryptext[k][0])
                        {
                            output << cryptext[k][1] ;
                        }
                    }
                }
                else
                {
                    output << a ;
                }
            }
            output << "\n";
        }
        input.close();
        cout << "Done!!" ;
    }
    else
    {
        cout << "Error!! No reading!!" ;
    }
    return 0;
}
