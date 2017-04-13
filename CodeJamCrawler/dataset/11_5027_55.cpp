#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int tc;
    int count=1;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int arr[16];
        for (int i=0;i<n;i++) cin>>arr[i];
        int byk = (int)pow(2,n);
        
        int maks = -1;
        for (int i=1;i<byk-1;i++)
        {
            int a=0,b=0,real=0;
            for (int j=0;j<n;j++)
            {
                if ((i&(1<<j))>0) //diisi a
                {
                    //cout<<"a ";
                    a^=arr[j];
                }
                else             //diisi b
                {
                    //cout<<"b ";
                    b^=arr[j];
                    real+=arr[j];
                }
            }
            //cout<<a<<" "<<b<<" "<<real;
            if (a==b)
            {
                maks = max(maks,real);
            }
            //cout<<endl;
        }
        cout<<"Case #"<<count++<<": ";
        if (maks==-1)
            cout<<"NO"<<endl;
        else
            cout<<maks<<endl;
    }
    //system("pause");
    return 0;
}
