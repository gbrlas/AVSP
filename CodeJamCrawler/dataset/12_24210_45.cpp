#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int exist(int n,int *A, int len)
{
    int Ans=0,i;
    for(i=0;i<len;i++)
    if(A[i]==n)
    Ans=1;
    return Ans;
}


int esp (int n)
{
    int i;
    for(i=1;n/(10*i)>0;i=i*10);
    return i;
}

int Num(int n,int exp,int A,int B)
{
    int copy=n,copyexp,anS=0;
    int *V;
    V=malloc(exp*sizeof(int));
    for(copyexp=1;copyexp<exp;copyexp=copyexp*10)
    {
                                                 copy=(copy%10)*exp+copy/10;
                                                 if(copy>n&&copy>=A&&copy<=B)
                                                 {
                                                     if(!exist(copy,V,anS))
                                                     {                   
                                                     V[anS]=copy;
                                                     anS++;
                                                     }
                                                 }
    }
    free(V);
    return anS;
                                                 
}

int main()
{
    int T,i;
    
    FILE *x;
    FILE *y;
    x=fopen("input.in","r");
    y=fopen("output.txt","w");
    fscanf(x,"%d",&T);
    for(i=0;i<T;i++)
    {
                    int A,B,j,ans=0,exp;
                    fprintf(y,"Case #%d: ",i+1);
                    fscanf(x,"%d",&A);
                    fscanf(x,"%d",&B);
                    exp=esp(A);
                    
                    for(j=A;j<=B;j++)
                    {
                                    ans=ans+Num(j,exp,A,B);
                    }
                    fprintf(y,"%d\n",ans);
                    
    }
    return 0;
}
