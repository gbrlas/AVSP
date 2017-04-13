#include <stdio.h>

int main(){
  char c;
  int n, i, j, ns, nq, melhor, p;
  int dini, dini2, switches;
  int s[100], q[1000];
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &ns);
    c=getchar();
    for(j=0;j<ns;j++){
      s[j]=0;
      p=1;
      while((c=getchar())!='\n'){
	s[j]=s[j]+(c*c)*(p++);
      }
    }
    scanf("%d", &nq);
    c=getchar();
    for(j=0;j<nq;j++){
      q[j]=0;
      p=1;
      while((c=getchar())!='\n'){
	q[j]=q[j]+(c*c)*(p++);
      }
    }


    for(dini=0, switches=0; dini<nq; switches++){
      melhor=-1;
      for(j=0, dini2=dini;j<ns && dini2<nq; j++, dini2=dini){
	if(s[j]==q[dini2]) continue;
	while(s[j]!=q[dini2] && dini2<nq) dini2++;
	if(melhor==-1) melhor=dini2;
	if(melhor<dini2) melhor=dini2;
      }
      dini=melhor;
    }

    if(switches==0) switches++;
    printf("Case #%d: %d\n", i+1, switches-1);
  }
  return 0;
}
