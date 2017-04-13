# include <stdio.h>
# include <string.h>
# include <math.h>

int check_palindrome(unsigned long long var)
{
    int i = 0, j = 0,k=0;
    char temp[40];
    sprintf(temp,"%llu",var);

//    printf("in str :%s<-%d\n",temp,strlen(temp));

    i = strlen(temp);
    j = i;

  //  printf("in str :%s<-%d\n",temp,i);
    
    if ((i%2) == 0)
        i = i/2;
    else
        i = (i-1)/2;

    for(k=0; k < i; k++)
        if (temp[k] != temp[(j-1-k)])
            return 0;

    return 1;
}

int main(void)
{
    //var 
    int t, n;
    unsigned long long a, b,temp, ans;
    int temp1,temp2;

    //loop
    int i,j,k,l;


    //t = check_palindrome(11);
    //printf ("ans : %d . \n",t);

    //return 0;

    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        ans = 0;
        scanf("%llu ",&a);
        scanf("%llu ",&b);

        for(;a<=b;a++)
        {
            if (check_palindrome(a))
            {
                temp = (unsigned long long) (sqrtl((long double)(a))) ;
    //            printf("\n found palindrome : %llu . srt ? : %llu \n",a,temp);
                if (temp*temp == a)
                    if (check_palindrome(temp))
                        ans++;
                temp -= 1;
                if (temp*temp == a)
                    if (check_palindrome(temp))
                        ans++;
                temp += 2;
                if (temp*temp == a)
                    if (check_palindrome(temp))
                        ans++;
            }
        }

        // output print
        printf("Case #%d: %llu\n",i+1,ans);
     }

    return 1;
}

