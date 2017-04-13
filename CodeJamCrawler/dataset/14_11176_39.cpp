#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,k,y,n,i,j,c,c1,front,rear;
    float a[11],b[11];
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>n;
        c=c1=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];

        sort(a,a+n);
        sort(b,b+n);

        i=j=n-1;
        while(i>=-1)
        {
            if(a[i]>b[j])
            {
                i--;
                c++;
            }
            else
            {
                j--;
                i--;
            }
        }


        front=0;
        rear=n-1;
        for(i=0;i<n;i++)
        {
            if(a[i]>b[front])
            {
                front++;
                c1++;
            }
            else
            rear--;
        }
        cout<<"Case #"<<k<<": "<<c1<<" "<<c<<endl;
    }
    return 0;
}
