#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char a[30], temp;
bool flag=false;
int ww;
int main(void)
{
    int t;
    int s, i;
    
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &t);
    for (int ca=1; ca<=t; ca++)
    {
        scanf("%s", a);
        s=strlen(a);
        flag=true;
        for (i=0; a[i+1]!='\0'; i++)
        {
            if (a[i]<a[i+1]) flag=false;
        }
        if (flag)
        {
            sort(a, a+s);
            i=0;
            while (a[i]=='0') i++;
            swap(a[i], a[0]);
            s++;
            a[s]='\0';
            for (int i=s-1; i>=1; i--)
            {
                a[i]=a[i-1];
            }
            a[1]='0';
        }
        else
        {
            for (i=s-1; i>=0; i--)
            {
                if (a[i]>a[i-1])
                {
                    break;
                }
            }
            temp=a[i];
            ww=i;
            for (int k=s-1; k>=i; k--)
            {
                if (a[k]>a[i-1] && a[k]<=temp)
                {
                    temp=a[k];
                    ww=k;
                }
            } 
            swap(a[i-1], a[ww]);
            sort(a+i, a+s);
        }
        printf("Case #%d: ", ca);
        puts(a);
    }

    return 0;
}
