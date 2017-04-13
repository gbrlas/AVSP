#include <stdio.h>

int col[300];
int rank[300];
int nseq;

int calc() {
  int totaltime=0, i;
  int time[2], pos[2];
  int C, D, D2, inf, sup;
  time[0]=time[1]=0;
  pos[0]=pos[1]=1;
  for(i=0; i<nseq; i++) {
    C=col[i];
    inf=pos[C]-time[C];
    sup=pos[C]+time[C];
    //printf("%d→%d %d,%d\n", pos[C], rank[i], inf, sup);
    if(rank[i]<inf || sup<rank[i]) {
      D=abs(rank[i]-pos[C]-time[C]);
      D2=abs(rank[i]-pos[C]+time[C]);
      if(D2<D) D=D2;
      totaltime+=D;
      time[C]+=D;
      time[1-C]+=D;
    }
    totaltime++;
    pos[C]=rank[i];
    time[C]=0;
    time[1-C]++;
  }
  return totaltime;
}

int main() {
  int cas, ncases, i, r;
  char str[20];
  scanf("%d", &ncases);
  for(cas=1; cas<=ncases; ++cas) {
    scanf("%d", &nseq);
    for(i=0; i<nseq; ++i) {
      scanf("%s", str);
      scanf("%d", rank+i);
      if(str[0]=='O' || str[1]=='O')
        col[i]=0;
      else
        col[i]=1;
    }
    printf("Case #%d: %d\n", cas, calc());
  }
  
  
  return 0;
}
