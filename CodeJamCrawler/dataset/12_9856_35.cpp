#include <cstdio>
#define MAXLEN 101
#define DICT "yhesocvxduiglbkrztnwjpfmaq"
using namespace std;
void translate(char* str)
{
    for (char* p = str; *p; ++p)
    {
        if (*p >= 'a' && *p <= 'z') *p = DICT[*p - 'a'];
    }
}
int main()
{
    int T;
    scanf("%d\n", &T);
    for (int i = 0; i < T; ++i)
    {
        char str[MAXLEN + 1];
        fgets(str, MAXLEN + 1, stdin);
        translate(str);
        printf("Case #%d: %s", i + 1, str);
    }
    return 0;
}
