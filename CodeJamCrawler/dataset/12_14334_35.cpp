#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>

using namespace std;

int main()
{
    FILE *fin=fopen("a.in","r"),*fout=fopen("a.out","w");
    char a[]="abcdefghijklmnopqrstuvwxyz";
    char b[]="yhesocvxduiglbkrztnwjpfmaq";
    char p[500];
    int m,x,y,z;
    fscanf(fin,"%d",&m);
    fgetc(fin);
    for(x=1;x<=m;x++)
    {
        fgets(p,500,fin);
        fprintf(fout,"Case #%d: ",x);
        for(y=0;y<strlen(p);y++)
        {
            if(p[y]==' ')
            {
                fprintf(fout," ");
            }
            for(z=0;z<26;z++)
            {
                if(a[z]==p[y])
                {
                    fprintf(fout,"%c",b[z]);
                }
            }
        }
        fprintf(fout,"\n");
    }
    return 0;
}
