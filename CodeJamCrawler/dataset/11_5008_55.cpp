#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<char> warna(n);
        vector<int> letak(n);
        vector<int> lb;
        vector<int> lo;
        for (int i=0;i<n;i++)
        {
            cin>>warna[i]>>letak[i];
            if (warna[i]=='O') lo.push_back(letak[i]);
            if (warna[i]=='B') lb.push_back(letak[i]);
        }
        int b=1,o=1,pb=0,po=0;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (warna[i]=='B')
            {
                int t = b-letak[i];
                if (t<0) t*=-1;
                t++;
                ans+=t;
                b=letak[i];
                pb++;
                if (po<lo.size())
                {
                    int temp = o-lo[po];
                    if (temp<0) temp*=-1;
                    if (temp<=t) o=lo[po];
                    else
                    {
                        if (o<lo[po]) o+=t;
                        else o-=t;
                    }
                }
            }
            else
            {
                int t = o-letak[i];
                if (t<0) t*=-1;
                t++;
                ans+=t;
                o=letak[i];
                po++;
                if (pb<lb.size())
                {
                    int temp = b-lb[pb];
                    if (temp<0) temp*=-1;
                    if (temp<=t) b=lb[pb];
                    else
                    {
                        if (b<lb[pb]) b+=t;
                        else b-=t;
                    }
                }
            }
            //cout<<ans<<" "<<b<<" "<<o<<endl;
        }
        cout<<"Case #"<<count++<<": "<<ans<<endl;
    }
    return 0;
}
