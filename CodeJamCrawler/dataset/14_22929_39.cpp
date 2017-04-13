#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int main()
{
    long long int t, i=1;
    cin>>t;
    FILE *fu = fopen("file.txt", "w");
    while(i<=t)
    {
        double c, f, x, s=0, e=0, r=2, mini;
        cin>>c>>f>>x;
        mini=x/2;
        double a[100];
        cout<<"Case #"<<i<<": ";
        fprintf(fu, "Case #%d: ", i++);
        for(int k=0 ; k<=x ; k++)
        {
            s=e+x/r;
            e=c/r+e;
            r=r+f;
            if(mini>s)
            {
                mini=s;
            }
        }
        printf("%.7lf\n",mini);
        fprintf(fu,"%.7lf\n",mini);


    }
    fclose(fu);
}
