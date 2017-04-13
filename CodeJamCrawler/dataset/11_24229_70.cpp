#include<iostream>
#include<stdio.h>
using namespace std;
int indexc;
char arr[110];
int joi[180][180];
int des[180][180];

int str(char ch)
{
    return (ch);
}

int checkcombine( char ch )
{
    if(indexc==0)
    {
        arr[indexc] = ch;
        indexc++;
        return 0;
    }
    char lastch = arr[indexc - 1];
    if( joi[ str(ch) ][ str(lastch) ] != -1 ){
        arr[indexc-1] = str(joi[ str(ch) ][ str(lastch) ]) ;
    }
    else{
        arr[indexc] = ch;
        indexc++;
    }
}

int breakqueue()
{
    int i;
    char ch = arr[indexc-1];
    for( i=0; i < indexc - 1; i++ ){
        if( des[ str(ch) ][ str(arr[i]) ] == 1 ){
            indexc = 0;
        }
    }
}

int main()
{
    int test;
    int i,j,o,r,m;
    char ch1,ch2,ch3,ch;
    FILE *fp,*fout;
    fp   = fopen("input","r");
    fout = fopen("output","w");
    fscanf(fp,"%d",&test);
    for(i=0;i<test;i++)
    {
        indexc = 0;
        for(o=0;o<150;o++)
        {
            for(r=0;r<150;r++)
            {
                joi[o][r] = -1;
                des[o][r] = 0;
            }
        }
        fscanf(fp,"%d",&m);
        for( j=0; j<m ;j++ )
        {
            fscanf(fp," %c%c%c ",&ch1,&ch2,&ch3);
            joi[ str(ch1) ][ str(ch2) ] = str(ch3) ;
            joi[ str(ch2) ][ str(ch1) ] = str(ch3) ;
        }
        fscanf(fp,"%d",&m);
        for( j=0; j<m ; j++ )
        {
            fscanf(fp," %c%c ",&ch1,&ch2);
            des[ str(ch1) ][ str(ch2) ] = 1;
            des[ str(ch2) ][ str(ch1) ] = 1;
        }
        fscanf(fp,"%d",&m);
        char stri[110];
        fscanf(fp,"%s",stri);
        for(j=0;j<m;j++)
        {
            ch = stri[j];
            checkcombine(ch);
            breakqueue();
        }
        fprintf(fout,"Case #%d: [",i+1);
        for(j=0;j<indexc;j++)
        {
            if( j == indexc -1 )
            {
                fprintf(fout,"%c",arr[j]);
            }
            else{
                fprintf(fout,"%c, ",arr[j]);
            }
        }
        fprintf(fout,"]\n");
    }
}
