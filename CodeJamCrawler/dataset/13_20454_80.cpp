#include<iostream>
#include<stdio.h>
#include <math.h>
using namespace std;
bool pd(long long int num);
int fns(long long int x);
int main()
{

     freopen("C-small-attempt1.in","rt",stdin);
    freopen("op2.txt","wt",stdout);
    long long int TT,l,h;
    cin>>TT;
    long long int count = 0;
    long long int m = 0;
    while(m<TT)
    {
        count = 0;
        cin>>l;
        cin>>h;
        for(int i=l;i<=h;i++)
        {
            if (sqrt(i)==floor(sqrt(i)))
            {
                    if(fns(i))
                        count++;

            }

        }

        cout<<"Case #"<<m+1<<": "<<count<<endl;
        m++;
    }


    return 0;
}

int fns(long long int x)
{
    if(pd(x))
    {
        long long int y = sqrt(x);
        if(pd(y))
            return 1;
        else
            return 0;
    }
    else
        return 0;

}
bool pd(long long int num)
{
    long long int n,digit, rev = 0;
     n = num;
     do
     {
         digit = num%10;
         rev = (rev*10) + digit;
         num = num/10;
     }while (num!=0);

     if (rev==n)
       return true;
     else
       return false;
}
