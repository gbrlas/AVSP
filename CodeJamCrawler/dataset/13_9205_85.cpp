#include<stdio.h>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(long long n) {string str; stringstream s; s<<n; s>>str; return str;}

bool ispalindrome(string str)
{
    int i=0;
    int flag=0;
    int l=str.size();
    while(i<l/2)
    {
     if(str[i]!=str[l-1-i])
            flag=1;
     i++;
    }
    if(!flag && str[0]!='0')
        return true;
    else
        return false;
}

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,temp,ans,i,j,high,low;
    long long a,b;
    long long z[]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,
                   121242121,123454321,125686521,
                   400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,
                   1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,
                   1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
    string x="";
    string y="";
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%lld%lld",&a,&b);
        j=0;
        while(j<39 && z[j]<a)
            j++;
        low=j;
        while(j<39 && z[j]<=b)
            j++;
        high=j-1;

        printf("Case #%d: %d\n",i,high-low+1);
    }

    return 0;
}
