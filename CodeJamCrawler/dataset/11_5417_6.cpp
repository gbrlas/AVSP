
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <math.h>



using namespace std;

int main()
{
    int T,T_C=1;
    cin >> T;
    while(T_C <= T)
    {
        int N=0,p_d=0, p_g=0;
        cin >> N;
        cin >> p_d;
        cin >> p_g;

        if(N>0)
        {
            int flag=0;
            if(p_d < 100 && p_g == 100)
                cout<<"Case #"<<T_C<<": "<<"Broken"<<endl;
            else if(p_d == 0 && p_g == 0)
                cout<<"Case #"<<T_C<<": "<<"Possible"<<endl;
            else if(p_d > 0 && p_g == 0)
                cout<<"Case #"<<T_C<<": "<<"Broken"<<endl;
            else if(p_d > 0 && p_d <= 100)
            {
                for(int i=1;i<=N;i++)
                {
                    int tmp=i*p_d/100;
                    int tmp1=tmp*100/p_d;
                    if(tmp1==i)
                    {    cout<<"Case #"<<T_C<<": "<<"Possible"<<endl;
                        flag=1;
                         break;
                     }




                }
                if(flag==0)
                    cout<<"Case #"<<T_C<<": "<<"Broken"<<endl;

            }

        }
        else if(N==0)
        {
            if(p_d > 0)
                //Case #2: Broken
                cout<<"Case #"<<T_C<<": "<<"Broken"<<endl;
            if(p_d == 0 && p_g == 0)
                cout<<"Case #"<<T_C<<": "<<"Possible"<<endl;
            if(p_d == 0 && p_g > 0 && p_g <= 100)
                cout<<"Case #"<<T_C<<": "<<"Possible"<<endl;
            if(p_d == 0 && p_g > 100)
                cout<<"Case #"<<T_C<<": "<<"Broken"<<endl;

        }

        T_C ++;
    }



    return 0;
}

