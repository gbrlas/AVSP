#include <iostream>

using namespace std;

int main(){
    
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    
    char s[20] = {"welcome to code jam"};
    
    int Testcase;
    
    scanf("%d", &Testcase);
    
    getchar();
    
    char tmp[501];
    
    int num[20];
    
    for( int testcase = 1; testcase <= Testcase; testcase++ ){
         gets( tmp );
         
         for( int i = 0; i < 19; i++ ){
              num[i] = 0;
         }
         int len = strlen( tmp );
//         cout<<tmp<<endl;
         for( int i = 0; i < len; i++ ){
              for( int j = 0; j < 19; j++ ){
                   if( tmp[i] == s[j] ){
                       if( j == 0 ){
                           num[0]++;
                       }
                       else{
                            num[j] = ( num[j] + num[j - 1] ) % 10000;
                       }
                   }
              }
              
//              for( int j = 0; j < 19; j++ ){
//                   cout<<"j="<<j<<" "<<num[j]<<endl;
//              }
         }
         
         printf("Case #%d: ",testcase );
         
         if( num[18] < 10 ){
             printf("000");
         }
         else if( num[18] < 100 ){
              printf("00");
         }
         else if( num[18] < 1000 ){
              printf("0");
         }
         
         printf("%d\n", num[18] );
    }
    
    return 0;
}
         
         
