
# include <iostream>

using namespace std;

int main()
{
    int t,i,cnt=1;
    char ar[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'},aaa[10];
    cin>>t;
    gets(aaa);
    while(t--)  
    {
        char in[1000],out[1000];
        gets(in);
        strcpy(out,in);
        int sz,j;
        sz = strlen(in);
        for(i=0;i<sz;i++)
        {
            if(in[i]==' ') continue;
            out[i] = ar[in[i]-'a'];    
        }
        cout<<"Case #"<<cnt++<<": "<<out<<endl;
    }
}
