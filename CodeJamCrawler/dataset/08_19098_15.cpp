#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
using namespace std;
int main()
{
        int t;
        cin>>t;
        int cases=0;
        while(t--)
        {
                cases++;
                int max,keys,tot;
                cin>>max>>keys>>tot;
                vector<int>a;
                int i,j;
                for(i=0;i<tot;i++)
                {
                        int temp;
                        cin>>temp;
                        a.push_back(temp);
                }
//              vector<long long int>pad[keys];
                long long int pad[keys][max];
                for(i=0;i<keys;i++)
                {
                        for(j=0;j<max;j++)
                        {
                                pad[i][j]=-1;
                        }
                }
                sort(a.begin(),a.end());
                long long int ans=0;
                for(i=tot-1;i>=0;i--)
                {
                        for(j=0;j<max;j++)
                        {
                                int found=0;
                                for(int k=0;k<keys;k++)
                                {
                                        if(pad[k][j]==-1)
                                        {
                                                pad[k][j]=a[i];
                                                ans=ans+(j+1)*a[i];
                                                found=1;
                                                break;
                                        }
                                }
                                if(found)
                                        break;
                        }
                }





                                cout<<"Case #"<<cases<<": "<<ans<<endl;
        }
}

