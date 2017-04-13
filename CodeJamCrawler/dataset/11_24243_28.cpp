#include<iostream>
using namespace std;
int arr[100000];
int n;
int test(int num)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        k = arr[i];
        if( k % num != 0 && num % k != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int t,i,l,h,j;
    int out,f;
    cin >> t;
    for(i=0;i<t;i++)
    {
        cin >> n;
        cin >> l >> h;
        for(j=0;j<n;j++)
        {
            cin >> arr[j];
        }
        cout<<"Case #"<<i+1<<": ";
        for(f = l ; f<=h ;f++)
        {
            out = test(f);
            if( out == 1 )
            {
                cout << f<<endl ;
                break;
            }
        }
        if( f == h+1 )
        {
            cout << "NO"<<endl;
        }
     }
 }
