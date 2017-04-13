#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    char array[50][50];
    int i,j,t,c,dim;
    vector<int> length(50);
    int ti,tc;
    scanf("%d",&tc);
    for(ti=0;ti<tc;ti++)
    {
        scanf("%d",&dim);
        for(i=0;i<dim;i++)
        {
            scanf("%s",array[i]);
            length[i]=0;
            for(j=0;j<dim;j++)
            {
                if(array[i][j]=='1')
                    length[i]=j+1;
            }
        }
        c=0;
        for(i=0;i<dim;i++)
        {
            for(j=i;j<dim;j++)
                if(length[j]<=i+1)
                    break;
            c+=j-i;
            t=length[j];
            length.erase(length.begin()+j);
            length.insert(length.begin(),t);
        }
        printf("Case #%d: %d\n",ti+1,c);
    }
    return 0;
}
