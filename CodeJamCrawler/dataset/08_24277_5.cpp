#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <strstream>

using namespace std;

#define MAX_LINE_LEN 1024
//#define USE_STDOUT

#ifdef USE_STDOUT
#include <stdlib.h>
#endif

static bool readline (FILE *in, char *line, int maxlen)
{
	char c, pos;
	if (!in || !line || maxlen <= 1 || feof (in))
		return false;

	pos = 0;
	while (c = fgetc (in), !feof (in) && pos < maxlen - 1) {
		if (c == 0x0a)
			break;
		if (c != 0x0d) {
			line [pos] = c;
			pos ++;
		}
	}

	line [pos] = 0;
	return pos < maxlen;
}

static bool readint (FILE *in, int &num)
{
	char line [MAX_LINE_LEN + 1];
	if (!in) return false;

	if (!readline (in, line, MAX_LINE_LEN)) {
		return false;
	}

	return 1 == sscanf (line, "%d", &num);
}

class MNode
{
public:
	MNode *left, *right;
	bool is_and, value;

	MNode (){
		left=NULL;
		right=NULL;
		value=false;
		is_and=false;
	}
	~MNode(){
		if(left) delete left;
		if(right) delete right;
	}
};

static bool eval(MNode *n)
{
	if (n->left&&n->right){
		bool a, b;
		a=eval(n->left);
		b=eval(n->right);
		if(n->is_and) return a&&b;
		else return a||b;
	}else return n->value;
}

static bool calc(MNode *root, bool lookfor)
{
	return eval(root)==lookfor;
}

static void solve (FILE *in, FILE *out)
{
	int tests, test;
	char line [MAX_LINE_LEN + 1];

	if (!readline (in, line, MAX_LINE_LEN)) {
		return;
	}

	if (sscanf (line, "%d", &tests) != 1) {
		return;
	}

	for (test = 1; test <= tests; test++) {
		int M,V, i;
		MNode *root;
		vector<MNode *> changeables, nodes;

		readline (in, line, MAX_LINE_LEN);
		sscanf (line, "%d %d", &M, &V);

		root=NULL;
		for (i = 0; i < M; i++){
			int G,C;

			readline (in, line, MAX_LINE_LEN);

			if (i==0){
				sscanf(line, "%d %d", &G, &C);
				root = new MNode();
				root->is_and = G==1;
				if (C) changeables.push_back (root);
				nodes.push_back (root);
			}else if (i < (M-1)/2){
				MNode *n;

				sscanf(line, "%d %d", &G, &C);
				n = new MNode();
				n->is_and = G==1;
				if(C) changeables.push_back(n);
				nodes.push_back(n);
			}else{
				MNode *n;
				
				sscanf(line, "%d", &G);
				n=new MNode ();
				n->value=G!=0;
				nodes.push_back(n);
			}
		}

		int sz=nodes.size();
		for (i=1;i<=M;i++){
			int idx=2*i+1;
			if(idx-1>=sz) break;
			MNode *n=nodes[i-1];
			n->left=nodes[idx-2];
			n->right=nodes[idx-1];
		}

		int res=-1;

		if (calc(root,V!=0)){
			res=0;
		}else{
			sz=1<<(changeables.size());
			for (int v=1; v<sz;v++){
				int changed=0;
				int e,idx;
				for(e=1,idx=0;e<=v;e*=2,idx++){
					if ((v&e)!=0&&changeables.size()>idx){
						MNode *n=changeables[idx];
						n->is_and=!n->is_and;
						changed++;
					}
				}

				if(calc(root,V!=0)){
					if(res==-1||res>changed) res=changed;
				}

				for(e=1,idx=0;e<=v;e*=2,idx++){
					if ((v&e)!=0&&changeables.size()>idx){
						MNode *n=changeables[idx];
						n->is_and=!n->is_and;
					}
				}
			}
		}

		fprintf (out, "Case #%d: ", test);
		if(res==-1){
			fprintf(out,"IMPOSSIBLE");
		}else{
			fprintf(out,"%d",res);
		}
		fprintf (out, "\n");

		if (root) delete root;
	}
}

int main (void)
{
	FILE *out;
	FILE *in = fopen ("data.in", "rb");

	#ifdef USE_STDOUT
		out = stdout;
	#else
		out = fopen ("data.out", "wt");
	#endif

	if (!in) {
		fprintf (stderr, "No input file!\n");
		#ifndef USE_STDOUT
			if (out)
				fclose (out);
		#endif
		return 1;
	}

	if (!out) {
		fprintf (stderr, "Cannot open output file!\n");
		fclose (in);
		return 2;
	}

	solve (in, out);

	fclose (in);
	#ifdef USE_STDOUT
		system ("pause");
	#else
		fclose (out);
	#endif
	return 0;
}
