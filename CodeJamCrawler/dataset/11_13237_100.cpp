#include<stdio.h>
#include<string.h>
#define maxn 200
int i,j,n,m;

int p[maxn];
bool blue[maxn];

void refresh(int& a,bool b){
  while(a<=n&&blue[a]!=b)
    a++;
}

void moveTo(int& a,int b){
  if(b>n||a==p[b])
    return;
  a+=(a<p[b]?1:-1);
}

void make(){
  int b=1,o=1,nextB=1,nextO=1,ans=0,i=1;
  refresh(nextB,1);
  refresh(nextO,0);
  while(i<=n){
    ans++;
    if(i==nextB){
      moveTo(o,nextO);
      if(b==p[i]){
	i++;
	nextB++;
	refresh(nextB,1);
      }else
	moveTo(b,nextB);
    }else{
      moveTo(b,nextB);
      if(o==p[i]){
	i++;
	nextO++;
	refresh(nextO,0);
      }else
	moveTo(o,nextO);
    }
  }
  printf("%d\n",ans);
}


int main(){
  int ii,nn;
  char a;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf(" %c %d",&a,&p[i]);
      blue[i]=(a=='B');
    }
    make();
  }
  return 0;
}
