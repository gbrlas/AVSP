#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<double> naomi;
vector<double> ken;
int main()
{
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D-small-attempt2.out","w",stdout);
    int t,N,i,j,ans1,ans2,k=1,l,f;
    double x;
    cin>>t;
    while(t--)
    {
        naomi.clear();
        ken.clear();
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>x;
            naomi.push_back(x);
        }
        for(i=0;i<N;i++)
        {
            cin>>x;
            ken.push_back(x);
        }
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());
//        cout<<endl<<endl;
//        for(i=0;i<N;i++)
//        {
//            cout<<naomi[i]<<" ";
//        }
//        cout<<endl<<endl;
//        for(i=0;i<N;i++)
//        {
//            cout<<ken[i]<<" ";
//        }
//        cout<<endl<<endl;
        ans1=0;
        i=0; l=N-1; j=0;
        for(i=0,j=0;i<N && j<=l; )
        {
            if(naomi[i]>ken[j])
            {
                ans1++;
                i++;
                j++;
            }
            else if(naomi[i]<ken[j])
            {
                i++;
                l--;
            }
        }
//        for(i=0;i<N;)
//        {
//            if(naomi[i]<ken[N-1-i])
//            {
//                i++;
//            }
//            else
//            {
//                break;
//            }
//        }
//        ans1 = N-i;
        j=0;
        f=0;
        ans2=0;
        for(i=0,j=0;i<N && j<N;)
        {
            if(naomi[i]>ken[j])
            {
                j++;
            }
            else if(naomi[i]<ken[j])
            {
                i++;
                j++;
            }

        }
        ans2 = N-i;
        cout<<"Case #"<<k++<<": "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
