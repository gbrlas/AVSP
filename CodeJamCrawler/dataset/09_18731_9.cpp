#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char s[1123456];
    int nt,len;
    scanf("%d",&nt);
    for(int t=1;t<=nt;t++)
    {
            memset(s,'0',sizeof(s));
            scanf("%s\n",s+1000);
            len=strlen(s);
            next_permutation(s,s+len);
            printf("Case #%d: %d\n",t,atoi(s));
    }
    return 0;
}
