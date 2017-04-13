#include<iostream>
using namespace std;
int main()
{
        int t,i,ans,j,current,pro,check,count,cases=0;
        int * found;
        cin>>t;
        while(t--)
        {
                cases++;
                ans=0;
                int no_s,no_q;
                cin>>no_s;
                getchar();
                string search[no_s];
                for(i=0;i<no_s;i++)
                        getline(cin,search[i]);
                cin>>no_q;
                getchar();
                string query[no_q];
                for(i=0;i<no_q;i++)
                        getline(cin,query[i]);
/*              for(i=0;i<no_s;i++)
                        cout<<search[i]<<endl;
                for(i=0;i<no_q;i++)
                        cout<<query[i]<<endl;*/
                count=0;
                pro=0;
                int start=0;
                while(pro<no_q)
                {
                found=(int *)calloc(no_s,sizeof(int));
                        count=0;
                        for(i=start;i<no_q;i++)
                        {
                                for(j=0;j<no_s;j++)
                                {
                                        if(query[i]==search[j] && found[j]==0)
                                        {
                                                found[j]=1;
                                                current=j;
                                                count++;
                                        }

                                }
                        }
                        string check=search[current];
                        if(count<no_s)
                        {
                                break;
                                ans=0;
                        }
                        else
                        {
                                i=pro;
                                while(query[i]!=check)
                                {
                                        i++;
                                        pro++;
                                }
                                start=i;
                                ans++;

                        }
                }

                cout<<"Case #"<<cases<<": "<<ans<<endl;
        }

}