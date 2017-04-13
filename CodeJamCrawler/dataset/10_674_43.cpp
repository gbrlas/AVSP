#include<stdio.h>
long long m[10000],p;
main(){
 int i,ind,t=1,T,R,k,N,c,g[1001],end;
 FILE *fin=freopen("C-small-attempt1.in","r",stdin);
 FILE *fout=freopen("out-c.txt","w",stdout);
 scanf("%d",&T);
 while(t<=T)
 {
  scanf("%d%d%d",&R,&k,&N);
  for(i=0;i<N;i++)scanf("%d",&g[i]);
  printf("Case #%d: ",t);
  i=ind=c=p=0;
  do 
  {
    c=0;
    m[i]=p;
	end=(ind);
	while( c+g[ind]<=k )
	{
	 c+=g[ind];
	 ind=(ind+1)%N;
	 if(ind==end)break;
	}
	m[i]=p+c;
	p=m[i];
	i++;
	//printf("%d %d\n",i,ind);
  }while(i < R);
  //if( R < i )
   printf("%lld\n",m[i-1]);
  //else 
   //printf("%lld\n",m[i]*(R/i) + (R%i)*m[R%i]);
  t++;
 }
 return 0;
}
