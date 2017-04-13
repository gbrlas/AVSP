#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[3001];
long long add;
int main()
{
    freopen("cc.in","r",stdin);
    freopen("cc.out","w",stdout);
    int test,i,j,Case=1,k,res;
    scanf("%d",&test);
    while(test--)
    {
        add=0;
        cin>>k;
        res=0;
        for(i=0;i<k;i++)
         cin>>arr[i];
        for(i=0;i<k;i++)
         res^=arr[i];
        if(!res)
        {
            sort(&arr[0],&arr[k]);
            for(i=1;i<k;i++)
            add+=arr[i];
            printf("Case #%d: ",Case++);
            cout<<add<<endl;
        }
        else
        printf("Case #%d: NO\n",Case++);
    }


    return 0;
}
