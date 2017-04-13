#include<stdio.h>

int n,small,sum,xsum,i,j;

int main(){
  int ii,nn;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%d",&n);
    xsum=sum=0;small=-1;
    while(n--){
      scanf("%d",&i);
      xsum^=i;
      sum+=i;
      if(small<0||i<small)
	small=i;
    }
    if(xsum)
      printf("NO\n");
    else{
      printf("%d\n",sum-small);
    }
  }
}
