#include<iostream>
#include<string>
#include<map>
using namespace std;
int t,n,s,q;
map<string, bool> visited;
int main() {
	
	freopen("A-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("outputLarge.txt","w",stdout);
	scanf("%d",&t);
	for(int i=0; i<t; i++) {
		visited.clear();		
		scanf("%d",&s);
		getchar();
		for(int j=0; j<s; j++) {
			string str;			
			getline(cin,str);
		}
		scanf("%d",&q);
		getchar();

		int l=0;
		int answer = 0;
		for(int j=0; j<q; j++) {
			string str;
			getline(cin, str);
			if (!visited[str]) {
				visited[str] = true;
				l++;
			}
			if (l == s) {
				l=1;				
				visited.clear();
				visited[str]=true;
				answer++;				
			}			
		}
		printf("Case #%d: %d\n",i+1,answer);
	}	
}