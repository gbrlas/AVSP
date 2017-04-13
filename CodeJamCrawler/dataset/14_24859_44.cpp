#include <iostream>
#include "stdio.h"

using namespace std;

double calculate(double c, double f, double x, int num_of_farms_bought)
{
    double result = 0;
    for (int i=0; i<num_of_farms_bought; i++)
    {
        result += c / (2 + i * f);
    }
    result += x / (2 + num_of_farms_bought * f);
    return result;
}

int main()
{
    int num_of_cases = -1;
    cin >> num_of_cases;

    for (int i=0; i<num_of_cases; i++)
    {
        double c = -1;
        double f = -1;
        double x = -1;

        cin >> c;
        cin >> f;
        cin >> x;

        double least = -1;
        least = x / 2.0;

        double time_needed = -1;
        int num_of_farms_bought = 1;

        while (1)
        {
            time_needed = calculate (c, f, x, num_of_farms_bought);

            if (time_needed < least)
            {
                least = time_needed;
            }
            else
            {
                break;
            }
            num_of_farms_bought++;
        }
        printf ("Case #%d: %.7f\n", i+1, least);
    }

    return 0;
}
