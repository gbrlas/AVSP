#include <fstream>
#include <cmath>
using namespace std;
ifstream f("inputC.in");
ofstream g("outputC.out");
int T,i,j,A,B,a,b,num;
int reverse(int);
int palindrome(int);
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>A>>B;
        a=int(sqrt(double(A)));
        b=int(sqrt(double(B)));
        if(a*a<A)
        ++a;
        if(b*b>B)
        --b;
        num=0;
        for(j=a;j<=b;j++)
        {
            if(palindrome(j) && palindrome(j*j))
            num++;
        }
        g<<"Case #"<<i<<": "<<num<<"\n";
    }
    return 0;
}
int reverse(int N)
{
    int M=0;
    while(N!=0)
    {
        M=M*10+N%10;
        N/=10;
    }
    return M;
}
int palindrome(int P)
{
    return (P==reverse(P));
}
