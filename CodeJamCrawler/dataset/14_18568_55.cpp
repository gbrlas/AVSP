#include<bits/stdc++.h>

using namespace std;

int main()
{
    int casos;
    cin >> casos;

    for(int i=0; i<casos; i++)
    {
        double c,f,x,galletas=2.0, total, tant=0.0;
        cin>>c>>f>>x;
        total=c/galletas;
        while(true)
        {
            if(tant+x/galletas<total+tant+x/(galletas+f))
            {
                printf("Case #%d: %4.7f \n",i+1,tant+x/galletas);
                break;
            }
            else
            {
                tant+=total;
                galletas+=f;
                total=c/galletas;


            }

        }
    }
    return 0;
}
