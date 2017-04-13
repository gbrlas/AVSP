#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    double time=0, c,f,x,temp=0,ftemp=0;
    char buffer[50];
    char *rest1,*rest2;
    FILE *pFile;
    ifstream fin("input.txt");
    pFile=fopen("output.txt","w");
    fin.getline(buffer,20);
    t=strtod(buffer,NULL);
    for(int i=0;i<t;i++)
    {
        fin.getline(buffer,50);
        c=strtod(buffer,&rest1);
        f=strtod(rest1,&rest2);
        x=strtod(rest2,NULL);
        int j=0;
        temp=time=0;
        while(temp<=time||j==1)
        {
            time=temp;
            temp=0;
            for(int k=0;k<j;k++)
                {
                    ftemp=2.0+f*k;
                    temp+=c/ftemp;
                }
            ftemp=2.0+f*j;
            temp+=x/ftemp;
            j++;
        }
        fprintf(pFile,"Case #%d: %.7lf\n",i+1,time);
    }
}
