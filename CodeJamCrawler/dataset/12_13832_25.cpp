#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
void toString(int n,char x[],int size)
{
    int k=0;
    while(n!=0)
    {
        x[k]=(n%10)+'0';
        n/=10;
        k++;
    }
    //cout<<k<<endl;
    reverse(x,x+k);
    x[k]='\0';
}
int toInt(char x[],int size)
{
    int res=0;
    reverse(x,x+size);
    for(int i=0;i<size;i++)
    {
        res+=(x[i]-'0')*pow(10,i);
    }
    return res;
}
int main()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int test;
    fin>>test;
    for(int u=0;u<test;u++)
    {
        int a,b,ret=0;
        char num[10],numx[10];
        fin>>a>>b;
        for(int i=a;i<b;i++)
        {
            toString(i,num,(int)log10(i)+1);
            for(int j=0;j<(int)log10(i);j++)
            {
                for(int k=0;k<(int)log10(i)+1;k++)
                {
                    if(k<=j) numx[(int)log10(i)-j+k]=num[k];
                    else numx[k-(j+1)]=num[k];
                }
                int tt=toInt(numx,(int)log10(i)+1);
                if(tt<=b && tt>i) {ret++;}
            }
        }
        fout<<"Case #"<<u+1<<": "<<ret<<endl;
    }
    return 0;
}
