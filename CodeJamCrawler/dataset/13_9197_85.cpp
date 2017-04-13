#include<stdio.h>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}

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
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,a,b,temp,ans;
    string x="";
    string y="";
    float sq;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        sq=sqrt(a);
        if(sq==(int)sq)
            temp=(int)sq;
        else
            temp=(int)sq+1;
        ans=0;
        while(temp*temp<=b)
        {
            x=intToStr(temp);
            y=intToStr(temp*temp);
            if(ispalindrome(x) && ispalindrome(y))
                ans++;
            temp++;
        }
        printf("Case #%d: %d\n",i,ans);
    }

    return 0;
}
