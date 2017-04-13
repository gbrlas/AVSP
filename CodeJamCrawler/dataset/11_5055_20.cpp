#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    char arr[105][105];
    while (tc--)
    {
        cout<<"Case #"<<count++<<":"<<endl;
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin>>arr[i][j];
        double wp[105],OWP[105],OOWP[105];
        double st[105],nl[105];
        for (int i=0;i<n;i++)
        {
            double satu=0;
            double nol=0;
            for (int j=0;j<n;j++)
            {
                if (arr[i][j]=='1') satu++;
                else if (arr[i][j]=='0') nol++;
            }
            st[i]=satu;
            nl[i]=nol;
            wp[i] = satu/(satu+nol);
        }
        for (int i=0;i<n;i++)
        {
            //double OWP;
            double nwp=0.0;
            double byk=0;
            for (int j=0;j<n;j++)
            {
                if (arr[i][j]!='.')
                {
                    byk++;
                    double stt=st[j],nlt=nl[j];
                    if (arr[j][i]=='1')
                        stt=st[j]-1;
                    else if (arr[j][i]=='0')
                        nlt=nl[j]-1;
                    nwp = nwp+(stt/(nlt+stt));
                }
            }
            OWP[i] = nwp/byk;
        }
        for (int i=0;i<n;i++)
        {
            double byk=0;
            double nowp=0.0;
            for (int j=0;j<n;j++)
            {
                if (arr[i][j]!='.')
                {
                    byk++;
                    nowp+=OWP[j];
                }
            }
            OOWP[i] = nowp/byk;
        }
        for (int i=0;i<n;i++)
        {
            double RPI = 0.25 * wp[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
            cout<<RPI<<endl;//printf("%.6lf\n",RPI);
        }
    }
    return 0;
}
