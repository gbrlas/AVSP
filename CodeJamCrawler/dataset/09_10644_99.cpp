#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1024;
const int SZ = 32;

const char *str = "welcome to code jam";
char buff[MAX];
int val[MAX][SZ];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  int sz = strlen(str);
  scanf("%d", &n);
  fgets(buff, MAX, stdin);
  for (int t = 0; t < n; ++ t)
  {
    memset(val, 0, sizeof(val));
    val[0][0] = 1;
    fgets(buff, MAX, stdin);
    int len = strlen(buff);
    for (int i = 1; i <= len; ++ i)
    {
      for (int j = 1; j <= sz; ++ j)
        if (buff[i - 1] == str[j - 1])
          val[i][j] += val[i - 1][j - 1];
      for (int j = 0; j < SZ; ++ j)
        val[i][j] = (val[i][j] + val[i - 1][j]) % 10000;
    }
    printf("Case #%d: %04d\n", t + 1, val[len][sz]);
  }
  return 0;
}
