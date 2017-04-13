#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
using namespace std;


int main()
{
    ofstream fout ("output.out");
    ifstream fin ("C-small-attempt0.in");

    int t,a,b,c,d,arr[110],k,flag,l,p,flag1,ans;
    fin>>t;
    for(int x=1;x<=t;x++)
    {
        ans=0;
        fin>>a>>b;
        c=sqrt(a);
        if(c*c!=a)
        {
            c++;
        }
        d=sqrt(b);
     //   cout<<c<<endl<<d<<endl;
     //   cout<<"hi";
        for(int i=c;i<=d;i++)
        {
            p=i;
            flag=0;
            k=0;
            while(p!=0)
            {
                arr[k++]=p%10;
                p=p/10;
            }
            l=(k/2)+1;
            for(int j=0;j<l;j++)
            {
                if(arr[j]!=arr[k-j-1])
                {
                    flag=1;
                    break;
                }
            }
           // cout<<"hi"<<endl;
            if(flag==0)
            {
                p=i*i;
                flag1=0;
                k=0;
                while(p!=0)
                {
                    arr[k++]=p%10;
                    p=p/10;
                }
                l=(k/2)+1;
                for(int j=0;j<l;j++)
                {
                    if(arr[j]!=arr[k-j-1])
                    {
                        flag1=1;
                        break;
                    }
                }
                if(flag1==0)
                {
                    ans++;
                }
            }

        }
        fout<<"Case #"<<x<<": "<<ans<<endl;
    }


    return 0;
}
