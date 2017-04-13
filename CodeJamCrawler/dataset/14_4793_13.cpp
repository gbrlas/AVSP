#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
vector<int> a;
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int t,i,n,cnt,ans,l,j,f,cse=1,tmp,sum,avg,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int a[n];
        //a.clear();
        //a.resize(n);
        for(i=0;i<n;i++)
        {
            //cin>>tmp;
            //a.push_back(tmp);
            cin>>a[i];
        }
        sort(a,a+n);
        ans=0;
        for(i=n-1,j=0;i>=j;)
        {
            if(i==j)
            {
                ans++;
                //cout<<ans<<endl;
                break;
            }
            //cout<<a[i]<<" "<<a[j]<<endl;
            if(a[i]+a[j]<=x)
            {
                ans++;
                i--;
                j++;
            }
            else
            {
                ans++;
                i--;
            }

            //cout<<1<<endl;
        }
        cout<<"Case #"<<cse++<<": "<<ans<<endl;
    }
    return 0;
}
