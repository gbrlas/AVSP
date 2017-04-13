#include<iostream>
#include<fstream>
using namespace std;

void sortArray(float n[], int m)
{
    float temp;
    int j,k;
    for(j=0;j<m-1;j++)
        for(k=0;k<m-1-j;k++)
            if(n[k]<n[k+1])
            {
                temp=n[k];
                n[k]=n[k+1];
                n[k+1]=temp;
            }
}
int main()
{
    int t,m,i,j,l,dw,w,m1;
    float n[1001],k[1001],n1[1001],k1[1001],temp;
    fstream fin,fout;
    fin.open("D-small-attempt1.in",ios::in);
    fout.open("op.txt",ios::out);
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>m;
        m1=m;
        dw=w=0;
        for(j=0;j<m1;j++)
        {
            fin>>n[j];
            n1[j]=n[j];
        }
        for(j=0;j<m1;j++)
        {
            fin>>k[j];
            k1[j]=k[j];
        }
        sortArray(n,m);
        sortArray(k,m);
        sortArray(n1,m);
        sortArray(k1,m);
        dw=m;
        for(j=m1-1;j>=0;j--)
        {
            for(l=0;l<m1;l++)
                if(n1[j]>k1[l])
                {
                    k1[l]=k1[m1-1];
                    break;
                }
            if(l==m1)
            {
                dw--;
                k1[0]=k1[m1-1];
            }
            sortArray(k1,m1-1);
            m1--;
        }

        for(j=m-1;j>=0;j--)
        {
            for(l=m-1;l>=0;l--)
            {
                if(k[l]>n[j])
                {
                    k[l]=k[m-1];
                    sortArray(k,m-1);
                    break;
                }
            }
            if(l<0)
            {
                w=j+1;
                break;
            }
            m--;
        }
        //cout<<"Case #"<<i<<": "<<dw<<' '<<w<<'\n';
        fout<<"Case #"<<i<<": "<<dw<<' '<<w<<'\n';
    }
    return 0;
}
