#include <stdio.h>
#include <string.h>

#include <algorithm>
using std :: rotate;

inline bool is_sim (int a, int b)
{
    char s1[15], s2[15];
    s1[0] = '\0';
    s2[0] = '\0';
    
    sprintf (s1, "%d", a);
    sprintf (s2, "%d", b);
    
    if (strlen (s1) == strlen (s2))
    {
       int len = strlen (s1);
       for (int i = 0; i < len; ++i)
       {
           if (strcmp (s1, s2) ==  0)
              return true;
           rotate (s1 + 0, s1 + 1, s1 + len);
       }
    }
       
    return false;
}

inline int get_ans (int a, int b)
{
    int res = 0;
    for (int i = a; i <= b; ++i)
        for (int j = i + 1; j <= b; ++j)
            if (is_sim (i, j) && i < j)
               ++res;
               
    return res;
}

int main ()
{
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    
    int all;
    scanf ("%d", &all);
    int a, b;
    for (int i = 0; i < all; ++i)
    {
        scanf ("%d %d", &a, &b);
        printf ("Case #%d: %d\n", i + 1, get_ans (a, b));
    }
    
    return 0;
    
}
