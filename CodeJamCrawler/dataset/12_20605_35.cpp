#include<stdio.h>
int a[5][40];
int main(){
  int i,n,s,p,t,c,v,b;
    v=1;
    a[1][0]=a[2][0]=0;
    for(i=1;i<=30;i++){
      a[1][i]=v;
      if(i%3==0) v++;
    }
    v=2;
    for(i=2;i<=28;i++){
      a[2][i]=v;
      if((i+2)%3==0) v++;
    }
    scanf("%d",&t);
    b=1;
    while(b<=t){
      scanf("%d%d%d",&n,&s,&p);
      v=0;
      for(i=0;i<n;i++){
        scanf("%d",&c);
        if(a[1][c]>=p) v++;
        else if(s>0){
          if(a[2][c]>=p){
            v++;
            s--;
          }
        }
      }
      printf("Case #%d: %d\n",b,v);
      b++;
    }
  return 0;
}
