#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char ch[1000];
int a[1000];
bool hash[140];
int cg[140];
int ww=0, wk, i;
long long p, sum;
int main(void)
{
    int t, s;    
    freopen("A-large.in","r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &t);
    for (int ca=1; ca<=t; ca++)
    {
        ww=0;
        memset(hash, 0, sizeof(hash));
        memset(cg, -1, sizeof(cg));
        scanf("%s", ch);
        s=strlen(ch);
        if (s==1)
        {
            sum=1;
            printf("Case #%d: ", ca);
            cout<<sum<<endl;
            continue;
        }
        for (i=0; i<s; i++)
        {
            hash[ch[i]]=true;
        }
        for (i = '0'; i<='z'; i++)
        {
            if (hash[i]) ww++;
        }
        if (ww==1) ww++;
        cg[ch[0]]=1;
        i=1;
        while (ch[i]==ch[0]) i++;
        cg[ch[i]]=0;
        wk=2;
        for (; i<s; i++)
        {
            if (cg[ch[i]]==-1)
            {
                cg[ch[i]]=wk++;
            }
        }
        for (i=0; i<s; i++)
        {
            a[i]=cg[ch[i]];
        }
        p=1;
        sum=0;
        for (i=s-1; i>=0; i--)
        {
            p=p*ww;
            sum += p*a[i]/ww;
        }
        printf("Case #%d: ", ca);
        cout<<sum<<endl;
    }
 
    return 0;
}
