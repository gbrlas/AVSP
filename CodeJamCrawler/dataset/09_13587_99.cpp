#include <iostream>
using namespace std;

int main () {

  int N;
  char buf[501];
  int count[500][19];
  scanf("%d\n", &N);
  for (int c = 1; c <= N; ++c) {
    cin.getline(buf, 501);
    //printf("%s\n", buf);
    int len = strlen(buf);
    for (int i = 0; i < len; ++i)
      for (int j = 0; j < 19; ++j)
	count[i][j] = 0;
    for (int i = 0; i < len; ++i) {
      if (i)
	for (int j = 0; j < 19; ++j)
	  count[i][j] = count[i-1][j];
      switch (buf[i]) {
      case 'w': ++count[i][0]; break;
      case 'e':
	count[i][1] = (count[i][1]+count[i][0])%10000;
	count[i][6] = (count[i][6]+count[i][5])%10000;
	count[i][14] = (count[i][14]+count[i][13])%10000;
	break;
      case 'l': count[i][2] = (count[i][2]+count[i][1])%10000; break;
      case 'c':
	count[i][3] = (count[i][3]+count[i][2])%10000;
	count[i][11] = (count[i][11]+count[i][10])%10000;
	break;
      case 'o':
	count[i][4] = (count[i][4]+count[i][3])%10000;
	count[i][9] = (count[i][9]+count[i][8])%10000;
	count[i][12] = (count[i][12]+count[i][11])%10000;
	break;
      case 'm':
	count[i][5] = (count[i][5]+count[i][4])%10000;
	count[i][18] = (count[i][18]+count[i][17])%10000;
	break;
      case ' ':
	count[i][7] = (count[i][7]+count[i][6])%10000;
	count[i][10] = (count[i][10]+count[i][9])%10000;
	count[i][15] = (count[i][15]+count[i][14])%10000;
	break;
      case 't': count[i][8] = (count[i][8]+count[i][7])%10000; break;
      case 'd': count[i][13] = (count[i][13]+count[i][12])%10000; break;
      case 'j': count[i][16] = (count[i][16]+count[i][15])%10000; break;
      case 'a': count[i][17] = (count[i][17]+count[i][16])%10000; break;
      }
    }
    //0123456789abcdefghi
    //welcome to code jam
    /*
    for (int i = 0; i < 19; ++i) {
      for (int j = 0; j < len; ++j)
	printf("%4d ", count[j][i]);
      printf("\n");
    }
    */
    printf("Case #%d: %04d\n", c, count[len-1][18]);
  }
}
