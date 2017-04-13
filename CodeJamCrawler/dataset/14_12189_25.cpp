#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
    int a,b;
    scanf("%d",&a);
    int arr[17]={0};
    int c=0,temp;
    int result=0;
    int var=0;
    while(c!=4)
    {
    if(c!=(a-1))
    for(int i=0;i<4;i++)
    scanf("%d",&temp);
    else
    for(int i=0;i<4;i++){
    scanf("%d",&temp);
    arr[temp]++;
    }

    c++;
    }

    scanf("%d",&b);
    c=0;
    while(c!=4){
    if(c!=(b-1))
    for(int i=0;i<4;i++)
    scanf("%d",&temp);
    else
    for(int i=0;i<4;i++){
    scanf("%d",&temp);
    if(arr[temp]==1)
    {
    var=temp;
    result++;
    }
    }
    c++;
    }
    if(result==0)
    printf("Case #%d: Volunteer cheated!\n",j);
    else if(result==1)
    printf("Case #%d: %d\n",j,var);
    if(result>1)
    printf("Case #%d: Bad magician!\n",j);

    }
    return 0;
}
