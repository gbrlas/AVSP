#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("input.inp","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int m,n,a[5][5],b[5][5],d[17],test;
	cin>>test;
	for (int t=1;t<=test;t++){
        cin>>m;
        for (int i=1;i<=4;i++){
            for (int j=1;j<4;j++){
                scanf("%d",&a[i][j]);
            }
            scanf("%d\n",&a[i][4]);
        }
        cin>>n;
        for (int i=1;i<=4;i++){
            for (int j=1;j<4;j++){
                scanf("%d",&b[i][j]);
            }
            scanf("%d\n",&b[i][4]);
        }
        for (int j=1;j<=16;j++){
            d[j]=0;
        }
        for (int j=1;j<=4;j++){
            d[a[m][j]]++;
        }
        int res=0;
        for (int j=1;j<=4;j++){
            res+=d[b[n][j]];
        }
        cout<<"Case #"<<t<<": ";
        if (res==1){
            for (int j=1;j<=4;j++){
                if (d[b[n][j]])
                    cout<<b[n][j]<<"\n";
            }
        }
        else
        if (res==0){
            cout<<"Volunteer cheated!\n";
        }
        else
            cout<<"Bad magician!\n";
	}
	return 0;
}
