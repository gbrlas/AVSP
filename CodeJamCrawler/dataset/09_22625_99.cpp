#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int ans = 0;

struct node {
	char *data;
	node *branch[26];
	bool reached;
	int lvl;
};

node *new_node(int level) {
	node *temp = (node*)malloc(sizeof(node));
	temp->data = NULL;
	temp->reached = false;
	temp->lvl = level;
	for (int i=0;i<26;i++)
		temp->branch[i] = NULL;
}

void add(node *cnode, char *s, char *data) {
	if (!*s) cnode->data = data;
	else {
		int idx = *s - 'a';
		if (!cnode->branch[idx])
			cnode->branch[idx] = new_node(cnode->lvl+1);
		add(cnode->branch[idx], s+1, data);
	}
	return;
}

char * get(node *cnode, char *s) {
	if (!cnode) return NULL;
	if (!*s) return cnode->data;
	return get(cnode->branch[*s - 'a'], s+1);
}

void update(node *cnode){
	if (!cnode) return;
	cnode->reached = false;
	for (int i=0;i<26;i++)
		update(cnode->branch[i]);
	return;
}

void visit(node *cnode, char ch, int idx, int level) {
	if (!cnode) return;
	if(cnode->reached && cnode->lvl < level) {
		for(int i=0;i<26;i++) {
			visit(cnode->branch[i], ch, i, level);
		}
	} else if(!cnode->reached && ch-'a' == idx && cnode->lvl == level) {
		cnode->reached = true;
	}
}

void count(node *cnode, int level) {
	if (!cnode) return;
	if(cnode->reached && cnode->lvl < level) {
		for(int i=0;i<26;i++) {
			count(cnode->branch[i], level);
		}
	} else if(cnode->reached && cnode->lvl == level) {
		ans++;
	}
	return;
}

int main() {
	int L,D,N;
	scanf("%d %d %d",&L,&D,&N);
	node *root = new_node(0);
	char str[20], inp[500];
	for(int i=0;i<D;i++) {
		scanf(" %[^\n]",str);
		add(root, str, str);
	}
	for(int i=0;i<N;i++) {
		printf("Case #%d: ",i+1);
		ans=0;
		scanf(" %[^\n]",inp);
		int len = strlen(inp);
		update(root);
		root->reached = true;
		int cnt=0;
		for(int j=0;j<len;j++) {
			if(inp[j] == '(') {
				j++;
				cnt++;
				while(inp[j] != ')') {
					visit(root, inp[j], -1, cnt);
					j++;
				}
			} else {
				cnt++;
				visit(root,inp[j],-1,cnt);
			}
		}
		count(root,L);
		printf("%d\n",ans);
	}
	return 0;
}
