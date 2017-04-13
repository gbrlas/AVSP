#include <cstdio>
#include <cstring>

int main()
{
    char string[101];
    int n;
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]%*c",string);
        int l = strlen(string);
        printf("Case #%d: ",i+1);
        for(int j=0;j<l;j++)
        {
            switch(string[j])
            {
                case 'z':
                    printf("q");
                break;
                case 'n':
                    printf("b");
                break;
                case 'f':
                    printf("c");
                break;
                case 'i':
                    printf("d");
                break;
                case 'c':
                    printf("e");
                break;
                case 'w':
                    printf("f");
                break;
                case 'l':
                    printf("g");
                break;
                case 'b':
                    printf("h");
                break;
                case 'k':
                    printf("i");
                break;
                case 'u':
                    printf("j");
                break;
                case 'o':
                    printf("k");
                break;
                case 'm':
                    printf("l");
                break;
                case 'x':
                    printf("m");
                break;
                case 's':
                    printf("n");
                break;
                case 'e':
                    printf("o");
                break;
                case 'v':
                    printf("p");
                break;
                case 'y':
                    printf("a");
                break;
                case 'p':
                    printf("r");
                break;
                case 'd':
                    printf("s");
                break;
                case 'r':
                    printf("t");
                break;
                case 'j':
                    printf("u");
                break;
                case 'g':
                    printf("v");
                break;
                case 't':
                    printf("w");
                break;
                case 'h':
                    printf("x");
                break;
                case 'a':
                    printf("y");
                break;
                case 'q':
                    printf("z");
                break;
                default:
                    printf(" ");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
