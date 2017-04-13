#include <stdio.h>
#include <math.h>

int main(){
	double t[9000]={}, c,gg[100]={}, f, x;
	int n,i,j,k=0;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{scanf("%lf%lf%lf",&c,&f,&x);
	for (k=0;k<3001;k++)
	{t[k]=x/(2.0+k*f);
	for (j=0;j<k; j++)
	{t[k]+=c/(2.0+j*f);}}
	gg[i]=t[0];
	for (k=1;k<3001;k++)
	{if (gg[i]>t[k]) gg[i]=t[k];}}
	for (i=1; i<=n; i++)
	{printf("Case #%d: %.7f\n",i,gg[i]);}


	anykey();
	return 0;
}
