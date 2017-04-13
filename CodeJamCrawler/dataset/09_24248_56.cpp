#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    freopen( "B-large.in", "r", stdin );
    freopen( "B-large.out", "w", stdout );
    int l,Cas1,Cas=0,a1,a2,i,j,c;
    char st[100];
    scanf("%d",&Cas1);
    while( Cas++<Cas1 )
    {
       scanf("%s",&st);
       l=strlen(st);
       a1=0;a2=0;
       for( i=l-2 ; i>=0 ; i-- )
       {
           a2=0;
           for( j=i+1 ; j<l ; j++ )
            if( st[j]>st[i] )
             if( st[j]<st[a2]||a2==0 ) 
               a2=j;
           if( a2 ) {a1=i;break;}          
       }
       printf("Case #%d: ",Cas);
       if( a2 )
       {
          for( i=0 ; i<a1 ; i++ )
            printf("%c",st[i]);
          printf("%c",st[a2]);
          st[a2]='9'+1;
          for( i=a1 ; i<l-1 ; i++ ) 
          {
             c=a2;
             for( j=a1 ; j<l ; j++ )
              if( st[j]<st[c] ) c=j;
             printf("%c",st[c]);
             st[c]='9'+1;
          }           
          printf("\n");
       }else 
       {
           for( i=l-1 ; i>-1 ; i-- )
            if( st[i]!='0' ) { printf("%c0",st[i]);st[i]='*';break;}
           for( i=l-1 ; i>-1 ; i-- )
            if( st[i]!='*' ) printf("%c",st[i]);
           printf("\n");
       }
    }
    return(0);
}
