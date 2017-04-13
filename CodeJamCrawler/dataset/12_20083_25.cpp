#include<stdio.h>
int main()
{
    int t,a,b,ii,i,gg,hj,d,jh,vb,vbz;//,pl,pl2;
    long long int c;
   // printf("%d",(int)pow(10,3));
    scanf("%d",&t);vbz=1;
    while(t)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        c=0;
        printf("Case #%d: ",vbz);
        vbz++;
        for(i=a;i<=b;i++)
        {
            ii=i;vb=0;
            while(ii)
            {
            ii=ii/10;
            vb++;
            }

            ii=i;gg=0;
            while(ii)
            {
                gg++;
                d=ii%10;

                if(d==0)
                {
                    ii=ii/10;
                    continue;}
                if(ii>10)
                {
                    double pl=(pow(10,(vb-gg)));
                    double pl2=(pow(10,gg));

                    int cc=pl;
                    int dd=pl2;
                    hj=i%dd;
                 //  if(i==110)
               // printf("%f  %d\n",pl2,hj);
                    hj=hj*cc;
                  //  if(i==110)
                 //   printf("%d\n",hj);
                    jh=ii/10;
                    if(jh==0)
                    break;
                    else
                    hj+=jh;

                  if(hj>=a&&hj<=b&&hj>i)
                  {
                   //   printf("i %d  hj%d\n",i,hj);
                      c++;
                  }
                }
                 ii=ii/10;
            }
        }
        printf("%llu\n",c);
        t--;
    }
    return 0;
}
