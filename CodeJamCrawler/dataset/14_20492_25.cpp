#include <iostream>
#include <cstdio>
using namespace std;
int counter(int *,int *,int ,int);
int main()
 {
    freopen("file.in","r",stdin);
    freopen("out.out","w",stdout);
	int a[4][4], b[4][4];
    int r1,r2;
    int T;
    int response=0;
    int ans;


    cin>>T;
    for(int i=0;i<T;i++)
    {
      cin>>r1;
      for(int j=0;j<4;j++)
       {
           for(int k=0;k<4;k++)
            {
             cin>>a[j][k];
            }
       }
      cin>>r2;
     for(int j=0;j<4;j++)
       {
           for(int k=0;k<4;k++)
            {
             cin>>b[j][k];
            }
       }
       response=0;
    for(int l=0;l<4;l++){
     for(int j=0;j<4;j++)
       {
           if(a[r1-1][l]==b[r2-1][j])
            {
              response++;
             ans = a[r1-1][l];
            }

       }
    }
       switch(response)
       {
       case 0:
         cout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
         break;
       case 1:
         cout<<"Case #"<<i+1<<": "<<ans<<endl;
         break;
       default:
         cout<<"Case #"<<i+1<<": Bad magician!"<<endl;
       }
    }
	return 0;
}


