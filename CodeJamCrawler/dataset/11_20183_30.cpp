#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

using namespace std;
char dic[10010][30];
bool dich[10010][30];
int arr[110][30];
int g_n,g_m;
bool dif(char str1[],char str2[],int arr[],int n)
{
    int i,j,k,len;
    if((len=strlen(str1))!=strlen(str2))return true;
    for(i=0;i<n;i++)
    {
        char ch=arr[i]+'a';
        for(j=0;j<len;j++)
        {
            if((str1[j]==ch)^(str2[j]==ch))return true;
        }
    }
    for(i=0;i<len;i++)
    {
        if(str2[i]==arr[n]+'a')return false;
    }
    return true;
}
int test(int idx,int arr[])
{
    int res=0,i,j;
    for(i=0;i<26;i++)
    {
        int ch=arr[i];
        if(dich[idx][ch])continue;
        for(j=0;j<g_n;j++)
            if(j!=idx)
            {
                if(dif(dic[idx],dic[j],arr,i)==false)
                {
                    break;
                }
            }
        if(j<g_n)
        {
            res++;
        }
    }
    return res;
}
void reader()
{
    scanf("%d%d",&g_n,&g_m);
    char tmp[30];
    int i,j;
    memset(dic,0,sizeof(dic));
    memset(dich,0,sizeof(dich));
    for(i=0;i<g_n;i++)
    {
        scanf("%s",dic[i]);
        for(j=0;dic[i][j];j++)
        {
            dich[i][dic[i][j]-'a']=true;
        }
    }
    for(i=0;i<g_m;i++)
    {
        scanf("%s",tmp);
        for(j=0;tmp[j];j++)
        {
            arr[i][j]=tmp[j]-'a';
        }
    }
}
char * solver(int arr[])
{
    int i,mx=0,mxi=0;
    for(i=0;i<g_n;i++)
    {
        int t=test(i,arr);
        //printf("\n%s=%d",dic[i],t);
        if(t>mx)
        {
            mx=t;
            mxi=i;
            
        }
    }
   /// printf("----\n");
    return dic[mxi];
}
int main()
{
       int cas, t,i;
       freopen("B-small-attempt0.in", "r", stdin);
      freopen("bout.txt", "w", stdout);
       scanf("%d", &t);
       for (cas = 1; cas <= t; cas++)
       {
            reader();
            printf("Case #%d:", cas);
            for(i=0;i<g_m;i++)
            {
                printf(" %s",solver(arr[i]));
            }
            printf("\n");
       }
       return 0;
}


