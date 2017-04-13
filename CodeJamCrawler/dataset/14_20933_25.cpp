int main()
{
    int testCase,i;
    scanf("%d",&testCase);
    for(i=1;i<=testCase;i++)
    {
        printf("Case #%d: ", i);
        cookiesClicker();
        printf("\n");
    }
	return 0;

}



void cookiesClicker()
{
    double current_rate=2, C, F, X, Time=0, t1, t2, t3;

    scanf("%lf %lf %lf",&C, &F, &X);


    while(1){


            t1 = X/current_rate;

            t2 = X/(current_rate + F);
            t3 = C/current_rate;

            if (t1 <= t2+t3)
            {
                Time += t1;
                break;
            }
            else
            {
                Time += t3;
                current_rate += F;

            }


    }


    printf("%.7f",Time);
}
