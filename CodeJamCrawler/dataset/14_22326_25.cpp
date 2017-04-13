#include<bits/stdc++.h>
using namespace std;

int main( void )
{
//    freopen("archivo.in","r",stdin);
//    freopen("file.txt","w",stdout);
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i ++)
    {
        int arr [8] [8];
        int ind [17] ;
        int a1,a2;
        cin>>a1;
        for(int j = 0 ; j < 4 ; j++)
        {
            for(int k = 0 ; k < 4 ; k++)
            {
                int t;
                cin>>t;
                ind[t] = j+1;
            }
        }
        cin>>a2;
        for(int j = 0 ; j < 4 ; j++)
        {
            for(int k = 0 ; k < 4 ; k++)
            {
                cin>>arr [j] [k];
            }
        }
        int c = 0, ans = 0;
        for(int j = 0 ; j < 4 ; j ++)
        {
            if (ind[ arr[a2-1] [j] ] == a1 )
            {
                c++;
                ans = arr[a2 - 1] [j];
            }
        }
        cout << "Case #"<<i + 1 <<": ";
        if(c == 1 )
            cout<<ans<<endl;
        else if(c > 1)
            cout<<"Bad magician!"<<endl;
        else
            cout<<"Volunteer cheated!"<<endl;
    }

}
