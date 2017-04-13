#include<iostream>
#include<string>
#include<map>
using namespace std;

string name[110];
map<string,int> mm;
char ss[120];
string a;

int main()
{
	int n,m,T,i,j,P = 1;
	scanf("%d",&T);
	while(T--){

		scanf("%d",&n);
		getchar();
		for(i =1; i <= n; i ++){
			gets(ss);
			name[i] = ss;
		}

		scanf("%d",&m);
		getchar();

		int nnum = 0;
		int cc = 0;

		for(i =0; i < m ; i ++){
			gets(ss);
			a = ss;
			if(mm[a] == 0){
				mm[a] ++;
				cc ++;
			}

			if(cc == n){
				cc = 1;
				nnum ++;
				mm.clear();
				mm[a] ++;
			}
		}
		printf("Case #%d: %d\n",P++,nnum);

		mm.clear();
	}
	return 0;
}
