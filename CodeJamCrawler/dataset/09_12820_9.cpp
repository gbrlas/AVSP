#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int com (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

int main(){
    char s[22], c;
    int n,i, l, j, k, done, small;
    scanf(" %d ", &n);
    for(i=0;i<n;i++){
        done=0;
        fgets(s, 22, stdin);
        l=strlen(s);
        if(s[l-1]=='\n')
            s[--l]='\0';
        for(j=l-2;j>=0 && !done;j--)
        {
            small=0;
            for(k=j+1;k<l && !done;k++)
            {
                if(s[j]<s[k] && (small==0 || s[k]<s[small]) )
                        small=k;
            }
            if(small!=0)
            {
                c=s[j];s[j]=s[small];s[small]=c;
                qsort(s+j+1, l-j-1, sizeof(char), com);
                done=1;
            }
        }
        if(done==0)
        {
            s[l++]='0';
            s[l]='\0';
            qsort(s, l-1, sizeof(char), com);
        }
        if(s[0]=='0')
        {
            for(j=0;j<l;j++)
            {
                if(s[j]!='0')
                {s[0]=s[j];s[j]='0';break;}
            }
        }
        printf("Case #%d: %s\n", i+1,s);
    }
    return 0;
}
