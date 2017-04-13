#include <cstdio>
#include <cstdlib>
#include <cstring>
#define WL 19
#define MAX 512

int main(void) {
  char hippie[] = "welcome to code jam";

  int n;
  scanf(" %d",&n);
  for(int c=1;c<=n;c++) {
    char str[MAX];
    int stpos[WL];
    int formo[WL+1][MAX];
    memset(formo,0,MAX*(WL+1)*sizeof(int));

    scanf(" %[^\n]",str);
    int l = strlen(str);
    
    for(int i=0,p=0;i<l && p<WL;i++) {
      if(str[i] == hippie[p]) 
	stpos[p++] = i;
    }

    for(int i=0;i<l;i++) formo[WL][i] = 1;

    for(int p=WL-1;p>=0;p--) {
      int nm = 0;
      for(int i=l-1;i>=0;i--) {
	formo[p][i] = formo[p][i+1];
	if(str[i] == hippie[p] && i >= stpos[p]) {
	  formo[p][i] += formo[p+1][i]; 
	  formo[p][i] %= 10000;
	}
      }
    }
    
    
    int result = formo[0][0];
    printf("Case #%d: %04d\n",c,result);
    
  }
  return(0);
}
