#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

int n,k;
char tab[55][55],ntab[55][55],ltab[55][55];
int v[55];
bool r_w,b_w;

void go(int l ,  int c){
    for(int j = l; j >= 1; j--){
        ntab[j][c] = ntab[j - 1][c];
    }
    for(int j = 0; j >= 0; j--){
        ntab[j][c] = '.';
    }
}

void process(){
    int u;
    for(int i = 0; i < n; i++){
        u = 0;
        v[i] = n-1;
        for(int j = n-1; j >= 0; j--){
            if(tab[i][j] != '.'){
                v[i] = u;
                //printf("v[%d] = %d\n",i,u);
                break;
                }
            u++;
        }
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ntab[i][j] = tab[n-1 - j][i];
        }
        ntab[i][n] = '\n';
        //printf(">>%s",ntab[i]);
        //printf("acabou");
    }
    /*
    printf("\n");
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%c",ntab[i][j]);
        printf("\n");
    }
    
     printf("\n");
     
    */
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if( ntab[j-1][i] != '.' && ntab[j][i] == '.') go(j,i); 
        }
    }
    
    //printf("%d\n",k);
    
    //for(int i = 0; i < n; i++){
       // for(int j = 0; j < n; j++) printf("%c",ntab[i][j]);
      //  printf("\n");
    //}
    
    // printf("\n");
     /*
    */ 
    /* 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%c",ltab[i][j]);
        printf("\n");
    }
    printf("\n");
    */
}

void lookfor(){
    int r = 0,b = 0;
    r_w = b_w = false;
    int l,c;
    for(int i = 0; i < n; i++){
        r = b = 0;
        for(int j = 0; j < n; j++){
            if(ntab[i][j] == 'R'){
                r++;
                b = 0;
            }
            else if(ntab[i][j] == 'B'){
                b++;
                r = 0;
            }
            else{
                r = 0;
                b = 0;
            }
            if(r == k) r_w = true;
            if(b == k) b_w = true;
        }
    }
    
    r = 0;
    b = 0;
    
    for(int j = 0; j < n ; j++){
        r = b = 0;
        for(int i = 0; i < n; i++){
            if(ntab[i][j] == 'R'){
                r++;
                b = 0;
            }
            else if(ntab[i][j] == 'B'){
                b++;
                r = 0;
            }
            else{
                r = 0;
                b = 0;
            }
            if(r == k){
                //printf("R W 2  , l = %d, c = %d, \n",i,j);
                r_w = true;
            }
            if(b == k){
                //printf("B W 2  , l = %d, c = %d, \n",i,j);
                b_w = true;
            }                  
        }
    }
    
  
    int p;
    for(int i = 0; i < n ; i++) for(int j = 0; j < n ; j++){
        l = i;
        c = j;
        p = 0;
          r = b = 0;
        while( 0 <= l + p && l + p < n && 0 <= c + p && c + p < n ){
            
            if(ntab[l + p][c + p] == 'R'){
                r++;
                b = 0;
            }
            else if(ntab[l + p][c + p] == 'B'){
                b++;
                r = 0;
            }
            else{
                r = 0;
                b = 0;
            }
            if(r == k){
                //printf("R W 3  , l = %d, c = %d, p = %d\n",l,c,p);
                r_w = true;
            }
            if(b == k){
                //printf("B W 3  , l = %d, c = %d, p = %d\n",l,c,p);
                b_w = true;
            }          
            p++;
        }
    }
    
    for(int i = 0; i < n ; i++) for(int j = 0; j < n; j++){
        l = i;
        c = j;
        p = 0;
          r = b = 0;
        while( 0 <= l + p && l + p < n && 0 <= c - p && c - p < n ){
            
            if(ntab[l + p][c - p] == 'R'){
                r++;
                b = 0;
            }
            else if(ntab[l + p][c - p] == 'B'){
                b++;
                r = 0;
            }
            else{
                r = 0;
                b = 0;
            }
            if(r == k){
                //printf("R W 4  , l = %d, c = %d, p = %d\n",l,c,p);
                r_w = true;
            }
            if(b == k){
                //printf("B W 4  , l = %d, c = %d, p = %d\n",l,c,p);
                b_w = true;
            }       
            p++;
        }
    }
    
}

int main(){
    int t;
    freopen("A-small-attempt2.in","r",stdin);
    freopen("saida.txt","w",stdout);
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d %d",&n,&k);
        memset(ntab,'\n',sizeof(ntab));
        
        for(int j = 0; j < n; j++){
            scanf("%s",tab[j]);
            //printf("%s\n",tab[j]);
        }
        
        process();
        lookfor();
        if(r_w && b_w) printf("Case #%d: Both\n",i+1);
        else if(r_w) printf("Case #%d: Red\n",i+1);
        else if(b_w) printf("Case #%d: Blue\n",i+1);
        else printf("Case #%d: Neither\n",i+1);
    }   
    return 0;
}
