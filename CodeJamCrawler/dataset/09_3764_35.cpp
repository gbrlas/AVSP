using namespace std;
#include<iostream>
char c[1000001];
int n[11];
char arr[1000001];
int main()
{
    int temp,cases,zero,k;
    bool flg;
    cin>>cases;
    for(int no=1;no<=cases;no++)
    {
            scanf("%s",&c);
            flg=true;
            if(next_permutation(c,c+strlen(c)))
            flg=false;
            if(!flg)
            printf("Case #%d: %s\n",no,c);
            else
            {
            prev_permutation(c,c+strlen(c));
            arr[0]='0';
            for(int i=0;i<=strlen(c);i++)
            arr[i+1]=c[i];
            //c[0]='0';
            next_permutation(arr,arr+strlen(arr));
            printf("Case #%d: %s\n",no,arr);
            }
    }
    return 0;
}
