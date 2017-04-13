#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
#include<cstring>
//using namespace std;
char s[200];
int main()
{
    //FILE *fin=fopen("A.in","r");
    //FILE *fout=fopen("A.out","w");
    int n,k;
    n=0;
    //fprintf(fout,"aaa");
    freopen("AAAA.in","r",stdin);
    freopen("A.out","w",stdout);
    //fscanf(fin,"%d",&n);
    //cout << n;
    //for(;;);
    scanf("%d\n",&n);
    //fclose(stdout);
    //printf("%d",n);
    //for(;;);
    //cout << "0";
    //printf("%d",n);
    for(int i=0;i<n;i++)
    {
        gets(s);
        k=strlen(s);
        for(int j=0;j<k;j++)
        {
            if(s[j]=='a') s[j]='y';
            else if(s[j]=='b') s[j]='h';
            else if(s[j]=='c') s[j]='e';
            else if(s[j]=='d') s[j]='s';
            else if(s[j]=='e') s[j]='o';
            else if(s[j]=='f') s[j]='c';
            else if(s[j]=='g') s[j]='v';
            else if(s[j]=='h') s[j]='x';
            else if(s[j]=='i') s[j]='d';
            else if(s[j]=='j') s[j]='u';
            else if(s[j]=='k') s[j]='i';
            else if(s[j]=='l') s[j]='g';
            else if(s[j]=='m') s[j]='l';
            else if(s[j]=='n') s[j]='b';
            else if(s[j]=='o') s[j]='k';
            else if(s[j]=='p') s[j]='r';
            else if(s[j]=='q') s[j]='z';
            else if(s[j]=='r') s[j]='t';
            else if(s[j]=='s') s[j]='n';
            else if(s[j]=='t') s[j]='w';
            else if(s[j]=='u') s[j]='j';
            else if(s[j]=='v') s[j]='p';
            else if(s[j]=='w') s[j]='f';
            else if(s[j]=='x') s[j]='m';
            else if(s[j]=='y') s[j]='a';
            else if(s[j]=='z') s[j]='q';
        }
        printf("Case #%d: %s\n",i+1,s);
    }
    //fclose(fout);
    
    //fclose(stdout);
    
    //exit(0);
    return 0;
    
}
