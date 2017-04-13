#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<functional>
using namespace std;
char num[300],num2[300],tmp,minval=100;
int len,T,N;
main()
{
    int i,j,k,z,done,minpos;
    scanf("%d",&T);
    for(z=0;z<T;z++)
    {

        done=0;
        scanf("%s",num);
        len=strlen(num);
        strcpy(num2,num);
        sort(num2,num2+len,greater<int>());
        if(strcmp(num2,num)==0)
        {
            sort(num2,num2+len,less<int>());
            //printf("%s\n",num2);
            printf("Case #%d: ",z+1);
            for(i=0;i<len;i++){ if(num2[i]>'0'){ printf("%c0",num2[i]); for(j=0;j<i;j++)printf("%c",num2[j]); for(j=i+1;j<len;j++)printf("%c",num2[j]); printf("\n"); done=1; break; } }
        }
        strcpy(num2,num);
        if(done==0)
        {
        for(k=len-2;k>=0;k--)
        {
            minval=100;

            for(i=k+1;i<len;i++)
            {
                //printf("num2[%d]%c num2[%d]%c\n",k,num2[k],i,num2[i]);
                if(num2[i]>num2[k]){  if(num2[i]<minval){ minval=num2[i]; minpos=i; } }
            }
            //printf("%s\n",num2);
            if(minval<100)
            {
            tmp=num2[k];
            num2[k]=num2[minpos];
            num2[minpos]=tmp;
            sort(num2+k+1,num2+len);
            printf("Case #%d: %s\n",z+1,num2);
            done=1;
            }

            if(done==1)break;
        }
        }

    }


}
