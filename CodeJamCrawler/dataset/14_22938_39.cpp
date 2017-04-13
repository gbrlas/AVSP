#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
    int t, i=1;
    cin>>t;
    ofstream my;
    my.open ("f4.txt");
    while(i<=t)
    {
        int a;
        double x;
        vector<double>n1;
        vector<double>k1;
        vector<double>n2;
        vector<double>k2;
        cin>>a;
        for(int j=0 ; j<a ; j++)
        {
            cin>>x;
            n1.push_back(x);
            n2.push_back(x);
        }
        for(int l=0 ; l<a ; l++)
        {
            cin>>x;
            k1.push_back(x);
            k2.push_back(x);
        }
        sort(n1.begin(),n1.end());
        sort(k1.begin(),k1.end());
        sort(n2.begin(),n2.end());
        sort(k2.begin(),k2.end());

        int cdw=0;

        for(int e=0 ; e<n1.size() ; e++)
        {
            for(int f=0 ; f<k1.size() ; f++)
            {
                if(n1[e]>k1[f])
                {
                    cdw++;
                    k1.erase(k1.begin()+f);
                    break;
                }
            }
        }

        int cw=0;
        for(int g=0 ; g<k2.size() ; g++)
        {
            for(int h=0 ; h<n2.size() ; h++)
            {
                if(k2[g]>n2[h])
                {
                    cw++;
                    n2.erase(n2.begin()+h);
                    break;
                }
            }
        }
        cw=a-cw;
        cout<<"Case #"<<i<<": "<<cdw<<" "<<cw<<endl;
        my<<"Case #"<<i++<<": "<<cdw<<" "<<cw<<endl;
    }
    my.close();
}
