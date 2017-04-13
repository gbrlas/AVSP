#include <stdio.h>
#include <string.h>

static char fi[256];
static char fo[256];
static const char map[] = {
	'y', 'h', 'e', 's', 'o', 
	'c', 'v', 'x', 'd', 'u', 
	'i', 'g', 'l', 'b', 'k', 
	'r', 'z', 't', 'n', 'w', 
	'j', 'p', 'f', 'm', 'a', 'q'};

static int N;
static char buf[128];

void solve() {	
	FILE *f = fopen(fi, "r");
	FILE *g = fopen(fo, "w");
	fscanf(f, "%d\n", &N);
	int i;
	for (i = 0; i < N; ++i) {
		fgets(buf, 128, f);
		char *c = buf;
		while (*c != '\n' && *c != '\0') {
			if (*c != ' ')
				*c = map[*c - 'a'];
			c++;
		}
		*c = '\0'; 
		fprintf(g, "Case #%d: ", i+1);
		fputs(buf, g);
		fprintf(g, "\n");
	}
	fclose(f);
	fclose(g);
}

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Please give input and output file name.\n");
		return 1;
	}
	strcpy(fi, argv[1]);
	strcpy(fo, argv[2]);
	solve();
	return 0;
}