#include<stdio.h>
main(){
 
 int T,t=1,n,k,p=1,s,r,i;
 FILE *fin=freopen("A-small-attempt0.in","r",stdin);
 FILE *fout=freopen("out.txt","w",stdout);
 scanf("%d",&T);
 while(t<=T)
 {
  scanf("%d%d",&n,&k);
  printf("Case #%d: ",t);
  s=r=0;
  p=1;
  for(i=0;i<n;i++,p*=2)
   s+=p;
  if( k==s || k%(s+1)==s )
   r=1;
  if(r==0)
   printf("OFF\n");
  else
   printf("ON\n");
   t++;
 }
 return 0;
}
