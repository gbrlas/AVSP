#include <iostream>
#include<cstdio>
using namespace std;
void Insertion_Sort (double arr[], int length)
{
    int j;
    double temp;

    for (int i = i; i < length; i++)
    {
        j = i;

        while (j > 0 && arr[j] < arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
int DecitfulWar(double Naomi[],double Ken[],int N)
{
    int count1=0,count2=0;
    int i=N-1,j=N-1;


    while(i>=0&&j>=0)
    {

        if(Naomi[i]>Ken[j])
        {
            count1++;
            j--;
            i--;
        }
        else
        {
            j--;
        }
    }
    return count1;
}

int War(double Naomi[],double Ken[],int N)
{
    int i=0,j=0;
    int count=0;
    while(j<N)
    {
        if(Naomi[i]<Ken[j])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }


    }
    return N-count;
}
int main()
{
    int T;

    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    cin>>T;
    for(int k=0; k<T;)
    {
        int N;

        cin>>N;
        double Naomi[N];
        double Ken[N];
        for(int i=0; i<N; i++)
        {
            cin>>Naomi[i];
        }
        Insertion_Sort(Naomi,N);
        for(int i=0; i<N; i++)
        {
            cin>>Ken[i];
        }

        Insertion_Sort(Ken,N);

        int a= DecitfulWar(Naomi,Ken, N);
        int b = War(Naomi,Ken, N);
        cout<<"Case #"<<++k<<": "<<a<<" "<<b<<"\n";
    }
}
