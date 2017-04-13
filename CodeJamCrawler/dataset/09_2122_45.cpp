#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

double prob;

double treep[1010];
char str[100];
char featstr[15];
int featcnt=0;

int left[1010],right[1010],par[1010];

struct Str
{
    char str[15];
    bool operator < (const Str &o) const { if(strcmp(str,o.str)<0)return 1; return 0; }
}fs;

map<Str, int> feat;

int anifeatnum;

int n,L,A,anifeat[1010],nodecnt=0,nodenow=0,len;

char junk,junkstr[100];

main()
{
    int i,j,k,z;
    double mult=1;
    scanf("%d",&n);
    //scanf("%c",&junk);
    for(z=0;z<n;z++)
    {
        printf("Case #%d:\n",z+1);
        nodecnt=0;
        nodenow=0;
        for(i=0;i<1010;i++){left[i]=0; right[i]=0; par[i]=0; treep[i]=0; }

        scanf("%d",&L);
        scanf("%c",&junk);
        for(k=0;k<L;k++)
        {
            gets(str);
            len=strlen(str);
            for(i=0;i<len;i++)
            {
            if(str[i]=='(')
            {
                nodecnt++;
                if(left[nodenow]==0)left[nodenow]=nodecnt;
                else right[nodenow]=nodecnt;
                par[nodecnt]=nodenow;
                nodenow=nodecnt;
            }
            else if(str[i]=='0'||str[i]=='1')
            {
                mult=1;
                for(j=i;j<len;j++)
                {
                    if(str[j]==' ')break;
                    if(str[j]==')'){ nodenow=par[nodenow]; break; }
                    if(str[j]=='.')j++;
                    treep[nodenow]+=mult*(str[j]-'0');
                    mult/=10;
                }
                i=j;
            }
            else if(str[i]>='a'&&str[i]<='z')
            {
                featcnt=0;
                for(j=i;j<len;j++)
                {
                    if(str[j]==' ')break;
                    fs.str[featcnt++]=str[j];
                }
                fs.str[featcnt]='\0';
                feat[fs]=nodenow;
                //printf("Featstr %s is at node %d\n",fs.str,feat[fs]);
                i=j;
            }
            else if(str[i]==')')nodenow=par[nodenow];
            }
        }
        scanf("%d",&A);
        for(k=0;k<A;k++)
        {
            for(i=0;i<1000;i++)anifeat[i]=0;

            scanf("%s",fs.str);
            scanf("%d",&anifeatnum);
            for(i=0;i<anifeatnum;i++)
            {
             scanf("%s",fs.str);
             //printf("feat %d added\n",feat[fs]);
             anifeat[feat[fs]]=1;
            }
            nodenow=1;
            prob=1;
            while(nodenow!=0)
            {
                //printf("nodenow = %d, prob = %lf\n",nodenow,treep[nodenow]);
                prob*=treep[nodenow];
                if(anifeat[nodenow])nodenow=left[nodenow]; else nodenow=right[nodenow];
            }
            printf("%.7lf\n",prob);

        }
    }
}
