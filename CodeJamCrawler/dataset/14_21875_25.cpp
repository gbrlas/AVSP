#include<cstdio>
#include<cstdlib>

using namespace std;
int a[30],r,n;
int main(){
  int i,j,k,t;
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("a.out","w",stdout);
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
      scanf("%d",&r);
      for( j = 1 ; j < 5 ; j++ )
        for( k = 1 ; k < 5 ; k++ ){
          scanf("%d",&t);
          if( j == r )
            a[t]++;
        }
      scanf("%d",&r);
      for( j = 1 ; j < 5 ; j++ )
        for( k = 1 ; k < 5 ; k++ ){
          scanf("%d",&t);
          if( j == r )
            a[t]++;
        }
      for( j = 1 , r = 0 ; j < 17 ; j++ ){
        if( a[j] == 2 ){
          if( r == 0 )
            r = j;
          else
            r = -1;
        }
        a[j] = 0;
      }
     printf("Case #%d: ",i);
     if( r == 0 )
       printf("Volunteer cheated!\n");
     else if( r == -1 )
       printf("Bad magician!\n");
     else
       printf("%d\n",r);

    }
   fclose (stdout);
  return 0;
}
