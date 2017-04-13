#include <cstdio>
#include <cstdlib>
using namespace std;
int N,T,a,b,A[16],B[16];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&a);for(int i=0;i<16;i++)scanf("%d",&A[i]);
		scanf("%d",&b);for(int i=0;i<16;i++)scanf("%d",&B[i]);
		a=(a-1)*4;
		b=(b-1)*4;bool f1=0,f2=0;int tt=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				if(A[a+i]==B[b+j]){
					if(f1){f2=1;break;}
					f1=1;
					tt=A[a+i];
				}
			if(f2)break;
		}
		printf("Case #%d: ",t);
		if(f2)printf("Bad magician!\n");
		else if(!f1)printf("Volunteer cheated!\n");
		else printf("%d\n",tt);
	}
	//system("pause");
}
