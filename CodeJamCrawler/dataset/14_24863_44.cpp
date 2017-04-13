#include <iostream>
#include "stdio.h"

using namespace std;

double Naomi[1005];
double Ken[1005];
double Ken_copy[1005];

int as_sort (double a[], int size)
{
    double temp = -1.0;
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return 0;
}

int as_reverse_sort(double a[], int size)
{
    double temp = -1.0;
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return 0;
}

int find_min_max_in_reverse_sorted_array(double a[], int size, double target)
{
    for (int i=0; i<size; i++)
    {
        if (a[i] < target)
            return i-1;
    }
    return size-1;
}

void fill_masses(int num_of_masses)
{
    for (int i=0; i<num_of_masses; i++)
    {
        cin >> Naomi[i];
    }
    for (int i=0; i<num_of_masses; i++)
    {
        cin >> Ken[i];
    }
}

void as_copy (double to[], double from[], int size)
{
    for (int i=0; i<size; i++)
    {
        to[i] = from[i];
    }
}

void as_print (double a[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf ("%f ", a[i]);
    }
    printf ("\n");
}

int main()
{
    int num_of_cases = -1;

    cin >> num_of_cases;

    for (int i=0; i<num_of_cases; i++)
    {
        int num_of_masses = -1;
        cin >> num_of_masses;

        fill_masses(num_of_masses);
        as_reverse_sort(Ken, num_of_masses);
        as_copy(Ken_copy, Ken, num_of_masses);

        /*** calculating Naomi_score_in_Deceitful_War ***/
        int Naomi_score_in_Deceitful_War = 0;
        as_reverse_sort(Naomi, num_of_masses);

        // Ken is already sorted.
/*
        int target_position_index = 0;
        for (; target_position_index<num_of_masses; target_position_index++)
        {
            if (Naomi[target_position_index] > Ken[target_position_index])
                break;
        }
        if (target_position_index == num_of_masses)
            Naomi_score_in_Deceitful_War = 0;
        else
            Naomi_score_in_Deceitful_War = num_of_masses - target_position_index;
*/
        int pos_in_Naomi = num_of_masses-1;
        int good_pair_counter = 0;
        for (int j=num_of_masses-1; j>=0 ; j--)
        {
            while (pos_in_Naomi >= 0)
            {
                if (Naomi[pos_in_Naomi] > Ken[j])
                    break;
                pos_in_Naomi--;
            }
            if (pos_in_Naomi == -1)
                break;

            pos_in_Naomi--;
            good_pair_counter++;
        }
        Naomi_score_in_Deceitful_War = good_pair_counter;
        //printf("Naomi_score_in_Deceitful_War : %d\n", Naomi_score_in_Deceitful_War);

        /*** calculating Naomi_score_in_War ***/
        //printf ("\n\ncalculating Naomi_score_in_War\n");
        //as_print(Ken_copy, num_of_masses);
        int size_for_Ken = num_of_masses;
        int Naomi_score_in_War = 0;
        for (int j=0; j<num_of_masses; j++)
        {
            int index = -1;
            index = find_min_max_in_reverse_sorted_array(Ken_copy, size_for_Ken, Naomi[j]);

            if (index == -1)
            {
                //printf ("N : %f\tK : %f\n", Naomi[j], Ken_copy[size_for_Ken-1]);
                size_for_Ken--;
                Naomi_score_in_War++;
            }
            else
            {
                //printf ("N : %f\tK : %f\n", Naomi[j], Ken_copy[index]);

                // do some shifting
                for (int k=index+1; k<size_for_Ken; k++)
                {
                    Ken_copy[k-1] = Ken_copy[k];
                }

                size_for_Ken--;
            }
        }
        //printf("Naomi_score_in_War : %d\n", Naomi_score_in_War);

        printf ("Case #%d: %d %d\n", i+1, Naomi_score_in_Deceitful_War, Naomi_score_in_War);
    }

    return 0;
}
