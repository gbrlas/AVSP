#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nbe_s nbe_t;
typedef struct conflict_s conflict_t;

struct nbe_s {
	char a, b; /* elements a + b = c */
	char c;
	
	nbe_t *next;
};

struct conflict_s {
	char a, b;
	
	conflict_t *next;
};
	

int main(int argc, char *argv[]) {
	FILE *in, *out;
	int lines;
	int n;
	nbe_t *nbelist;
	conflict_t *conflictlist;
	
	if(argc != 3) {
		return(1);
	}
	
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w+");
	
	if(!in || !out) {
		return(1);
	}
	
	fscanf(in, "%d", &lines);
	for(n = 0; n < lines; n++) {
		int strings, m, i;
		char list[255];
		
		fscanf(in, "%d", &strings);
		nbelist = NULL;
		memset(list, 0, sizeof(list));
	
		for(m = 0; m < strings; m++) {
			char a, b, c;
			nbe_t *nbe;
			
			fscanf(in, " %c%c%c", &a, &b, &c);
			nbe = malloc(sizeof(nbe_t));
			nbe->a = toupper(a);
			nbe->b = toupper(b);
			nbe->c = toupper(c);
			nbe->next = NULL;
			
			if(!nbelist) {
				nbelist = nbe;
			} else {
				nbe_t *p = nbelist;
				
				while(p->next) {
					p = p->next;
				}
				p->next = nbe;
			}
		}
		fscanf(in, " %d", &strings);
		conflictlist = NULL;
		
		for(m = 0; m < strings; m++) {
			char a, b;
			conflict_t *conf;
			
			fscanf(in, " %c%c", &a, &b);
			conf = malloc(sizeof(conflict_t));
			conf->a = toupper(a);
			conf->b = toupper(b);
			conf->next = NULL;
			
			if(!conflictlist) {
				conflictlist = conf;
			} else {
				conflict_t *p = conflictlist;
				
				while(p->next) {
					p = p->next;
				}
				p->next = conf;
			}
		}
		
		fscanf(in, " %d ", &strings);
		i = -1;
		for(m = 0; m < strings; m++) {
			char c;
			
			fscanf(in, "%c", &c);
			c = toupper(c);
			
			if(i == -1) {
				list[++i] = c;
			} else {
				nbe_t *p = nbelist;
				conflict_t *q = conflictlist;
				int j;
				int append = 1;
				
				/* check combos */
				while(p) {
					if((p->a == c && p->b == list[i]) || (p->b == c && p->a == list[i])) {
						list[i] = p->c;
						append = 0;
						break;
					}
					p = p->next;
				}
				if(append) {
					while(q) {
						for(j = 0; j <= i; j++) {
							if((q->a == c && q->b == list[j]) || (q->b == c && q->a == list[j])) {
								memset(list, 0, sizeof(list));
								i = -1;
								append = 0;
								break;
							}
						}
						q = q->next;
					}
				}
				if(append) { /* we've seen the end of the list */
					list[++i] = c;
				}
			}
		}
		fprintf(out, "Case #%d: [", n+1);
		for(m = 0; m < strlen(list); m++) {
			fprintf(out, "%c", list[m]);
			if(m+1 < strlen(list)) {
				fprintf(out, ", ");
			}
		}
		fprintf(out, "]\n");
		while(nbelist) {
			nbe_t *ptr = nbelist;
			
			nbelist = nbelist->next;
			free(ptr);
		}
		while(conflictlist) {
			conflict_t *ptr = conflictlist;
			
			conflictlist = conflictlist->next;
			free(ptr);
		}	
	}
	fclose(in);
	fclose(out);
	return(0);
}
