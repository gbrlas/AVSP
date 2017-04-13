#include <cstdio>

int tc,t;
int i,j,k;
int n,m;
int res;
int a[20][20];
int b[20][20];
int flag;

void init(int n,int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            b[i][j] = 2;    
}

void trim(int direction,int pos){
    if(direction){ // across
        for(int j=0;j<m;j++)    
            b[pos][j] = 1;
    }else{ // down
        for(int i=0;i<n;i++)
            b[i][pos] = 1;    
    }
}

bool check(int direction,int pos){
    if(direction){
        for(int j=0;j<m;j++)    
            if(a[pos][j]!=1) return false;
        return true;
    } else {
        
        for(int i=0;i<n;i++)
            if(a[i][pos]!=1) {                
                return false;
            }    
        return true;
    }
    
}

bool verify(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)    
            if(a[i][j]!=b[i][j])
                return false;
    return true;
}

int main(){
    scanf("%d",&tc);
    for(t=1;t<=tc;t++){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
         init(n,m);
         for(i=0;i<n;i++)
             if(check(1,i))
                 trim(1,i);
         for(j=0;j<m;j++)
             if(check(0,j))
                 trim(0,j);
         res = verify();
         
         
        if(res)
            printf("Case #%d: YES\n",t);
        else
            printf("Case #%d: NO\n",t);
    
    }
    return 0;
}
