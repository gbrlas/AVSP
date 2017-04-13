#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char arr[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

    int n,j;
    cin>>n;
    getchar();
    char str[1000];
    int index=0,i;

    for(i=1;i<=n;i++)
    {
        gets(str);
        j=0;
        cout<<"Case #"<<i<<": ";
        while(str[j]!='\0')
        {
            if(str[j]>=97 && str[j]<=122){
            index=str[j]-'a';
            cout<<arr[index];}
            else cout<<" ";
            j++;
        }
        cout<<endl;

    }
    return 0;


}
