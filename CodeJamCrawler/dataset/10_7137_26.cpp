#define _CRT_SECURE_NO_WARNINGS
#define _NCDEBUG

#include <stdio.h>
#include <string.h>

#define IF "A-small-attempt3.in"
#define OF "A-small-attempt3.out"

#if defined(_NCDEBUG)
#define DbgPrint(...)	fprintf(stderr, __VA_ARGS__)
#else
#define DbgPrint(...)
#endif

static FILE *fpin;
static FILE *fpout;

#define cscanf(...)   fscanf(fpin, __VA_ARGS__)
#define cprintf(...)	fprintf(fpout, __VA_ARGS__)


static void prepare(void)
{
	fpout = fopen(OF, "w+t");
	if (!fpout) {
		perror("fopen/out");

		DbgPrint("Failed to open a file %s\n", OF);
		return;
	}

	fpin = fopen(IF, "rt");
	if (!fpin) {
		perror("fopen/in");

		DbgPrint("Failed to open a file %s\n", IF);
		fclose(fpout);
		return;
	}
}


static void complete(void)
{
	fclose(fpin);
	fclose(fpout);
}



int main(int argc, char *argv[])
{	
	int nr_of_tc;
	register int i;
	int N, M;
	char d[101][101];
	int j;
	int k;
	int max_len;
	int len;
	int idx;
	int created = 0;
	char tmp[101];

	prepare();
	cscanf("%d", &nr_of_tc);

	DbgPrint("TC: %d\n", nr_of_tc);

	for (i = 0; i < nr_of_tc; i ++) {
		cscanf("%d %d", &N, &M);
		DbgPrint("%d %d\n", N, M);

		for (j = 0; j < N; j ++) {
			cscanf("%s", d[j]);	
		}

		created = 0;

		for (k = 0; k < M; k ++) {
			cscanf("%s", tmp);
			j = 1;
			do {
				if (tmp[j] == '/') {
					strncpy(d[N], tmp, j);
					d[N][j] = '\0';
					
					for (idx = 0; idx < N; idx ++) {
						if (!strcmp(d[N], d[idx])) break;
					}

					if (idx == N) {
						created ++;
						DbgPrint("[%d] %s create\n", created, d[N]);
						N ++;
					}
				}
				j ++;
			} while (tmp[j] != '\0');

			if (tmp[j] == '\0') {
				for (idx = 0; idx < N; idx ++) {
					if (!strcmp(d[idx], tmp)) break;
				}

				if (idx == N) {
						strcpy(d[N], tmp);
						created ++;
						DbgPrint("[%d] %s created\n", created, d[N]);
						N ++;
				}
			}
		}

		DbgPrint("Case #%d: %d\n", i + 1, created);
		cprintf("Case #%d: %d\n", i+1, created);

	}

	complete();
	return 0;
}



// End of a file