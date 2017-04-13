#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

bool isPalin(int a)
{
    int temp = a;
    int num = 0;
    while(temp!=0)
    {
        num = num*10 + temp%10;
        temp/=10;
    }
    return (a==num);
}

int main()
{
    int t;
    scanf("%d",&t);
    int count = 1;
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        
        cout<<"Case #"<<count<<": ";
        int cnt = 0;
        int i;
        for(i=a;i<=b;i++)
        {
            int r = sqrt(i);
            if(isPalin(i) && i == r*r && isPalin(r))
            { 
              cnt++;
            }
        
        }
        cout<<cnt<<endl; 
        count++;
    }

}
