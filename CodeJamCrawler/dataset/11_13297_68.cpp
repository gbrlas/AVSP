#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define maxn 100000
#define eps 1e-5

struct point{
  double s1,s2;
  double len;
}p[maxn];


int i,j,n,m;

double X,S,R,t;

bool cmp(point a,point b){
  return (1/a.s1-1/a.s2)/(1/a.s2)>(1/b.s1-1/b.s2)/(1/b.s2);
  //  return (1/a.s1-1/a.s2)/(1/a.s1)>(1/b.s1-1/b.s2)/(1/b.s1);
}

int main(){
  int ii,nn;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%lf %lf %lf %lf %d",&X,&S,&R,&t,&n);
    m=0;
    double last=0,a,b,c;
    for(i=1;i<=n;i++){
      scanf("%lf %lf %lf",&a,&b,&c);
      if(a>last+eps){
	m++;
	p[m].s1=S;
	p[m].s2=R;
	p[m].len=a-last;
      }
      m++;
      p[m].s1=S+c;
      p[m].s2=R+c;
      p[m].len=b-a;
      last=b;
    }
    if(X>last+eps){
      m++;
      p[m].s1=S;
      p[m].s2=R;
      p[m].len=X-last;
    }
    sort(&p[1],&p[m+1],cmp);
    double ans=0;
    for(i=1;i<=m;i++){
      if(t>0){
	a=p[i].len/(p[i].s2);
	if(t<a)
	  a=t;
	ans+=a;
	t-=a;
	p[i].len-=a*p[i].s2;
      }
      ans+=p[i].len/p[i].s1;
      
    }
    printf("%.9lf\n",ans);
  }
  return 0;
}
