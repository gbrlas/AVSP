#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
const int maxsize =110;
const int inf = 0x7fffffff;
template<class T>
void show(T a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

char cs[maxsize][10];
char ds[maxsize][10];
char ns[maxsize];
char ans[maxsize];
int solve(int c,int d){
	int t=0;
	char in[300];
	clr(in);
	for(int i=0;ns[i];i++){
		char ch=ns[i];
		ans[t++]=ch;
		in[ch]++;
		if(t>1){
			char pre=ans[t-2];
			bool goon=true;
			for(int j=0;j<c&&goon;j++){
				if((ch==cs[j][0]&&pre==cs[j][1])||(ch==cs[j][1]&&pre==cs[j][0])){
					in[ch]--; in[pre]--;
					t--; t--;
					ans[t++]=cs[j][2];
					goon=false;
				}
			}
			for(int j=0;j<d&&goon;j++){
				if((ch==ds[j][0]&&in[ds[j][1]])||(ch==ds[j][1]&&in[ds[j][0]])){
					clr(in); t=0;
					goon=false;
				}
			}
		}
	}
	return t;
}






int main(int argc, char *argv[])
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int haha=1;haha<=t;haha++){
		printf("Case #%d: ",haha);
		int c,d,n;
		scanf("%d",&c);
		for(int i=0;i<c;i++){
			scanf("%s",cs[i]);
		}
		scanf("%d",&d);
		for(int i=0;i<d;i++){
			scanf("%s",ds[i]);
		}
		scanf("%d",&n);
		scanf("%s",ns);
		int cnt=solve(c,d);
		printf("[");
		if(cnt){
			cnt--;
			for(int i=0;i<cnt;i++){
				putchar(ans[i]);
				putchar(',');
				putchar(' ');
			}
			putchar(ans[cnt]);
		}
		printf("]\n");
	}
	
   
    //system("PAUSE");
    return 0;
}

