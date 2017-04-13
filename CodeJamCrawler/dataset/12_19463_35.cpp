#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXL = 1000000;
char instr[MAXL];
char old[30] = "abcdefghijklmnopqrstuvwxyz";
char nnew[30] ="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int T,Case=0;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        gets(instr);
        int len=strlen(instr);
        int i;
        for(i=0;i<len;i++)
        {
            if(instr[i]!=' ')
                instr[i]=nnew[instr[i]-'a'];
        }
        printf("Case #%d: %s\n",++Case,instr);
    }
    return 0;
}
