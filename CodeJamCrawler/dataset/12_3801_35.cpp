# include <stdio.h>


int main(void)
{
    //var 
    int t, n, s, p;
    int count = 0;
    int temp,temp1,temp2;
    int ti[101];

    //loop
    int i,j,k,l;

    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        count = 0;
        scanf("%d ",&n);
        scanf("%d ",&s);
        scanf("%d ",&p);

        for(j=0;j<n;j++)
            scanf("%d ",&ti[j]);

        // Solve
        for(j=0;j<n;j++)
        {
            // ignore impossible ?
            switch(ti[j] % 3)
            {
                case 0:
                    temp = (ti[j] / 3);
                    // try without 'surprise'
                    if (temp >= p)
                    {
                        count++;
                        break;
                    }
                    // try with surprise
                    if(temp > 0)
                    if( (s > 0) && ((temp+1) >= p) )
                    {
                        count++;
                        s--;
                        break;
                    }
                    break;
                case 1:
                    temp = ((ti[j]-1) / 3);
                    // try without 'surprise'
                    if ((temp+1) >= p)
                    {
                        count++;
                        break;
                     }
                    // try with surprise
                    if( (s > 0) && ((temp+1) >= p) )
                    {
                        count++;
                        s--;
                        break;
                    }
                    break;
                case 2:
                    temp = ((ti[j]-2) / 3);
                    // try without 'surprise'
                    if ((temp+1) >= p)
                    {
                        count++;
                        break;
                     }
                    // try with surprise
                    if( (s > 0) && ((temp+2) >= p) )
                    {
                        count++;
                        s--;
                        break;
                    }
                    break;

            }
        }

        // output print
        printf("Case #%d: %d\n",i+1,count);
     }

    return 1;
}

