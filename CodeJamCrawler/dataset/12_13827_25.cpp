#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    char key[]="yhesocvxduiglbkrztnwjpfmaq";
    int test;
    char h;
    char g[30][100];
    fin>>test;
    for(int k=0;k<=test;k++)
    {
        fin.getline(g[k-1],5000);
        if(k==0) continue;
        fout<<"Case #"<<k<<": ";
        for(int i=0;i<strlen(g[k-1]);i++)
        {
            if(g[k-1][i]==' ') fout<<" ";
            else fout<<key[g[k-1][i]-'a'];
        }
        fout<<endl;
    }
    return 0;
}
