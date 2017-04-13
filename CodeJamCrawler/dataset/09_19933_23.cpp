#include "util.h"


int main ()
{
    int s32NumTests;
    int s32Test;
    char s8AZTimes[26];
    char s809Times[10];
    char s8Tmp[65];
    char s8Tra[65];
    long long s64Min;
    int s32NumChar;
    int i;
    int s32Base;
    char s8AZMap[26];
    char s809Map[10];
    int s32Inc;
    long long s64LastPow;

    scanf("%d\r\n", &s32NumTests);
    //printf("Num of test cases: %d\r\n", s32NumTests);

    for (s32Test=0; s32Test<s32NumTests; s32Test++)
    {
        gets(s8Tmp);
        memset(s8AZTimes, 0, 26);
        memset(s809Times, 0, 10);

        for (s32NumChar=0; ;s32NumChar++)            
        {
            if (s8Tmp[s32NumChar] == 0)
                break;            
            else if (isdigit(s8Tmp[s32NumChar]))
                s809Times[s8Tmp[s32NumChar]-'0'] = 1;
            else if (isalpha(s8Tmp[s32NumChar]))
                s8AZTimes[s8Tmp[s32NumChar]-'a'] = 1;
        }

        s32Base = 0;
        for (i=0; i<26; i++)
        {
            s32Base += s8AZTimes[i];
        }
        for (i=0; i<10; i++)
        {
            s32Base += s809Times[i];
        }
        if (s32Base == 1)
            s32Base = 2;

        memset(s8AZMap, -1, 26);
        memset(s809Map, -1, 10);
        if (isdigit(s8Tmp[0]))
        {
            s809Map[s8Tmp[0]-'0'] = 1;
            s8Tra[0] = 1;
        }
        else if (isalpha(s8Tmp[0]))
        {
            s8AZMap[s8Tmp[0]-'a'] = 1;        
            s8Tra[0] = 1;
        }

        s32Inc = 0;
        for (i=1; i<s32NumChar; i++)
        {
            if (isdigit(s8Tmp[i]))
            {
                if (s809Map[s8Tmp[i]-'0'] == -1)
                {
                    if (i==1)
                    {
                        s809Map[s8Tmp[i]-'0'] = 0;
                        s32Inc=2;
                    }
                    else
                    {
                        s809Map[s8Tmp[i]-'0'] = s32Inc++;      
                        if (s32Inc==1)
                            s32Inc++;
                    }
                }
                s8Tra[i] = s809Map[s8Tmp[i]-'0'];
            }
            else if (isalpha(s8Tmp[i]))
            {
                if (s8AZMap[s8Tmp[i]-'a'] == -1)
                {
                    if (i==1)
                    {
                        s8AZMap[s8Tmp[i]-'a'] = 0;
                        s32Inc=2;
                    }
                    else
                    {
                        s8AZMap[s8Tmp[i]-'a'] = s32Inc++;                   
                        if (s32Inc==1)
                            s32Inc++;
                    }

                }
                s8Tra[i] = s8AZMap[s8Tmp[i]-'a'];            
            }
        }

        s64LastPow = 1;
        s64Min = 0;
        for (i=s32NumChar-1; i>=0; i--)
        {
            s64Min += s64LastPow*s8Tra[i];
            s64LastPow *= ((long long)s32Base);
        }

        printf("Case #%d: %lld\r\n", s32Test+1, s64Min);
    }

    return 0;
}
