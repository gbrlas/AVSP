
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberoftest;
    scanf("%d", &numberoftest);
    
    double c,f,x;
    
    double cps = 2;
    
    for(int i = 0; i < numberoftest; i++)
    {
        scanf("%lf %lf %lf", &c, &f, &x);
        
        double otime = x/2;
        for(int j = 0; ;j++)
        {
            double time = otime - x/(f*j +2) + c/(f*j +2) + x/(f*(j+1) +2);
            
            if(otime < time)
            {
                break;
            }
            otime = time;
        }
        
        printf("Case #%d: %.7lf\n", (i+1),otime);
    }
    
    return 0;
}