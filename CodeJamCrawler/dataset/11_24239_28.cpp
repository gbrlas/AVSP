#include<iostream>
using namespace std;
char arr[100][100];
int r,c;
int convert(int i, int j)
{
    arr[i][j]='/';
    if((i+1<r)&&(arr[i+1][j] == '#' ))
        arr[i+1][j] = '\\';
    else
        return 0;
    if((j+1<c)&&(arr[i][j+1] == '#' ))
        arr[i][j+1] = '\\';
    else
        return 0;

    if((j+1<c)&&(i+1<r)&&(arr[i+1][j+1] == '#' ))
        arr[i+1][j+1] = '/';
    else
        return 0;

}

int main()
{
    int t,i,j,out;
    char ch;
    cin >> t;
    int f;
    for(f=0;f<t;f++)
    {
    cin >> r >> c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin >> ch;
            arr[i][j] = ch;
        }
    }
    cout<<"Case #"<<f+1<<":"<<endl;
    for( i =0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(arr[i][j] == '#' )
            {
                out = convert(i,j);
                if(out == 0)
                {
                    cout<<"Impossible"<<endl;
                    break;
                }
            }
        }
        if(j!=c)
        {
            break;
        }
    }
    if( i==r )
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<arr[i][j];
            }
            cout << endl;
        }
        cout<<endl;
    }
    }
 }
