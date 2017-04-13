#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long i,j,k,p,q,t;
    double r;
    int cnt,flag;
    char x[50],m[50],n[50];
    fstream fp, fout;
    fp.open("A-large.in", ios::in);
    fout.open("op.txt", ios::out);
    fp>>t;
    for(k=1;k<=t;k++)
    {
        cnt=flag=0;
        fp>>x;

        for( i=0,j=0;i<=strlen(x);i++)
        {
            if(flag==0&&x[i]!='/')
            {
                m[i]=x[i];
            }
            else if(flag==1)
            {
                n[j++]=x[i];
            }
            else
            {
                flag=1;
                m[i]='\0';
            }
        }
        n[j]='\0';
        p=atoll(m);
        q=atoll(n);
        //cout<<p<<"/"<<q<<" ";
        fout<<"Case #"<<k<<": ";
        r=(double)p/q;
        flag=0;
        for(i=0;i<40;i++)
        {
            if(r-(long long)r==0.0)
            {
                flag=1;
                break;
            }
            if(r>1)
                r=r-1;
            r=r*2;
        }
        if(flag==1)
        {
            while(p<q)
            {
                p=p*2;
                cnt++;
            }
            fout<<cnt<<'\n';
        }
        else
            fout<<"impossible\n";
    }
    return 0;
}
