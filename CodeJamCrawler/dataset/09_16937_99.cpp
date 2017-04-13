#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(void) {
  bool w[16][32];
  char dict[5000][16];
  int l,d,n;
  scanf(" %d %d %d", &l,&d,&n);
  for(int i=0;i<d;i++) {
    scanf(" %s",dict[i]);
  }
  for(int c=1;c<=n;c++) {
    memset(w,0,sizeof(w));

    for(int i=0;i<l;i++) {
      char ch;
      scanf(" %c",&ch);
      if (ch == '(') {
	scanf("%c",&ch);
	do {
	  w[i][ch-'a'] = true;
	  scanf("%c",&ch);
	} while(ch != ')');
      }
      else w[i][ch-'a'] = true;
    }
    int chance = 0;
    for(int i=0;i<d;i++) {
      bool is = true;
      for(int j=0;j<l && is;j++) {
	is &= w[j][dict[i][j]-'a'];
      }
      if (is) chance++;
    }
    printf("Case #%d: %d\n",c,chance);
  }
  return(0);
}
