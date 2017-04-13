#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
    int t;
    freopen("A-small-attempt1.in",  "r",stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    char a[1000], b[1000];
    int cnt=1;
    while(t--)
    {
        int n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin >> n;
        cin >> a >> b;

        int len1=strlen(a);
        int len2=strlen(b);
        int j=0, i=0;
        int ans=0;
        while(i<len1&&j<len2)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else if(j>0&&a[i]==b[j-1])
            {
                i++;
                ans++;
            }
            else if(i>0&&b[j]==a[i-1])
            {
                j++;
                ans++;
            }
            else
            {
                ans=-1;
                break;
            }
        }
        while(j==len2&&i<len1)
        {
            if(a[i]==b[len2-1])
            {
                ans++;
                i++;
            }
            else
                break;
        }
        while(i==len1&&j<len2)
        {
            if(a[len1-1]==b[j])
            {
                ans++;
                j++;
            }
            else
                break;
        }
        if(i!=len1||j!=len2)
            ans=-1;
        cout << "Case #" << cnt++ << ": ";
        if(ans==-1)
            cout << "Fegla Won" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
