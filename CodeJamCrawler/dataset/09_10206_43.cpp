#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char code[]="welcome to code jam";
    char ip[505];
    int stri[20];
    int count,n,num=1;
    cin>>n;
    ip[0]=getchar();
    while(num<=n){
        cin.getline(ip,501,'\n');
        for(int i=0;i<20;i++)stri[i]=0;
        for(int i=0;ip[i]!='\0';i++)
        if(ip[i]=='w')stri[0]++;
        else
            for(int j=1;j<19;j++)
                if(code[j]==ip[i])
                    stri[j]=(stri[j]+stri[j-1])%1000;
        count= stri[18];
        printf("Case #%d: %04d\n",num,count);
        num++;
    }
    return 0;
}

