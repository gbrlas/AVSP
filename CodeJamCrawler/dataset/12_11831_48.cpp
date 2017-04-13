#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxn 10000
#define maxint 1000000000

int p[maxn];

int q[maxn];

int i,j,n,m;


void make(int l,int r,int delta){

        if(l+1>=r)
                return;
        int i;
        delta++;
        for(i=r-1;i>l;i--){
                p[i]=p[i+1]-delta;
        }

        l++;
        while(l<r){
                make(l,q[l],delta);
                l=q[l];
        }
        
}

int main(){
        int ii,nn;
        scanf("%d",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d:",ii);
                scanf("%d",&n);
                for(i=1;i<n;i++){
                        scanf("%d",&q[i]);
                }
                bool o=false;
                for(i=1;i<n;i++){
                        for(j=i+1;j<q[i];j++){
                                if(q[j]>q[i])
                                        o=true;
                        }
                }
                if(o){
                        printf(" Impossible\n");
                        continue;
                }
                i=1;
                p[1]=maxint/2;
                while(i<n){
                        p[q[i]]=p[i];
                        make(i,q[i],0);
                        i=q[i];
                }
                for(i=1;i<=n;i++)
                        printf(" %d",p[i]);
                printf("\n");
        }
        return 0;
}
