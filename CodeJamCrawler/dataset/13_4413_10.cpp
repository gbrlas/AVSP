# include <stdio.h>


int cmpint( const void *a, const void *b)
{
    int x  = *((int *)a); 
    int y  = *((int *)b);

    if (x<y) return -1 ;
    if (x==y) return 0;
    if (x>y) return 1;
}

int main(void)
{
    //var 
    int t, n, a, b;
    int temp,temp1,temp2,steps;

    //loop
    int i,j,k,l;

    //string
    int temparr[100];


    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {

        scanf("%d ",&a);
        scanf("%d ",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d ",&temparr[j]);
        }

        qsort(temparr,n,sizeof(int),cmpint);

        // Solve
        steps = 0;
        for(j=0;j<n;j++)
        {
            temp = 0;
            
            while (a <= temparr[j])
            {
                if (a == 1)
                {
                    temp = n +1 ;
                    break;
                }
                a += (a-1) ;
                temp++;
            }
            if (temp > (n-j))
            {
                steps += (n-j);
                break;
            }

            a += temparr[j];
            steps += temp;
            //printf("Arr %d, a : %d :, steps : %d\n",temparr[j],a,steps);
        }
        // output print
        printf("Case #%d: %d\n",i+1,steps);
     }

    return 1;
}

