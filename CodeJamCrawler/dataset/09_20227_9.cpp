#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<sstream>
#define oo (int)1e9
using namespace std;
int no;
char s[25];

main()
{
      freopen("B-small-attempt1.in","r",stdin);
      freopen("bo.txt","w",stdout);
      int t;
      scanf("%d\n",&t) ;
      for(int cs=1;cs<=t;cs++)
      {
              scanf("%s",&s);
              
              int n = strlen(s);

              bool pre=0;
              while( next_permutation(s,s+n) )
              {
                     pre=1;
                     break;
              }
              
              if(!pre)
              {
                      sort(s,s+n);
                      //n++;
                      do
                      {
                          if(s[0]!='0')break;
                      }while( next_permutation(s,s+n) );
                      
              }
              printf("Case #%d: ",cs);
              if(pre)
              {
               for(int i=0;i<n;i++)printf("%c",s[i]);
              }
              else
              {
                  printf("%c%c",s[0],'0');
                  for(int i=1;i<n;i++)printf("%c",s[i]);
              }
              printf("\n");
              
      }
}
