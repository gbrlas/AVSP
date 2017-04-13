#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    char str[100];
    int i,l,imap[128],mapn,tc,tcn;
    unsigned long long total;
    scanf("%d",&tcn);
    for(tc=0;tc<tcn;tc++)
    {
        scanf("%s",str);
        l=strlen(str);
        memset(imap,255,128*sizeof(int));
        mapn=0;
        imap[str[0]]=1;
        for(i=1;i<l;i++)
        {
            if(imap[str[i]]==-1)
            {
                imap[str[i]]=mapn++;
                if(mapn==1)
                    mapn++;
            }
        }
        if(mapn==0)
            mapn=2;
        total=0;
        for(i=0;i<l;i++)
            total=(unsigned long long)mapn*total+(unsigned long long)imap[str[i]];
        printf("Case #%d: %llu\n",tc+1,total);
    }
    return 0;
}
