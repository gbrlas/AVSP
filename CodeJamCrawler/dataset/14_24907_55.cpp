
#include <stdio.h>
#include <stdlib.h>

double getmax(double * array, int size)
{
    double max = -0.01;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max && array[i] != 1.01)
        {
            max = array[i];
        }
    }
    return max;
}

double getmingreaterthanx(double * array, int size, double x)
{
    double min = 1.01;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < min && array[i] > x)
        {
            min = array[i];
        }
    }
    return min;
}

int getpos(double * array, int size, double value)
{
    int pos = -1;
    for(int i = 0; i < size; i++)
    {
        if(array[i] == value)
        {
            return i;
        }
    }
    return pos;
}

void copy(double * array, double * array2, int size)
{
    for(int k = 0; k < size; k++)
    {
        array2[k] = array[k];
    }
}

int main()
{
    int numberoftest;
    scanf("%d", &numberoftest);
    
    int count;
    
    for(int i = 0; i < numberoftest; i++)
    {
        scanf("%d", &count);
        
        double naomi[count],ken[count];
        
        for(int j = 0; j < count; j++) { scanf("%lf", &naomi[j]); }
        for(int j = 0; j < count; j++) { scanf("%lf", &ken[j]); }
        
        double naomi2[count],ken2[count];
        
        copy(ken, ken2, count);
        copy(naomi, naomi2, count);
        
        int points = 0;
        int points2 = 0;
        
        for(int j = 0; j < count; j++)
        {
            double choicenaomi = getmingreaterthanx(naomi, count, 0);
            double choiceken = getmingreaterthanx(ken, count, choicenaomi);
            
            if(choiceken == 1.01)
            {
               choiceken = getmingreaterthanx(ken, count, 0);
            }
        
            if(choicenaomi > choiceken)
            {
                points++;
            }
    
            naomi[getpos(naomi,count, choicenaomi)] = 1.01;
            ken[getpos(ken,count, choiceken)] = 1.01;
            
            
            double minken = getmingreaterthanx(ken2, count, 0);
            double minnaomi = 0;
            
            do
            {
                minnaomi = getmingreaterthanx(naomi2, count, minnaomi);
                if(minnaomi > minken && minnaomi != 1.01)
                {
                    points2++;
                    break;
                }
            }
            while(minnaomi != 1.01);
            
            if(minnaomi == 1.01)
            {
                minken = getmax(ken2, count);
                minnaomi = getmingreaterthanx(naomi, count, 0);
            }
            
            naomi2[getpos(naomi2,count, minnaomi)] = 1.01;
            ken2[getpos(ken2,count, minken)] = 1.01;
        }
        printf("Case #%d: %d %d\n", (i+1), points2, points);
    }
    
    return 0;
}
