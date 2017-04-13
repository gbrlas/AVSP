
# include <iostream>

using namespace std;

int main()
{
    int t,cnt=1;
    cin>>t;
    while(t--)
    {
        int n,s,p,sc[100],i,j;
        cin>>n>>s>>p;
        for(i=0;i<n;i++)
            cin>>sc[i];
        sort(sc,sc+n);
        int ans=0;
        for(i=n-1;i>=0;i--)
        {
            int ss = sc[i]/3;
            if(ss>=p)
            {
                ans++;
                continue;    
            }
            if(ss*3 == sc[i]-2)
            {
                if(ss==p-1)
                {
                    ans++;
                    continue;    
                }
                else if(ss==p-2 && s>0)
                {
                    --s;
                    ++ans;
                    continue;    
                }
                else
                    continue;
            }
            else if(ss*3 == sc[i]-1)
            {
                if(ss==p-1)
                {
                    ans++;
                    continue;    
                }
                else
                    continue;    
            }
            else
            {
                if(s>0 && ss==p-1 && ss>=1)
                {
                    --s;
                    ++ans;    
                }
                else
                    break;
                
            }
        }
    cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }    
}
