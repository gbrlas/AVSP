#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>


using namespace std;
int main()
{
        int t;
        long long int  cases=0,a,b,c,d,x,y ,m;
        cin>>t;
        while(t--)
        {
                cases++;
                int n;
                cin>>n>>a>>b>>c>>d>>x>>y>>m;
                int treex[n],treey[n];
                int i;
                treex[0]=x;
                treey[0]=y;
                for(i=1;i<n;i++)
                {
                        x=(a*x+b)%m;
                        y=(c*y+d)%m;
                        treex[i]=x;
                        treey[i]=y;
                }
                int count=0;
                for(i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                        {
                                for(int k=j+1;k<n;k++)
                                {
                                        int x1=treex[i];
                                        int y1=treey[i];
                                        int x2,y2,x3,y3;
                                        x2=treex[j];
                                        y2=treey[j];
                                        x3=treex[k];y3=treey[k];
                                        float checkx=(x1+x2+x3)/3.0;
                                        float checky=(y1+y2+y3)/3.0;
                                        if(checkx==(int)checkx && checky==(int)checky)
                                                count++;
                                }
                        }
                }
                cout<<"Case #"<<cases<<": "<<count<<endl;
        }
}
