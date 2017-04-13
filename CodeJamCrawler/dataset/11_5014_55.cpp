#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        char cb[27][27];
        char hilang[27][27];
        for (int i=0;i<27;i++) for (int j=0;j<27;j++) cb[i][j]='0';
        for (int i=0;i<27;i++) for (int j=0;j<27;j++) hilang[i][j]='0';
        
        int c,d,n;
        string s;
        cin>>c;
        for (int i=0;i<c;i++)
        {
            cin>>s;
            cb[s[0]-65][s[1]-65]=s[2];
            cb[s[1]-65][s[0]-65]=s[2];
        }
        cin>>d;
        for (int i=0;i<d;i++)
        {
            cin>>s;
            hilang[s[0]-65][s[1]-65]='1';
            hilang[s[1]-65][s[0]-65]='1';
        }
        cin>>n;
        cin>>s;
        bool pake[101]={0};
        for (int i=1;i<s.length();i++)
        {
            bool sudah=0;
            for (int j=i-1;j>=0;j--)
            {
                if (pake[j]==1) continue;
                
                if (cb[s[i]-65][s[j]-65]!='0' && i-j==1)
                {
                    pake[j]=1;
                    s[i]=cb[s[i]-65][s[j]-65];
                    break;
                }
                if (hilang[s[i]-65][s[j]-65]=='1')
                {
                    for (int q=0;q<=i;q++)
                        pake[q]=1;
                    break;
                }
            }
        }
        cout<<"Case #"<<count++<<": [";
        int kena=0;
        for (int i=0;i<s.length();i++)
        {
            if (pake[i]==0)
            {
                if (kena>0) cout<<", "; 
                cout<<s[i];
                kena=1;
            }
        }
        cout<<"]";
        cout<<endl;
    }
    //system("pause");
    return 0;
}
