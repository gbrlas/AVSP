#include<cstdio>
#include<cstdlib>
int c,n,ni,i;
int main(){
  int r,s,a,min,p;
 scanf("%d",&n);
 c=1;
 while(c<=n){
   r=s=0;
   min=10000000;
   scanf("%d",&ni);
   for(i=0;i<ni;i++){
     scanf("%d",&p);
    r=r^p;
    s+=p;
    if(p<min)
     min=p; 
        
    }
    if(r==0)
      printf("Case #%d: %d\n",c,s-min);
    else
      printf("Case #%d: NO\n",c);
    c++;  
 }
 return 0;
}
