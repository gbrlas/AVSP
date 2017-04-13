#include <stdio.h>
int main(){
    freopen("input","rt",stdin);
    freopen("out","wt",stdout);

    int cases;
    int notes[10000];
    scanf("%d",&cases);

    for(int iCase=0;iCase<cases;++iCase){
        int n,l,h;
        scanf("%d %d %d",&n,&l,&h);


        for(int i=0;i<n;i++)
            scanf("%d",notes+i);

        int i=l;
        for(;i<=h;i++){
            int j=0;
            for(;j<n;j++){
                if(!(i%notes[j] == 0 || notes[j]%i == 0))
                    break;
            }
            if(j == n){
                printf("Case #%d: %d\n",iCase+1,i);
                break;
            }
        }
        if(i>h)
            printf("Case #%d: NO\n",iCase+1);

    }
    return 0;
}
