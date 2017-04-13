#include<stdio.h>

int main()
{
  int i,t;
  double c,f,x,p,ans;
  FILE *in,*out;

  in = fopen("./B-small-attempt0.in","r");
  out = fopen("./GCJ2014-B.out","w");

  fscanf(in,"%d",&t);
  for(i=0;i<t;i++){
    fscanf(in,"%lf %lf %lf",&c,&f,&x);
    p = 2.0;
    ans = 0.0;
    while(1){
      if(x/p > (c/p+x/(p+f))){
	ans += c/p;
	p += f;
      }else{
	ans += x/p;
	break;
      }
    }
    fprintf(out,"Case #%d: %f\n",i+1,ans);
  }
  
  return 0;
}
