#include<stdio.h>

int T, R;
int arr[5][5];
int v[20];

int main() {
  freopen("A.txt","r",stdin);
  freopen("A.out","w",stdout);
  
  scanf("%d",&T);
  for (int tc=0; tc<T; tc++) {
    for (int i=0; i<20; i++) v[i] = 0;
    
    scanf("%d",&R);
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) {
      scanf("%d",&arr[i][j]);
      if (i==R-1) v[arr[i][j]]++;
    }
    scanf("%d",&R);
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) {
      scanf("%d",&arr[i][j]);
      if (i==R-1) v[arr[i][j]]++;
    }
    
    int ans=0, ct=0;
    for (int i=0; i<20; i++) {
      if (v[i]==2) {ans=i; ct++;}
    }
    printf("Case #%d: ",tc+1);
    if (ct==0) puts("Volunteer cheated!");
    else if (ct==1) printf("%d\n",ans);
    else puts("Bad magician!");
  }
  return 0;
}
