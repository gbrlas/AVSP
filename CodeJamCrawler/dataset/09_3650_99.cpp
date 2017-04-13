#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int kind = 26;
const int N = 200000;
int num;
struct Node{
	int next[kind];
	int count;
}Tree[N];
vector<char>r[30];
bool flag[30];
void insert(char *str,int root)
{
	int p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-'a';
		flag[index] = 1;
		if(Tree[p].next[index]==0){
			memset(Tree[num].next,0,sizeof(Tree[num].next));
			Tree[num].count = 0;
			Tree[p].next[index] = num++;
			
		}
		p = Tree[p].next[index];
		i++;
	}
	Tree[p].count = 1;
}
int n,cnt;
void dfs(int root,int depth)
{
	if(depth==n){
		if(Tree[root].count==1) cnt++;
		return;
	}
	for(int i=0;i<r[depth].size();i++)
	{
		if(Tree[root].next[r[depth][i]-'a']){
		//	printf(" %c",r[depth][i]);
			dfs(Tree[root].next[r[depth][i]-'a'],depth+1);
		}
	}
}
char str[200000];
int main()
{
	int m,k,root,i,j,ca,T;
	char word[200];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&n,&m,&T)!=EOF)
	{
		memset(Tree,0,sizeof(Tree));
		memset(flag,0,sizeof(flag));
		root = 1;num = 1;
		for(i=0;i<m;i++)
		{
			scanf("%s",word);
			insert(word,root);
		}
	//	for(i=0;i<26;i++) printf("%d ",flag[i]);
		for(ca=0;ca<T;ca++)
		{
			scanf("%s",str);
			for(i=0;i<n;i++) r[i].clear();
			j = 0;k=0;
			while(str[j]!='\0'){

				if(str[j]=='('){
					j++;
					while(str[j]!=')' && str[j]!='\0'){
						if(flag[str[j]-'a']) r[k].push_back(str[j]);
						j++;
					}
					k++;
					if(str[j]=='\0') break;
					j++;
				}
				else{
					r[k].push_back(str[j]);
					k++;
					j++;
				}
			}

			cnt = 0;
			dfs(1,0);
			printf("Case #%d: %d\n",ca+1,cnt);
		}
	}
	return 0;
}