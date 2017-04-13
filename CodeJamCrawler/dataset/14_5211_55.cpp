#include<stdio.h>

#define N 1000

void msort(double x[],int l,int r);

int main()
{
  int t,i,ans,max,min,n,j,k;
  double tmp,a[N],b[N];
  FILE *in,*out;

  in = fopen("./D-large.in","r");
  out = fopen("./D-large.out","w");

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
    msort(a,0,n-1);
    msort(b,0,n-1);

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

void msort(double x[],int l,int r)
{
  int m,i,j,k;
  double tmp[N];

  if(l>=r)
    return;

  m = (l+r)/2;
  msort(x,l,m);
  msort(x,m+1,r);

  for(i=l;i<=m;i++){
    tmp[i] = x[i];
  }
  for(i=m+1;i<=r;i++){
    tmp[r+m+1-i] = x[i];
  }

  i=l;
  j=r;
  for(k=l;k<=r;k++){
    if(tmp[i]<tmp[j]){
      x[k]=tmp[i++];
    }else{
      x[k]=tmp[j--];
    }
  }
}
