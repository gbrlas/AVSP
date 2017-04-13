using namespace std;
#include<iostream>
#include<cstring>
int main()
{
    char inp[5000][16];
    char str[15][500];
    char s[100000];
    int t,l,d,n,k,c=0;
    cin>>l>>d>>n;
    for(int i=0;i<d;i++)
    {scanf("%s",inp[i]);}
    //cout<<"output"<<endl;
    
    for(int i=0;i<n;i++)
    {
    scanf("%s",s);
    //printf("%s",s);
    t=0;
    for(int i=0;i<l;i++)
    {
            k=0;
            if(s[t]=='(')
            {
                         t++;
                         while(s[t]!=')')
                         {
                             str[i][k]=s[t];
                             k++;
                             t++;
                         }
                         str[i][k]='\0';
                         t++;
            }
            else
            {
                str[i][0]=s[t];
                str[i][1]='\0';
                t++;
            }
    }
    int count=0,flg;
    for(int i=0;i<d;i++)
    {
            for(int j=0;j<l;j++)
            {
                    flg=0;
                    for(int k=0;k<strlen(str[j]);k++)
                    {
                            if(inp[i][j]==str[j][k]) {flg=1;break;}
                    }
                    if(!flg) break;
            }
            if(flg) count++;
    }
    cout<<"Case #"<<c+1<<": "<<count<<endl;                   
    c++;
    }
    return 0;
}
