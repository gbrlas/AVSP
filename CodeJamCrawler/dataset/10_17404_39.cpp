#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int m,n;
char path[256];
char * pch;
__int64 ans=0;
struct Node{
	char name[256];
	vector<Node*> children;
	Node(){
		strcpy(name,"");
	}
};
Node *root;
void rebuildtree(Node * root){
	int len=root->children.size();
	for (int i=0;i<len;i++)
		if (strcmp(pch,root->children[i]->name)==0){
			pch=strtok(NULL,"/");
			if (pch!=NULL) rebuildtree(root->children[i]);
			return ;
		}
		Node *tmp= new Node();
		ans++;
		strcpy(tmp->name,pch);
		root->children.push_back(tmp);
		pch=strtok(NULL,"/");
		if (pch!=NULL) rebuildtree(tmp);
}
void buildtree(Node * root){
	int len=root->children.size();
	for (int i=0;i<len;i++)
		if (strcmp(pch,root->children[i]->name)==0){
			pch=strtok(NULL,"/");
			if (pch!=NULL) buildtree(root->children[i]);
			return ;
		}
	Node *tmp= new Node();
	strcpy(tmp->name,pch);
	root->children.push_back(tmp);
	pch=strtok(NULL,"/");
	if (pch!=NULL) buildtree(tmp);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	root= new Node();
	/*root->name="root";*/
	int tc;
	scanf("%d",&tc);
	for (int ii=1;ii<=tc;ii++){
		root->children.clear();
		printf("Case #%d: ",ii);
		scanf("%d%d\n",&n,&m);
		for (int i=0;i<n;i++){
			cin.getline(path,256);
			pch = strtok (path,"/");
			if (pch!=NULL) buildtree(root);
		}
		ans=0;
		for (int i=0;i<m;i++){
			cin.getline(path,256);
			pch = strtok (path,"/");
			if (pch!=NULL) rebuildtree(root);
		}
		printf("%I64d\n",ans);
		//end case
	}
	return 0;
}