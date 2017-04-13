#include<bits/stdc++.h>


using namespace std;

int main()
{

    int casos;


    cin>>casos;
    for(int k=0; k<casos; k++)
    {
        int bloques, z=0;
        vector<float>Naomi;
        vector<float>Ken;
        float a;
        cin>>bloques;
        for(int i=0; i<bloques; i++)
        {
            cin>>a;
            Naomi.push_back(a);
        }

        for(int j=0; j<bloques; j++)
        {
            cin>>a;
            Ken.push_back(a);
        }

        sort(Naomi.begin(), Naomi.end());
        sort(Ken.begin(),Ken.end());
        int w=0,y=0, t=bloques-1, d=bloques-1;
       for(int j=bloques-1; d>=w&&j>=0; j--)
        {
            if(Naomi[j]<Ken[d])
            {
                z++;
                d--;
            }
              else
                w++;
        }
        w=0;
        for(int j=bloques-1; t>=w&&j>=0; j--)
        {
            if(Naomi[t]>Ken[j])
            {
                y++;
                t--;
            }
            else
                w++;
        }


        printf("Case #%d: %d %d\n",k+1,y,bloques-z);

    }

    return 0;
}
