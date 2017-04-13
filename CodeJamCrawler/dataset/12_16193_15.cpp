#include<iostream>
using namespace std;
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    int n,i,j;
    char str[1000];
    char arr[]={
         'y',
         'h',
         'e',
         's',
         'o',
         'c',
         'v',
         'x',
         'd',
         'u',
         'i',
         'g',
         'l',
         'b',
         'k',
         'r',
         'z',
         't',
         'n',
         'w',
         'j',
         'p',
         'f',
         'm',
         'a',
         'q'
    };
    scanf("%d",&n);
    fflush(stdin);
    for(i=0; i<n; i++ ) {
               gets(str);             
               for( j=0; str[j]; j++ )
               {
                    if( str[j]!=' ' )
                        str[j]=arr[str[j]-'a'];
               }
               printf("Case #%d: %s",i+1,str);
               if(i!=n-1)
                   printf("\n");
    }       
      
}
