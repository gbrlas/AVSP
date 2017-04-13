#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
   // freopen("c1.in", "r", stdin);
    //freopen("c2.out", "w", stdout);
    int t,t1,n,i,j;
    double var;
    int y,z;
    cin>>t;
    for(t1=1;t1<=t;++t1)
    {

        y=0;z=0;
        cin>>n;
        set<double,less<double> > naomi,ken;
        for(i=0;i<n;++i)
        {
            cin>>var;
            naomi.insert(var);
        }
        for(i=0;i<n;++i)
        {
            cin>>var;
            ken.insert(var);
        }
        cout<<"Case #"<<t1<<": ";
        //war coding
        set<double,greater<double> > naomi_tmp;
        set<double>::iterator itr1(naomi.begin());
        while(itr1!=naomi.end())
        {
            naomi_tmp.insert(*itr1);
            ++itr1;
        }
        set<double,less<double> >ken_tmp;
        itr1=ken.begin();
        while(itr1!=ken.end())
        {
            ken_tmp.insert(*itr1);
            ++itr1;
        }
        int c=1;
        set<double>::iterator itr2;
        while(c<=n)
        {
            itr1=naomi_tmp.begin();
            itr2=ken_tmp.begin();
            while(itr2!=ken_tmp.end())
            {
                if(*itr2>*itr1)
                    break;
                ++itr2;
            }
            if(itr2==ken_tmp.end())
            {
                ++y;
                naomi_tmp.erase(*itr1);
                ken_tmp.erase(*(ken_tmp.begin()));
            }
            else
            {
                ken_tmp.erase(*itr2);
                naomi_tmp.erase(*itr1);
            }
            ++c;
        }
        //deceit war
        c=1;
        while(c<=n)
        {
            itr1=naomi.begin();
            itr2=ken.begin();
            while(itr1!=naomi.end())
            {
                if(*itr1>*itr2)
                    break;
                ++itr1;
            }
            if(itr1!=naomi.end())
            {
                ++z;
                //cout<<z<<" "<<*itr1<<" "<<*itr2<<endl;
                naomi.erase(*itr1);
                ken.erase(*itr2);
            }
            else
            {
                //cout<<z<<" "<<*itr1<<" "<<*itr2<<endl;
                naomi.erase(*(naomi.begin()));
                ken.erase(*itr2);
            }
            ++c;
        }
        cout<<z<<" "<<y<<endl;
    }
    return 0;

}
