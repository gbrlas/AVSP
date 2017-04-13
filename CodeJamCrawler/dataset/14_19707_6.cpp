#include <stdio.h>
#include <set>

int main()
{
    freopen("C:\\Users\\Nothing9087\\Downloads\\A-small-attempt1.in", "rt+", stdin);
    freopen("D:\\A-small-attempt1.out", "wt+", stdout);
    int T;
    scanf("%d", &T);
    for(unsigned t = 1; t < T; t ++)
    {
        int row;
        std::set<int> flag;
        scanf("%d", &row);
        for(unsigned r = 1; r <= 4; r ++)
        {
            for(unsigned c = 0; c < 4; c ++)
            {
                int num;
                scanf("%d", &num);
                if(r == row)
                {
                    flag.insert(num);
                }
            }
        }
        scanf("%d", &row);
        int count = 0, mem;
        for(unsigned r = 1; r <= 4; r ++)
        {
            for(unsigned c = 0; c < 4; c ++)
            {
                int num;
                scanf("%d", &num);
                if(r == row && flag.find(num) != flag.end())
                {
                    count ++;
                    mem = num;
                }
            }
        }
        printf("Case #%d: ", t);
        if(count == 0)
        {
            printf("Volunteer cheated!\n");
        }
        else if(count == 1)
        {
            printf("%d\n", mem);
        }
        else
        {
            printf("Bad magician!\n");
        }
    }
}