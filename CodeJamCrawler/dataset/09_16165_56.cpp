#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
	double w;
	char f[11];
	Node *a,*b,*pre;
	
	Node() {
		a = b = pre = NULL;
	}
};

struct Animal {
	int n;
	char f[100][11];
};

double Pro(Animal al, Node *now, double p) {
	int i;
	
//	printf("[%f %s %.f]\n", now->w, now->f, p);
	if(now->a == NULL) 
		return p * now->w;
	for(i=0; i<al.n; i++)
		if(strcmp(al.f[i], now->f) == 0)
			break;
	if(i < al.n)
		return Pro(al, now->a, p*now->w);
	else
		return Pro(al, now->b, p*now->w);
}

void Clear(Node *now) {
	if(now != NULL) {
		Clear(now->a);
		Clear(now->b);
		now->a = NULL;
		now->b = NULL;
		if(now->pre != NULL)
			delete now;
	}
}
		

int main() {
	int N,L,A,i,j,ptr,cas=1,n,sub;
	char in[100],*x;
	Node root,*now,*tmp;
	Animal al;
		
	freopen("testA.in", "r", stdin);
	freopen("testA.out", "w", stdout);
	scanf("%d", &N);
	while(1) {
		scanf("%d", &L);
		getchar();
		root.pre = NULL;		
		sub = 0;
		for(i=0; i<L; i++) {
			gets(in);
			ptr = 0;
			while(1) {
				if(in[ptr] == ' ') {
					ptr++;
					continue;
				}
				if(in[ptr] == '\0')
					break;
				if(in[ptr] == '(') {
					if(sub == 0) {
						now = &root;
						sub = 1;
					}
					else {
						if(now->a == NULL) {
							tmp = now;
							now->a = new Node;
							now = now->a;
							now->pre = tmp;
						}
						else {
							tmp = now;
							now->b = new Node;
							now = now->b;
							now->pre = tmp;
						}
					}
					ptr++;
				}
				if(isdigit(in[ptr]) != 0) {
					sscanf(&in[ptr], "%lf", &now->w);
					while(isdigit(in[ptr]) != 0 || in[ptr] == '.')
						ptr++;
				}
				if(islower(in[ptr]) != 0) {
					sscanf(&in[ptr], "%s", now->f);
					while(islower(in[ptr]) != 0)
						ptr++;
				}
				if(in[ptr] == ')') {
					if(now->pre == NULL)
						break;
					now = now->pre;
					ptr++;
				}
			}
		}
		printf("Case #%d:\n", cas);
//		system("PAUSE");
		scanf("%d", &A);
		getchar();
		for(i=0; i<A; i++) {
			gets(in);
			x = strtok(in, " ");
			x = strtok(NULL, " ");
			sscanf(x, "%d", &al.n);
			for(j=0; j<al.n; j++) {
				x = strtok(NULL, " ");
				sscanf(x, "%s", &al.f[j]);
			}
			printf("%.7f\n", Pro(al, &root, 1.0));
		}
		Clear(&root);
		if(cas == N)
			break;
		cas++;
	}
	return 0;
}
