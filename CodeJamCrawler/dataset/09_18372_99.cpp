// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>

using namespace std;

class Entry {
public:
	Entry() {
		for (int i = 0; i < 26; i++) {
			b[i] = false;
			link[i] = NULL;
		}
	}
	~Entry() {
		for (int i = 0; i < 26; i++) {
			if (link[i] != NULL) {
				delete link[i];
			}
		}
	}
	bool b[26];
	Entry* link[26];
};

void construct(Entry* root, char* s, int len) {
	int i;
	Entry *cur = root;		
	for (i = 0; i < len; i++) {
		int index = s[i] - 'a';
		cur->b[index] = true;
		if (i != len - 1 && cur->link[index] == NULL) {
			cur->link[index] = new Entry();
		}
		cur = cur->link[index];     
	}
}

int findinnode(Entry* root, string* slist, int start, int len) {
	if (root == NULL) {
		return 1;
	}
    int num = 0;
	int j;
	string s = slist[start];
	for (j = 0; j < s.length(); j++) {
		int index = s[j] - 'a';
		if (root->b[index]) {
			num += findinnode(root->link[index], slist, start+1, len);
		}
	}
	return num;
}

int findintree(Entry* root, string s, int len) {
	int i, j;
	string slist[20];
	for (i = j = 0; i < len; i++) {
		if (s[j] == '(') {
			int end = s.find(')', j);
            slist[i] = s.substr(j + 1, end - j - 1);
			j = end + 1;
		} else {
			slist[i] = s.substr(j, 1);
			j++;
		}
	}	
	int num = findinnode(root, slist, 0, len);
	return num;
}

int main()
{
    FILE* in = fopen("A-small-attempt0.in", "r");
	FILE* out = fopen("out.txt", "w");
	int L, D, N;
	int i;
	fscanf(in, "%d %d %d", &L, &D, &N);
	Entry* root = new Entry();
	char tmp[20];
	for (i = 0; i < D; i++) {
		fscanf(in, "%s", tmp);
		construct(root, tmp, L);
	}
	char testcase[1000];
	for (i = 0; i < N; i++) {
		fscanf(in, "%s", testcase);
		int num = findintree(root, string(testcase), L);
		fprintf(out, "Case #%d: %d\n", i+1, num);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
