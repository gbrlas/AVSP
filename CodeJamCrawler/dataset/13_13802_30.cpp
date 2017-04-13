#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b-small.txt","w",stdout);
    int cass,t,i,j,n,m,k;
    int arr[10][10];
    scanf("%d",&t);
    for(i=1;i<=t;++i){
    cass=1;
    int Ar[10]={0},tab[10]={0};
    scanf("%d %d",&n,&m);
    for(j=0;j<n;++j){
    for(k=0;k<m;++k){
    scanf("%d",&arr[j][k]);
    if(arr[j][k]==1)
    Ar[j]++;
    }
    }
    for(j=0;j<m;++j){
    for(k=0;k<n;++k){
    if(arr[k][j]==1)
    tab[j]++;
    }
}
    for(j=0;j<n;++j){
    if(Ar[j]!=m && Ar[j]!=0){
    for(k=0;k<m;++k){
    if(arr[j][k]==1 && tab[k]!=n){
    cass=0;
    break;
    }
    }
    }
    }
    if(cass)
    printf("Case #%d: YES\n",i);
    else
    printf("Case #%d: NO\n",i);
        }
return 0;
}
