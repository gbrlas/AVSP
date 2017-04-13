#include<stdio.h>

#define N 10

int main()
{
  int t,i,ans,max,min,n,j,k;
  double tmp,a[N],b[N];
  FILE *in,*out;

  in = fopen("./D-small-attempt0.in","r");
  out = fopen("./D-small-attempt0.out","w");

  fscanf(in,"%d",&t);
  for(i=1;i<=t;i++){
    max = 0;
    min = N;
    fscanf(in,"%d",&n);
    for(j=0;j<n;j++){
      fscanf(in,"%lf",&a[j]);
    }
    for(j=0;j<n;j++){
      fscanf(in,"%lf",&b[j]);
    }
    for(j=0;j<n;j++){
      for(k=j;k<n;k++){
	if(a[j]>a[k]){
	  tmp = a[j];
	  a[j] = a[k];
	  a[k] = tmp;
	}
	if(b[j]>b[k]){
	  tmp = b[j];
	  b[j] = b[k];
	  b[k] = tmp;
	}
      }
    }

    for(j=0;j<n;j++){
      ans =0;
      for(k=0;k<n;k++){
	if(a[(j+k)%n] > b[k]){
	  ans++;
	}
      }
      if(ans>max){
	max = ans;
      }
      if(ans<min){
	min = ans;
      }
    }

    fprintf(out,"Case #%d: %d %d\n",i,max,min);
  }

  return 0;
}
